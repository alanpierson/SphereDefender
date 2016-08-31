#include "SphereDefender.h"
#include "MainPlayer.h"


AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

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

	
	InputComponent->BindAxis("LookYaw", this, &AMainPlayer::LookYaw);
	InputComponent->BindAxis("LookPitch", this, &AMainPlayer::LookPitch);
	InputComponent->BindAxis("MoveForward", this, &AMainPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainPlayer::MoveRight);
}

void AMainPlayer::LookYaw(float val)
{
	AddControllerYawInput(val);
}

void AMainPlayer::LookPitch(float val)
{
	AddControllerPitchInput(val);
}

void AMainPlayer::MoveForward(float val)
{
	//FRotator Rotation(0, GetActorRotation().Yaw, 0);
	FVector Forward(1, 0, 0); //= FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
	AddMovementInput(Forward, val);
}

void AMainPlayer::MoveRight(float val)
{
	//FRotator Rotation(0, GetActorRotation().Yaw, 0);
	FVector Right(0, 1, 0); //= FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
	AddMovementInput(Right, val);
}

