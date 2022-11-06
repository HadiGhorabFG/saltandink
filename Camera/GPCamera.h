#pragma once
#include "GPCamera.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class AGPCamera : public APawn
{
    GENERATED_BODY()
    
public:
    AGPCamera();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    void EdgePanning(float deltaSeconds);
    void Zoom(float deltaSeconds);
    void Rotation(float deltaSeconds);
    void Move(float deltaSeconds);

    virtual void SetupPlayerInputComponent(UInputComponent* inputComponent) override;
    void ScrollZoomInput(float axisValue);
    void RotationInput(float axisValue);
    void HorizontalInput(float axisValue);
    void VerticalInput(float axisValue);
    
    UPROPERTY(VisibleAnywhere)
    USceneComponent* SceneComponent;
    UPROPERTY(VisibleAnywhere)
    UCameraComponent* Camera;
    UPROPERTY(VisibleAnywhere)
    USpringArmComponent* SpringArm;
    
    UPROPERTY(EditAnywhere, Category="Camera Settings|Edge Panning")
    bool bEnableEdgePanning = true;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Edge Panning")
    float EdgeScrollSpeed = 1000.f;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Edge Panning")
    float EdgeRangePercentage = 0.05f;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Edge Panning")
    float minEdgeSpeedPercentage = 0.2f;

    UPROPERTY(EditAnywhere, Category="Camera Settings|Zoom")
    float ZoomStrength = 500.f;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Zoom")
    float ZoomSpeed = 4.f;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Zoom")
    float ZoomMin = 1000.f;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Zoom")
    float ZoomMax = 2500.f;

    UPROPERTY(EditAnywhere, Category="Camera Settings|Rotation")
    float RotationStrength = 20.f;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Rotation")
    float RotationSpeed = 6.f;

    UPROPERTY(EditAnywhere, Category="Camera Settings|Movement")
    float MoveStrength = 2000.f;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Movement")
    float MoveSpeed = 6.f;

    UPROPERTY(EditAnywhere, Category="Camera Settings|Movement")
    float MinYThreshold = -500.f;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Movement")
    float MaxYThreshold = 500.f;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Movement")
    float MinXThreshold = -500.f;
    UPROPERTY(EditAnywhere, Category="Camera Settings|Movement")
    float MaxXThreshold = 500.f;
    
private:
    FVector2D mousePos;
    FVector2D viewportSize;

    FVector moveVector;

    float currentSpringArmLength;
    float nextSpringArmLength;
    float zoomModifier;

    float newRotationYaw;
    float currentRotationYaw;
    float nextRotationYaw;
    FRotator newRotation;

    float horizontalStrength;
    float horizontalLerpTo;
    float verticalStrength;
    float verticalLerpTo;
    FVector currentLocation;
    FVector nextLocation;
    FVector newLocation;
};