// Fill out your copyright notice in the Description page of Project Settings.

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "EndlessPlayerController.h"


void AEndlessPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(FPSMappingContext,0);
	}
}

void AEndlessPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if(UEnhancedInputComponent* EnhancedInput=Cast<UEnhancedInputComponent>(InputComponent))
	{
		if(MoveAction)
		{
			EnhancedInput->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AEndlessPlayerController::MoveRight);
		}
		if(JumpAction)
		{
			EnhancedInput->BindAction(JumpAction,ETriggerEvent::Started,this,&AEndlessPlayerController::PlayerJump);
		}
	}
}

void AEndlessPlayerController::MoveRight(const FInputActionValue& Value)
{
	if(APlayerChar* Char = Cast<APlayerChar>(GetPawn()))
	{
		Char->MoveRight(Value);
	}
}

void AEndlessPlayerController::PlayerJump()
{
	if(APlayerChar* Char =Cast<APlayerChar>(GetPawn()))
	{
		Char->Jumping();
	}
}


