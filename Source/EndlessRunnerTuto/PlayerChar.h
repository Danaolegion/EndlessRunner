// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerChar.generated.h"

class UCameraComponent;

UCLASS()
class ENDLESSRUNNERTUTO_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* SideViewCamera;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	

public:
	void MoveRight(const FInputActionValue& Value);
	void Jumping();
	class UCameraComponent* GetSideViewCameraComponent() const
	{
		return SideViewCamera;
	}
	void RestartLevel();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,AActor* OtherActor,
		UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool bfromsweep,
		const FHitResult& SweepResult);
private:
	float zPosition;
	FVector tempPos= FVector();
	bool CanMove;
};
