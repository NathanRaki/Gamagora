// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomNodes.generated.h"

/**
 * 
 */
UCLASS()
class ASTAR_API UCustomNodes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, Category = "Custom")
		static void FileLoadString(FString FileName, FString& SaveText);
};
