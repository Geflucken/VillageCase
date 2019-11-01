// Konstantinos Papafoteinos 2019


#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASpawner::PlaceActors()
{
	FBox SpawnSpace = FBox(FVector(22970,26170,100),FVector(23030,26230,100));
	for (int i = 0; i < 20; i++)
	{
		FVector SpawnPoint = FMath::RandPointInBox(SpawnSpace);
		UE_LOG(LogTemp, Warning, TEXT("Spawn Point %s"), *SpawnPoint.ToCompactString())
	}
}


// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

