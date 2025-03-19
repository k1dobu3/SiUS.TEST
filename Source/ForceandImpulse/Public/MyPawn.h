// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyPawn.generated.h"

UCLASS()
class FORCEANDIMPULSE_API AMyPawn : public APawn
{
	GENERATED_BODY()


public:
	// Sets default values for this pawn's properties
	AMyPawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PARAMETERS)
	UStaticMeshComponent* BaseMesh;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;



	float MovementForce = 1000000;
	UStaticMesh* asset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveLeft(float Value);
	void Movecamera2(float Value);
	void Movecamera1(float Value);

	// Input variables
	FVector CurrentVelocity;
};
