// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelGenerator.h"
#include "BaseLevel.h"
#include "Components/BoxComponent.h"

// Sets default values
ALevelGenerator::ALevelGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelGenerator::BeginPlay()
{
	Super::BeginPlay();
	LevelArray={Level1,Level2,Level3,Level4,Level5,Level6};
	SpawnLevel(true);
	SpawnLevel(false);
	SpawnLevel(false);
	SpawnLevel(false);
}

// Called every frame
void ALevelGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelGenerator::SpawnLevel(bool bIsFirst)
{
	SpawnLocation =FVector(0,10.f,0);
	SpawnRotation =FRotator(0,90.f,0);

	if(!bIsFirst && LevelList.Num()>0)
	{
		ABaseLevel* Lastlevel= LevelList.Last();
		if(Lastlevel)
		{
			SpawnLocation= Lastlevel->GetSpawnLocation()->GetComponentTransform().GetTranslation();
		}
	}


	Randomlevel =FMath::RandRange(1,LevelArray.Num()-1);
	ABaseLevel* NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelArray[Randomlevel],SpawnLocation,SpawnRotation,SpawnInfo);

	if(NewLevel)
	{
		if(NewLevel->GetTrigger())
		{
			NewLevel->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this,&ALevelGenerator::OnOverlapBegin);
		}

		LevelList.Add(NewLevel);
	}
	if(LevelList.Num() >5)
	{
		LevelList.RemoveAt(0);
	}
	
}

void ALevelGenerator::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bfromsweep, const FHitResult& SweepResult)
{
	SpawnLevel(false);
}

