#pragma once

#include <vector>
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "follow.generated.h"

using pos = std::pair<int, int>;
class Graph
{
public:
	int nbVertices() { return coords.size(); }
	int findMinVertex(double* distance, bool* visited);
	float dijkstra(const int& src, const int& dst);
	double calcHCost(const int& src, const int& dst);

	void pushCoord(pos p) { coords.push_back(p); }
	void pushLine(std::vector<int> l) { matrix.push_back(l); }

private:
	std::vector<pos> coords;
	std::vector<std::vector<int>> matrix;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PATHFINDING_API Ufollow : public UActorComponent
{
	GENERATED_BODY()

public:	
	Ufollow();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
