// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	SetRootComponent(BaseMesh);

	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshToMyMesh(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (StaticMeshToMyMesh.Succeeded())
	{
		asset = StaticMeshToMyMesh.Object;
		BaseMesh->SetStaticMesh(asset);
	}

	BaseMesh->SetSimulatePhysics(true);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");	

	SpringArm->SetupAttachment(BaseMesh);
	Camera->SetupAttachment(SpringArm);

	//SpringArm->SetWorldTransform();

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("ForwardBack", this, &AMyPawn::MoveForward);
	InputComponent->BindAxis("LeftRight", this, &AMyPawn::MoveLeft);
	InputComponent->BindAxis("CameraMovement", this, &AMyPawn::Movecamera1);
	InputComponent->BindAxis("CameraMovement2", this, &AMyPawn::Movecamera2);

}

void AMyPawn::MoveForward(float Value)
{
	FVector ForceToAdd = FVector(1, 0, 0) * MovementForce * Value;
	BaseMesh->AddForce(ForceToAdd);
}

void AMyPawn::MoveLeft(float Value)
{
	FVector ForceToAdd = FVector(0, 1, 0) * MovementForce * Value;
	BaseMesh->AddForce(ForceToAdd);
}

void AMyPawn::Movecamera1(float Value)
{
	FVector ForceToAdd = FVector(0, 1, 0) * MovementForce * Value;
	BaseMesh->AddForce(ForceToAdd);
}

void AMyPawn::Movecamera2(float Value)
{
	FVector ForceToAdd = FVector(1, 0, 0) * MovementForce * Value;
	BaseMesh->AddForce(ForceToAdd);
}



