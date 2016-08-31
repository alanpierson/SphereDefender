#include "SphereDefender.h"
#include "MainPlayer.h"


AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	/*TOP DOWN VIEW*/
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	PlayerCamera->AttachTo(CameraBoom);
}

void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AMainPlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AMainPlayer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	/*Allows phone gyroscope to control shield rotation. Disabled for now*/
	//InputComponent->BindVectorAxis("RotationRate", this, &AMainPlayer::OnRotationInput);
	
	/*Allows traditional WASD navigation. Disabled for now*/
	//InputComponent->BindAxis("Up_Down", this, &AMainPlayer::UpDown);
	//InputComponent->BindAxis("Left_Right", this, &AMainPlayer::LeftRight);
}

/* DISABLED FEATURES
void AMainPlayer::OnRotationInput(FVector Input)
{

	float val = 0.f;
	if (Input.X > 1.f || Input.X < -1.f)
	{
		val = val + (Input.X * 2.5);
		AddControllerYawInput(val);
	}
}


void AMainPlayer::UpDown(float val)
{
	FVector Forward(1, 0, 0);
	AddMovementInput(Forward, val);
}

void AMainPlayer::LeftRight(float val)
{
	FVector Right(0, 1, 0);
	AddMovementInput(Right, val);
}
*/

