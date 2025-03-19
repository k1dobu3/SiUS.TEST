// Fill out your copyright notice in the Description page of Project Settings.


#include "TastyBalls.h"

// Sets default values
ATastyBalls::ATastyBalls()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	SetRootComponent(BaseMesh);

	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshToMyMesh(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (StaticMeshToMyMesh.Succeeded())
	{
		asset = StaticMeshToMyMesh.Object;
		BaseMesh->SetStaticMesh(asset);
	}

	Impulse = FVector(0.0f, 0.0f, 10.0f);
	ImpulsePower = 100.0f;

	Mass = 1.0f;

}

// Called when the game starts or when spawned
void ATastyBalls::BeginPlay()
{
	Super::BeginPlay();
	
	BaseMesh->SetSimulatePhysics(true);
	BaseMesh->SetNotifyRigidBodyCollision(true);
	BaseMesh->SetMassOverrideInKg(NAME_None, Mass, true);

	BaseMesh->OnComponentHit.AddDynamic(this, &ATastyBalls::OnHit);
}

// Called every frame
void ATastyBalls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATastyBalls::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	BaseMesh->AddImpulse(Impulse * ImpulsePower);

	UE_LOG(LogTemp, Warning, TEXT("bounce"));
}

