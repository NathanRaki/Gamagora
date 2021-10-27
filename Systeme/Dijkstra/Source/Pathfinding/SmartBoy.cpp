// Fill out your copyright notice in the Description page of Project Settings.


#include "SmartBoy.h"

Maze::Maze() {}

Maze::Maze(int nbCases)
{
	adj = new int*[nbCases];
	for (int i = 0; i < nbCases; ++i)
	{
		adj[i] = new int[nbCases];
		for (int j = 0; j < nbCases; ++j)
		{
			adj[i][j] = 0;
		}
	}
}

void Maze::AddEdge(int a, int b, int value)
{
	adj[a][b] = value;
	adj[b][a] = value;
}

void Maze::Display()
{
	FString line;
	for (int i = 0; i < Size*Size; ++i)
	{
		line = "";
		for (int j = 0; j < Size*Size; ++j)
		{
			line += line.FromInt(adj[i][j]) + " ";
		}
		UE_LOG(LogTemp, Warning, TEXT("%s"), *line);
	}
}

int* Maze::Dijkstra(int start)
{
	std::vector<int> poids;
	int* distance = new int[Size*Size];
	int* pred = new int[Size*Size];
	for (int i = 0; i < Size * Size; ++i)
	{
		pred[i] = -1;
	}

	for (int i = 0; i < Size*Size; ++i)
	{
		distance[i] = INFINITY;
	}
	distance[start] = 0;
	int cursor = start;

	std::pair<int, int> min;
	while (poids.size() < Size*Size)
	{
		min = std::pair<int, int>(INFINITY, 0);
		for (int i = 0; i < Size*Size; ++i)
		{
			if (std::find(poids.begin(), poids.end(), i) == poids.end())
			{
				if (distance[i] < min.first) { min.first = distance[i]; min.second = i; break; }
			}
		}

		cursor = min.second;
		poids.push_back(cursor);
		
		for (int i = 0; i < Size*Size; ++i)
		{
			if (std::find(poids.begin(), poids.end(), i) == poids.end() && adj[cursor][i] != 0)
			{
				if (distance[i] > distance[cursor] + adj[cursor][i])
				{
					distance[i] = distance[cursor] + adj[cursor][i];
					pred[i] = cursor;
				}
			}
		}
	}
	return pred;
}

void ASmartBoy::GenerateGraph()
{

	level.Size = Size;
	level.cases = new Case[Size * Size];
	for (int i = 0; i < TPixels.Num(); ++i)
	{
		int x = i % Size;
		int y = i / Size;
		level.cases[i] = Case(x, y);
		if (TPixels[i] > 0) {
			level.cases[i].valid = true;
			if (x == SpawnPoint.X / Distance && y == SpawnPoint.Y / Distance)
				level.spawn = i;
			if (x == EndPoint.X / Distance && y == EndPoint.Y / Distance)
				level.end = i;
		}
	}

	for (int i = 0; i < Size*Size; ++i)
	{
		if (level.cases[i].valid)
		{
			int top = i - 16;
			int left = i - 1;
			int right = i + 1;
			int bottom = i + 16;
			if (top > 0)
				if (level.cases[top].valid)
					level.AddEdge(top, i, 1);
			if (left > 0)
				if (level.cases[left].valid)
					level.AddEdge(left, i, 1);
			if (right < Size * Size)
				if (level.cases[right].valid)
					level.AddEdge(right, i, 1);
			if (bottom < Size * Size)
				if (level.cases[bottom].valid)
					level.AddEdge(bottom, i, 1);
		}
	}
}

void ASmartBoy::GetPath()
{
	int* pred = level.Dijkstra(level.spawn);
	int cursor = level.end;
	while (cursor != -1)
	{
		path.push_back(cursor);
		cursor = pred[cursor];
	}
	std::reverse(path.begin(), path.end());
}

// Sets default values
ASmartBoy::ASmartBoy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HasWon = false;
	Current = 0;
}

// Called when the game starts or when spawned
void ASmartBoy::BeginPlay()
{
	Super::BeginPlay();

	FVector PlayerPosition = SpawnPoint;
	AI->SetActorLocation(PlayerPosition);

	level = Maze(TPixels.Num());

	GenerateGraph();
	GetPath();
}

// Called every frame
void ASmartBoy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector location = AI->GetActorLocation();
	if (Current != path.size() - 1)
	{
		int Case = path[Current];
		int NextCase = path[Current + 1];
		FVector src = FVector(level.cases[Case].x * Distance, level.cases[Case].y * Distance, Distance / 2.0f);
		FVector dst = FVector(level.cases[NextCase].x * Distance, level.cases[NextCase].y * Distance, Distance / 2.0f);
		AI->SetActorLocation(location + (dst - src) * DeltaTime * 4.0);
		location = AI->GetActorLocation();
		if (location.X > dst.X - Distance / 8.0 && location.X < dst.X + Distance / 8.0 && location.Y > dst.Y - Distance / 8.0 && location.Y < dst.Y + Distance / 8.0)
		{
			Current++;
		}
	}
}