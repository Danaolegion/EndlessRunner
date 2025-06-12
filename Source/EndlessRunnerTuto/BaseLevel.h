// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseLevel.generated.h"

class UBoxComponent;

UCLASS()
class ENDLESSRUNNERTUTO_API ABaseLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* Trigger;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnLocation;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* FloorMesh;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* CubeMesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UBoxComponent* GetTrigger();
	UBoxComponent* GetSpawnLocation();
};
