#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameObject.generated.h"

UCLASS()
class CYCLAR_API AGameObject : public AActor
{
	GENERATED_BODY()
	
public:
	void UpdateObjectTransform(FTransform NewTransform);
	void DestroySelf();
};
