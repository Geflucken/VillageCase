// Konstantinos Papafoteinos 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class VILLAGECASE_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	//Spawns a new actor in the game
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void PlaceActor(TSubclassOf<AActor> ToSpawn, float Radius);

private:
	//Checks if the location is suitable for spawning the actor (collisions)
	bool CanSpawnAtLocation(FVector Location, float Radius);

	//Tries to find a suitable location for spawning around the spawner
	bool FindEmptyLocation(FVector& OutLocation,float Radius);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
