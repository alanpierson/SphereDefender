#include "SphereDefender.h"
#include "MainActor.h"


AMainActor::AMainActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMainActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMainActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

