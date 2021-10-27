// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RunBoy.generated.h"

UCLASS(Blueprintable)
class BOIDS_API ARunBoy : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		int NbBoids;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		float ArenaSize;

	UFUNCTION(BlueprintImplementableEvent, Category = Default)
		void SpawnBoids();

	ARunBoy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
