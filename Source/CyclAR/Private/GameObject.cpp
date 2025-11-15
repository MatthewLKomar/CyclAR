#include "GameObject.h"

void AGameObject::UpdateObjectTransform(FTransform NewTransform)
{
	SetActorTransform(NewTransform);
	// TODO Interp Pose...
}

void AGameObject::DestroySelf()
{
	// TODO some effect or something when it gets killed.
	Destroy();
}
