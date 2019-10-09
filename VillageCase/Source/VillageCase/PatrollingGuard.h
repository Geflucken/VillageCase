// Konstantinos Papafoteinos 2019

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class VILLAGECASE_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public: // TODO make getter
		UPROPERTY (EditInstanceOnly, Category = "Patrol Route")
		TArray<AActor*> PatrolPointsCPP;
	
};
