#pragma once

#include "CoreMinimal.h"
#include "RTSContextObject.h"
#include "Engine/StaticMeshActor.h"

#include "Building.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct  FBuildingInfo
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, Category = "Building")
		FString m_name;
	UPROPERTY(EditDefaultsOnly, Category = "Building")
		TSubclassOf < APawn > m_object;
};


UCLASS()
class DEMORTS_API ABuilding : public AStaticMeshActor , public IRTSContextObject
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(EditDefaultsOnly , Category = "Building")
	FString m_ObjectName;

	UPROPERTY(EditDefaultsOnly, Category = "Building")
	TArray<FBuildingInfo> m_buildingInfo;
public:

	virtual FString GetTypeName_Implementation() const override { return m_ObjectName; }

	virtual void GetButtonInformation_Implementation(TArray<FString> &buttonNames) const override;

	virtual void ButtonClicked_Implementation(const FString& name) const override;
protected:
	virtual void BeginPlay() override;
	
	
};
