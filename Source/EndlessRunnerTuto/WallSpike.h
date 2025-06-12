// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spikes.h"
#include "WallSpike.generated.h"

/**
 * 
 */
class UBoxComponent;
UCLASS()
class ENDLESSRUNNERTUTO_API AWallSpike : public ASpikes
{
	GENERATED_BODY()
	AWallSpike();

public:
	UPROPERTY(EditAnywhere)
	UBoxComponent* Collision;
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaSeconds) override;
};
