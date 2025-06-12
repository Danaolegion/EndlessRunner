// Fill out your copyright notice in the Description page of Project Settings.


#include "WallSpike.h"

#include "Components/BoxComponent.h"

AWallSpike::AWallSpike()
{
	PrimaryActorTick.bCanEverTick=true;
	Collision=CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Collision->SetupAttachment(RootComponent);
}

void AWallSpike::BeginPlay()
{
	Super::BeginPlay();
	this->GetRootComponent()->ComponentVelocity =FVector(0,25.f,0);
}

void AWallSpike::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	SetActorLocation(GetActorLocation()+FVector(0,350.f*DeltaSeconds,0),true);
}
