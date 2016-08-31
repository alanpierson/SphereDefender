#pragma once

#include "GameFramework/Actor.h"
#include "MainActor.generated.h"

UCLASS()
class SPHEREDEFENDER_API AMainActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMainActor();

	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;

};
