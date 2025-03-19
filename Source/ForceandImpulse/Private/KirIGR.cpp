// Fill out your copyright notice in the Description page of Project Settings.


#include "KirIGR.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AKirIGR::AKirIGR()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpiringArm"));

	SpringArmComp->SetupAttachment(GetRootComponent());
	CameraComp->SetupAttachment(SpringArmComp);

	SpringArmComp->bUsePawnControlRotation = true;

	WalkSpeed = 600.0f;
	RunSpeed = 999.0f;
	isRun = false;
}

// Called when the game starts or when spawned
void AKirIGR::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKirIGR::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKirIGR::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("MoveForward", this, &AKirIGR::MoveForward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AKirIGR::MoveLeft);
	PlayerInputComponent->BindAxis("LookUp", this, &AKirIGR::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &AKirIGR::AddControllerYawInput);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AKirIGR::StartRun);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AKirIGR::StopRun);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AKirIGR::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AKirIGR::StopJump);
}

void AKirIGR::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AKirIGR::MoveLeft(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}

void AKirIGR::StartRun()
{
	isRun = true;
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void AKirIGR::StopRun()
{
	isRun = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AKirIGR::Jump()
{
	bPressedJump = true;
}

void AKirIGR::StopJump()
{
	bPressedJump = false;
}

