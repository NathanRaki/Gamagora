// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#include <string>
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Graph.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PATHFINDING_API UGraph : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pixels)
		TArray<FColor> TColors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pixels)
		TArray<int32> TPixels;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pixels)
		float Distance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pixels)
		int32 Size;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;

	UGraph();

	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
