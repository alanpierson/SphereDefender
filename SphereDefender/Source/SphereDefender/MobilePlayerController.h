// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MobilePlayerController.generated.h"

UCLASS()
class SPHEREDEFENDER_API AMobilePlayerController : public APlayerController
{
	GENERATED_BODY()

		void Tick(float DeltaTime);
	
	
};
