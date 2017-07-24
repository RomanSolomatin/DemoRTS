#pragma once
#include "pchPublic.h"
#include "DemoGameEngine.generated.h"


UCLASS()
class DEMORTS_API UDemoGameEngine : public UGameEngine

{
	GENERATED_UCLASS_BODY()
public:
	virtual void Init(class IEngineLoop* InEngineLoop) ;
	virtual void Start();
	virtual void PreExit();
	virtual void Tick(float DeltaSeconds, bool bIdleMode);
};