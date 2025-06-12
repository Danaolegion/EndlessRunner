// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerChar.h"
#include "EndlessPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
UCLASS()
class ENDLESSRUNNERTUTO_API AEndlessPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	//Inputs
	UPROPERTY(EditDefaultsOnly,Category="Input")
	UInputMappingContext* FPSMappingContext;

	UPROPERTY(EditDefaultsOnly,Category="Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly,Category="Input")
	UInputAction* JumpAction;

	//Functions
	void MoveRight(const FInputActionValue& Value );
	void PlayerJump();
};
