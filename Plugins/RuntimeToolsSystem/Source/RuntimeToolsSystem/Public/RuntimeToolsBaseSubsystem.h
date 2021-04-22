// CMES 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <Tickable.h>
#include "RuntimeToolsBaseSubsystem.generated.h"

/**
 * Base System Class
 */

UCLASS(Abstract, BlueprintType, EditInlineNew, Within = GameInstance)
class URuntimeToolsBaseSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:
	/**
	 * FTickableGameObject methods
	 */

	virtual void Tick(float DeltaTime) override {}

	// Must override in subclasses, that need ticking
	virtual bool IsTickable() const override
	{
		return !IsPendingKill() && !HasAnyFlags(RF_ClassDefaultObject);
	}

	virtual bool IsTickableWhenPaused() const override
	{
		return true;
	}

	virtual TStatId GetStatId() const override
	{
		return TStatId();
	}
};
