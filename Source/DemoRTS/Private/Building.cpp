// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"
#include "Defines.h"
#include "Runtime/AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"

ABuilding::ABuilding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	VLogFS("Test");
}

void ABuilding::GetButtonInformation_Implementation(TArray<FString> &buttonNames) const
{
	for (int idx = 0; idx < m_buildingInfo.Num(); idx++)
	{
		FString name = m_buildingInfo[idx].m_name;
		buttonNames.Add(name);
	}
	
}

void ABuilding::ButtonClicked_Implementation(const FString& name) const
{
	VLogFS(name);
	for (int idx = 0; idx < m_buildingInfo.Num(); idx++)
	{
		FString _name = m_buildingInfo[idx].m_name;
		if (_name == name)
		{
			TSubclassOf < APawn > ActorClass = m_buildingInfo[idx].m_object;
			float		Offset = 10.0f;
			const FVector spawnPoint = GetActorLocation() + GetActorRightVector() * Offset;
			UAIBlueprintHelperLibrary::SpawnAIFromClass(GetWorld(), ActorClass, nullptr, spawnPoint, FRotator::ZeroRotator);
		}
	}
}