// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include <string>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SmartBoy.generated.h"

#define INFINITY 9999

class Case
{
public:
	int x;
	int y;
	bool valid;
	Case() : x(0), y(0), valid(false) {}
	Case(int x, int y) : x(x), y(y), valid(false) {}
	Case(int x, int y, bool valid) : x(x), y(y), valid(valid) {}
};

class Maze
{
public:
	int** adj;
	Case* cases;
	int Size;
	int spawn;
	int end;

	Maze();
	Maze(int nbCases);
	void AddEdge(int a, int b, int value);
	void Display();
	int* Dijkstra(int start);
};

UCLASS(Blueprintable)
class PATHFINDING_API ASmartBoy : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pixels)
		TArray<FColor> TColors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pixels)
		TArray<int32> TPixels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pixels)
		float Distance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pixels)
		int32 Size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pixels)
		FVector SpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pixels)
		FVector EndPoint;

	UPROPERTY(EditAnywhere)
		AActor* AI;

	bool HasWon;
	Maze level;
	int Current;
	std::vector<int> path;

	ASmartBoy();
	void GenerateGraph();
	void GetPath();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
