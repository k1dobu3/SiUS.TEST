// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "KirIGR.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class FORCEANDIMPULSE_API AKirIGR : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKirIGR();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArmComp;

	float WalkSpeed;
	float RunSpeed;
	bool isRun;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Amount);
	void MoveLeft(float Amount);
	void StartRun();
	void StopRun();
	void Jump();
	void StopJump();
};
