// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "TastyBalls.generated.h"

UCLASS()
class FORCEANDIMPULSE_API ATastyBalls : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATastyBalls();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PARAMETERS)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float Mass;

	UStaticMesh* asset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PARAMETERS)
	FVector Impulse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PARAMETERS)
	float ImpulsePower;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
