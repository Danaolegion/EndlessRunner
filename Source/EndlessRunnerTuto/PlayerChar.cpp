// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Spikes.h"
#include "Engine.h"
#include "WallSpike.h"
#include "PlayerChar.h"


// Sets default values
APlayerChar::APlayerChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f,96.4f);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1,ECR_Overlap);

	bUseControllerRotationPitch=false;
	bUseControllerRotationRoll=false;
	bUseControllerRotationYaw=false;

	SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCamera->bUsePawnControlRotation=false;
	
	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate= FRotator(0.f,720.f,0.f);

	GetCharacterMovement()->AirControl =0.8f;
	GetCharacterMovement()->GroundFriction =3.f;
	GetCharacterMovement()->GravityScale =2.f;
	GetCharacterMovement()->JumpZVelocity=1000.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed =600.f;

	tempPos=GetActorLocation();
	zPosition =tempPos.Z +300.f;
}

// Called when the game starts or when spawned
void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this,&APlayerChar::OnOverlapBegin);
	CanMove= true;
}

// Called every frame
void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	tempPos=GetActorLocation();
	tempPos.X=-850.f;
	tempPos.Z=zPosition;
	
	SideViewCamera->SetWorldLocation(tempPos);
}

// Called to bind functionality to input
void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerChar::MoveRight(const FInputActionValue& Value)
{
	if(CanMove)
	{
		const FVector MovementValue =Value.Get<FVector>();
		const FVector RightDirection =FVector(0.0f,1.0f,0.0f);
		AddMovementInput(RightDirection,MovementValue.X);
	}
}

void APlayerChar::Jumping()
{
	Jump(); 
}

void APlayerChar::RestartLevel()
{
	UGameplayStatics::OpenLevel(this,FName(*GetWorld()->GetName()));
}

void APlayerChar::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bfromsweep, const FHitResult& SweepResult)
{
	if(OtherActor != nullptr)
	{
		ASpikes* WallSpike=Cast<AWallSpike>(OtherActor);
		ASpikes* Spike    =Cast<ASpikes>(OtherActor);
		if(WallSpike || Spike)
		{
			GetMesh()->Deactivate();
			GetMesh()->SetVisibility(false);
			CanMove =false;

			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(UnusedHandle,this,&APlayerChar::RestartLevel,
				2.f,false);
			
		}
	}
}

