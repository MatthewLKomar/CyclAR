#pragma once

#include "CoreMinimal.h"
#include "GameObject.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "GameObjectManager.generated.h"

UCLASS()
class CYCLAR_API UGameObjectManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "Game Object Manager")
	void StartManager();

	UFUNCTION(BlueprintCallable, Category = "Game Object Manager")
	void TrackGameObject(AGameObject* GameObject);

	UFUNCTION()
	void GameObjectMover();

	UFUNCTION(BlueprintCallable, Category = "Game Object Manager")
	void UpdateTrackedGameObject(int GameObjectID, FTransform NewTransform);

	UFUNCTION(BlueprintCallable, Category = "Game Object Manager")
	void DestroyGameObject(int GameObjectID);

	UPROPERTY(BlueprintReadOnly, Category = "Game Object Manager")
	TMap<int32, AGameObject*> GameObjectMap;

private:
	FTimerHandle GameObjectMoverTimerHandle;
};
