// Fill out your copyright notice in the Description page of Project Settings.

#include "SphereDefender.h"
#include "MobilePlayerController.h"

void AMobilePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bool test;
	FVector Tilt;
	FVector RotationRate;
	FVector Gravity;
	FVector Acceleration;

	test = PlayerInput->InputMotion(Tilt, RotationRate, Gravity, Acceleration);

	UE_LOG(LogTemp, Warning, TEXT("RotationRate X : %f / Y : %f / Z : %f"), RotationRate.X, RotationRate.Y, RotationRate.Z);
	UE_LOG(LogTemp, Warning, TEXT("Gravity X : %f / Y : %f / Z : %f"), Gravity.X, Gravity.Y, Gravity.Z);
	UE_LOG(LogTemp, Warning, TEXT("Acceleration X : %f / Y : %f / Z : %f"), Acceleration.X, Acceleration.Y, Acceleration.Z);
}



