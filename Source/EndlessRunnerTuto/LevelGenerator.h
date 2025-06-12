// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator.generated.h"
class ABaseLevel;
UCLASS()
class ENDLESSRUNNERTUTO_API ALevelGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
	void SpawnLevel(bool bIsFirst);
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,AActor* OtherActor,UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,bool bfromsweep,
	const FHitResult& SweepResult);
protected:
	UPROPERTY()
	APawn* Player;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseLevel> Level1;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseLevel> Level2;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseLevel> Level3;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseLevel> Level4;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseLevel> Level5;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseLevel> Level6;

	UPROPERTY()
	TArray<ABaseLevel*> LevelList;
	UPROPERTY()
	TArray<TSubclassOf<ABaseLevel>> LevelArray;
public:
	int Randomlevel;

	FVector SpawnLocation =FVector();
	FRotator SpawnRotation=FRotator();
	FActorSpawnParameters SpawnInfo=FActorSpawnParameters();
};
