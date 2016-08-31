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

	
	//InputComponent->BindAxis("Rotate", this, &AMainPlayer::Rotate);
	InputComponent->BindVectorAxis("RotationRate", this, &AMainPlayer::OnRotationInput);
	InputComponent->BindAxis("Up_Down", this, &AMainPlayer::UpDown);
	InputComponent->BindAxis("Left_Right", this, &AMainPlayer::LeftRight);
}

/*
void AMainPlayer::Rotate(float val)
{
	AddControllerYawInput(val);
}
*/

void AMainPlayer::OnRotationInput(FVector Input)
{

	//static float DEG_TO_RAD = PI / (180.f);

	//TODO: get right and down scale factor from player controller to make the game playable for people who don't want to do full body motions, like while sitting

	//FQuat RightRot = FQuat(FVector(0.f, 0.f, -1.f), Input.Y * DEG_TO_RAD);		//Why is right reversed, I don't know...  Damnit MATH!!!!
	//FQuat DownRot = FQuat(FVector(0.f, 1.f, 0.f), Input.X * DEG_TO_RAD);
	//FQuat RollLeftRot = FQuat(FVector(1.f, 0.f, 0.f), Input.Z * DEG_TO_RAD);

	//FQuat Result = GetActorQuat() * RightRot * DownRot * RollLeftRot;

	//SetActorRotation(Result.Rotator());
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

