// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DriveBoy.generated.h"

class Node
{
public:
	float x, y, cost;
	Node *pred;
	Node() : x(0), y(0), cost(0), pred(nullptr) {}
	Node(int x, int y, int cost) : x(x), y(y), cost(cost), pred(nullptr) {}
};

bool operator==(const Node& a, const Node& b);
bool operator!=(const Node& a, const Node& b);

UCLASS(Blueprintable)
class ASTAR_API ADriveBoy : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom)
		float Distance = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom)
		TMap<int32, FString> NodesDict;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom)
		TArray<FVector> path;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom)
		AActor* player;

	UFUNCTION(BlueprintImplementableEvent, Category = CustomAction)
		void DrawCity();

	TArray<Node> nodes;

	ADriveBoy();
	void generateNodes();
	TOptional<Node*> findNode(float x, float y);
	TArray<Node*> getNeighbours(Node* n);
	TArray<FVector> astar(int Start, int End);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
