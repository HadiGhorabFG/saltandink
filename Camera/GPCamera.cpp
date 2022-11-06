#include "GPCamera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"

AGPCamera::AGPCamera()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	
	RootComponent = SceneComponent;

	SpringArm->SetupAttachment(SceneComponent);
	Camera->SetupAttachment(SpringArm);
}

void AGPCamera::SetupPlayerInputComponent(UInputComponent* inputComponent)
{
	Super::SetupPlayerInputComponent(inputComponent);
	inputComponent->BindAxis("MouseWheelAxis", this, &AGPCamera::ScrollZoomInput);
	inputComponent->BindAxis("CameraRotateAxis", this, &AGPCamera::RotationInput);
	inputComponent->BindAxis("CameraHorizontalAxis", this, &AGPCamera::HorizontalInput);
	inputComponent->BindAxis("CameraVerticalAxis", this, &AGPCamera::VerticalInput);
}

void AGPCamera::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetFirstPlayerController()->SetViewTargetWithBlend(this);

	SpringArm->TargetArmLength = ZoomMax;
	nextSpringArmLength = ZoomMax; // set default to current start length

	nextRotationYaw = GetActorRotation().Yaw;
	currentRotationYaw = GetActorRotation().Yaw;
}

void AGPCamera::Tick(float DeltaSeconds)
{
	//move speed based on zoom
	zoomModifier = UKismetMathLibrary::NormalizeToRange(SpringArm->TargetArmLength, ZoomMin, ZoomMax);
	zoomModifier = UKismetMathLibrary::FClamp(zoomModifier, minEdgeSpeedPercentage, 1.f);
	
	if(bEnableEdgePanning)
		EdgePanning(DeltaSeconds);

	Move(DeltaSeconds);

	//constrain movement
	FVector clampedLocation = GetActorLocation();
	clampedLocation.X = UKismetMathLibrary::FClamp(clampedLocation.X, MinXThreshold, MaxXThreshold);
	clampedLocation.Y = UKismetMathLibrary::FClamp(clampedLocation.Y, MinYThreshold, MaxYThreshold);
	SetActorLocation(clampedLocation);

	Zoom(DeltaSeconds);
	Rotation(DeltaSeconds);
}

void AGPCamera::EdgePanning(float deltaSeconds)
{
	if(GEngine->GameViewport != 0)
		GEngine->GameViewport.Get()->GetMousePosition(mousePos);

	GEngine->GameViewport.Get()->GetViewportSize(viewportSize);

	//returns a normalize 0 - 1 inside a certain range of the screen (edge)
	double leftEdgeRange = UKismetMathLibrary::NormalizeToRange(mousePos.X, 0.f, viewportSize.X * EdgeRangePercentage);
	leftEdgeRange = UKismetMathLibrary::FClamp(leftEdgeRange, 0, 1);
	
	double rightEdgeRange = UKismetMathLibrary::NormalizeToRange(mousePos.X, viewportSize.X *
		(1 - EdgeRangePercentage), viewportSize.X);
	rightEdgeRange = UKismetMathLibrary::FClamp(rightEdgeRange, 0, 1);

//	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Yellow, FString::Printf(TEXT("Pos: %f"), rightEdgeRange));

	double upEdgeRange = UKismetMathLibrary::NormalizeToRange(mousePos.Y, 0.f, viewportSize.Y * EdgeRangePercentage);
	upEdgeRange = UKismetMathLibrary::FClamp(upEdgeRange, 0, 1);

	double downEdgeRange = UKismetMathLibrary::NormalizeToRange(mousePos.Y, viewportSize.Y *
		(1 - EdgeRangePercentage), viewportSize.Y);
	downEdgeRange = UKismetMathLibrary::FClamp(downEdgeRange, 0, 1);
	
	// -1 cuz we are going to the left/up
	moveVector.X = mousePos.X <= viewportSize.X * 0.5f ? (leftEdgeRange - 1.f) : rightEdgeRange;
	moveVector.Y = mousePos.Y <= viewportSize.Y * 0.5f ? (upEdgeRange - 1.f) : downEdgeRange;
	
	SceneComponent->AddLocalOffset(moveVector * deltaSeconds * EdgeScrollSpeed * zoomModifier);
}

void AGPCamera::Zoom(float deltaSeconds)
{
	SpringArm->TargetArmLength = UKismetMathLibrary::Lerp(currentSpringArmLength, nextSpringArmLength, deltaSeconds * ZoomSpeed);
	SpringArm->TargetArmLength = UKismetMathLibrary::FClamp(SpringArm->TargetArmLength, ZoomMin, ZoomMax);
}

void AGPCamera::ScrollZoomInput(float axisValue)
{
	currentSpringArmLength = SpringArm->TargetArmLength;

	if(axisValue > 0 && currentSpringArmLength > ZoomMin)
	{
		nextSpringArmLength = currentSpringArmLength - ZoomStrength;
	}
	else if(axisValue < 0 && currentSpringArmLength < ZoomMax)
	{
		nextSpringArmLength = currentSpringArmLength + ZoomStrength;
	}
}

void AGPCamera::Rotation(float deltaSeconds)
{
	currentRotationYaw = UKismetMathLibrary::Lerp(currentRotationYaw, nextRotationYaw, deltaSeconds * RotationSpeed);
	
	newRotation = FRotator(
		GetActorRotation().Roll,
		currentRotationYaw,
		GetActorRotation().Pitch
	);
	
	SetActorRotation(newRotation);
}

void AGPCamera::RotationInput(float axisValue)
{
	if(axisValue != 0)
	{
		newRotationYaw = RotationStrength * axisValue;
		nextRotationYaw = currentRotationYaw + newRotationYaw; 
	}
}

void AGPCamera::Move(float deltaSeconds)
{
	horizontalStrength = UKismetMathLibrary::Lerp(horizontalStrength, horizontalLerpTo, deltaSeconds * MoveSpeed);
	verticalStrength = UKismetMathLibrary::Lerp(verticalStrength, verticalLerpTo, deltaSeconds * MoveSpeed);
	newLocation.X = horizontalStrength * zoomModifier;
	newLocation.Y = verticalStrength * zoomModifier;

	SceneComponent->AddLocalOffset(newLocation * deltaSeconds);
}

void AGPCamera::HorizontalInput(float axisValue)
{
	if(axisValue != 0)
	{
		horizontalStrength = axisValue * MoveStrength;
		horizontalLerpTo = horizontalStrength;
	}
	else
	{
		horizontalLerpTo = 0;;
	}
}

void AGPCamera::VerticalInput(float axisValue)
{
	if(axisValue != 0)
	{
		verticalStrength = axisValue * MoveStrength;
		verticalLerpTo = verticalStrength;
	}
	else
	{
		verticalLerpTo = 0;;
	}
}
