// Konstantinos Papafoteinos 2019


#include "Spawner.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"

// Sets default values
ASpawner::ASpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASpawner::PlaceActor(TSubclassOf<AActor> ToSpawn, float Radius)
{
	//UE_LOG(LogTemp, Warning, TEXT("ROOT: %s"), *SpawnerLocation.ToCompactString())
	int32 MaxItems = 1; // If we want to increase the number of actors spawning in the future
	for (size_t i = 0; i < MaxItems; i++)
	{
		FVector SpawnPoint;
		bool found = FindEmptyLocation(SpawnPoint, Radius);
		if (found)
		{
			float Rotation = FMath::RandRange(-180.f, 180.f);
			AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
			Spawned->SetActorRelativeLocation(SpawnPoint);
			Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
			Spawned->SetActorRotation(FRotator(0, Rotation, 0));
		}	
	}
}

bool ASpawner::FindEmptyLocation(FVector& OutLocation, float Radius)
{
	FBox SpawnSpace(FVector(-200,-200,0), FVector(200,200,0));
	const int MAX_ATTEMPTS = 100;
	for (size_t i = 0; i < MAX_ATTEMPTS; i++)
	{
		FVector CandidatePoint = FMath::RandPointInBox(SpawnSpace);
		if (CanSpawnAtLocation(CandidatePoint,Radius))
		{
			OutLocation = CandidatePoint;
			return true;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("false ") )
	return false ;
}

bool ASpawner::CanSpawnAtLocation(FVector Location, float Radius)
{
	FHitResult HitResult;
	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GlobalLocation,
		GlobalLocation + FVector(0,0,1),
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		FCollisionShape::MakeSphere(Radius)
	);
	/*FColor ResultColor = HasHit ? FColor::Red : FColor::Green;
	DrawDebugCapsule(GetWorld(), GlobalLocation, 0, Radius, FQuat::Identity, ResultColor, true, 100);*/
	return !HasHit;
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

