#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Interface.h"
#include "RTSContextObject.generated.h"

UINTERFACE(Blueprintable)
class DEMORTS_API URTSContextObject : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class DEMORTS_API IRTSContextObject
{
	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Context Menu")
	FString GetTypeName() const;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Context Menu")
	void GetButtonInformation(TArray<FString> &buttonNames) const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Context Menu")
	void ButtonClicked(const FString& name) const;
};