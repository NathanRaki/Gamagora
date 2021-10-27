// Fill out your copyright notice in the Description page of Project Settings.


#include "DriveBoy.h"

bool operator==(const Node& a, const Node& b) { return (a.x == b.x && a.y == b.y); }
bool operator!=(const Node& a, const Node& b) { return (a.x != b.x || a.y != b.y); }

// Sets default values
ADriveBoy::ADriveBoy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADriveBoy::generateNodes()
{
	for (int i = 0; i < NodesDict.Num(); ++i)
	{
		FString x;
		FString y;
		NodesDict[i].Split(" ", &x, &y);
		nodes.Add(Node(FCString::Atof(*x) * Distance, FCString::Atof(*y) * Distance, 0.0f));
	}
}

TOptional<Node*> ADriveBoy::findNode(float x, float y)
{
	for (int i = 0; i < nodes.Num(); ++i)
	{
		if (nodes[i].x == x && nodes[i].y == y) { return &nodes[i]; }
	}
	return TOptional<Node*>();
}

TArray<Node*> ADriveBoy::getNeighbours(Node* n)
{
	TArray<Node*> neighbours;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i == 0 && j == 0) { continue; }
			TOptional<Node*> neighbour = findNode(n->x + i * Distance, n->y + j * Distance);
			if (neighbour.IsSet()) { neighbours.Add(neighbour.GetValue()); }
		}
	}
	return neighbours;
}

TArray<FVector> ADriveBoy::astar(int Start, int End)
{
	TArray<Node*> opened;
	TArray<Node*> closed;
	TArray<Node*> neighbours;
	TArray<FVector> res;
	int cursor;
	float min;

	opened.Add(&nodes[Start]);

	while (opened.Num() != 0)
	{
		min = 9999.0f;
		for (int i = 0; i < opened.Num(); ++i)
		{
			if (opened[i]->cost < min) { cursor = i; min = opened[i]->cost; }
		}

		Node* nX = opened[cursor];

		if (nX == &nodes[End])
		{
			while (nX != nullptr)
			{
				res.Add(FVector(nX->x, nX->y, 100.0f));
				nX = nX->pred;
			}
			for (int i = 0, j = res.Num() - 1; i < j; i++, j--) { Swap(res[i], res[j]); }
			return res;
		}

		closed.Add(nX);
		opened.Remove(nX);

		neighbours = getNeighbours(nX);
		for (int i = 0; i < neighbours.Num(); ++i)
		{
			if (!opened.Contains(neighbours[i]) && !closed.Contains(neighbours[i]))
			{
				neighbours[i]->cost = nX->cost + (nodes[End].x - neighbours[i]->x) + (nodes[End].y - neighbours[i]->y);
				neighbours[i]->pred = nX;
				opened.Add(neighbours[i]);
			}
		}
	}
	return res;
}

// Called when the game starts or when spawned
void ADriveBoy::BeginPlay()
{
	Super::BeginPlay();
	
	generateNodes();

	path = astar(0, 17);
	for (int i = 0; i < path.Num(); ++i)
	{
		UE_LOG(LogTemp, Warning, TEXT("%f, %f"), path[i].X, path[i].Y);
	}

	float x = nodes[0].x;
	float y = nodes[0].y;
	player->SetActorLocation(FVector(x, y, 500.0f), false, (FHitResult*)nullptr, ETeleportType::TeleportPhysics);

	DrawCity();

}

// Called every frame
void ADriveBoy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

