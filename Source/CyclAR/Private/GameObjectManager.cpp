#include "GameObjectManager.h"

#include "CyclAR/CyclAR.h"

void UGameObjectManager::StartManager()
{
	GetWorld()->GetTimerManager().SetTimer(
	   GameObjectMoverTimerHandle,                
	   this,                          
	   &ThisClass::GameObjectMover,    
	   0.1f,                          
	   true                          
	);
}
void UGameObjectManager::TrackGameObject(AGameObject* GameObject)
{
	if (!GameObject)
	{
		SIMPLE_LOG(Warning, "Gameobject is nullptr");
		return;
	}
	GameObjectMap.Add(GameObject->GetUniqueID(), GameObject);
	SIMPLE_LOG(Log, "added tracked object");
}

void UGameObjectManager::GameObjectMover()
{
	SIMPLE_LOG(Log, "trying to move");

	for (const TPair<int, AGameObject*>& KeyValuePair :  GameObjectMap)
	{
		SIMPLE_LOG(Log, "Updating %s Location." , *KeyValuePair.Value->GetName());
		FTransform NewLocation = FTransform();
		FVector Location = KeyValuePair.Value->GetActorLocation();
		Location.X += 5;
		NewLocation.SetLocation(Location);
		UpdateTrackedGameObject(KeyValuePair.Key, NewLocation);		
	}
}

void UGameObjectManager::UpdateTrackedGameObject(int GameObjectID, FTransform NewTransform)
{
	AGameObject* GameObject = *GameObjectMap.Find(GameObjectID);
	if (!GameObject)
	{
		SIMPLE_LOG(Warning, "Gameobject is nullptr");
		return;
	}
	GameObject->UpdateObjectTransform(NewTransform);
}



void UGameObjectManager::DestroyGameObject(int GameObjectID)
{
	AGameObject* GameObject = GameObjectMap.FindAndRemoveChecked(GameObjectID);
	if (!GameObject)
	{
		SIMPLE_LOG(Warning, "Gameobject is nullptr");
		return;
	}
	GameObject->DestroySelf();
}
