// Konstantinos Papafoteinos 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

/**
* A "route card" to help AI choose their next waypoint
**/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VILLAGECASE_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> GetPatrolPoints() const;

private: 
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPoints;

};
