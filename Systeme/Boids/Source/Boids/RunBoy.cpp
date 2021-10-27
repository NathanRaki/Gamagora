// Fill out your copyright notice in the Description page of Project Settings.


#include "RunBoy.h"

// Sets default values
ARunBoy::ARunBoy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARunBoy::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnBoids();
}

// Called every frame
void ARunBoy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

