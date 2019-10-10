// Konstantinos Papafoteinos 2019


#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolRoute.h"
#include "AIController.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get the patrol route
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing patrol points"));
		return EBTNodeResult::Failed;
	}

	//Set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle the Index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);


	UE_LOG(LogTemp, Warning, TEXT(" Index:"), Index)
	return EBTNodeResult::Succeeded;
}