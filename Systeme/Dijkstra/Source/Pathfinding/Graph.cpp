// Fill out your copyright notice in the Description page of Project Settings.


#include "Graph.h"

// Sets default values for this component's properties
UGraph::UGraph()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGraph::BeginPlay()
{
	Super::BeginPlay();
	TArray<UStaticMeshComponent*> walls;
	USceneComponent* RootComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	for (int i = 0; i < 1; ++i)
	{

	}
	// ...
}


// Called every frame
void UGraph::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

