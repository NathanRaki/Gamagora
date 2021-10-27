#include "follow.h"

int Graph::findMinVertex(double* distance, bool* visited)
{
    int minVertex = -1;
    for (int i = 0; i < nbVertices(); ++i)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

float Graph::dijkstra(const int& src, const int& dst)
{
    double* distance = new double[nbVertices()];
    bool* visited = new bool[nbVertices()];

    // Initialisation
    for (int i = 0; i < nbVertices(); ++i)
    {
        distance[i] = std::numeric_limits<double>::infinity();
        visited[i] = false;
    }

    distance[src] = 0;

    for (int i = 0; i < nbVertices() - 1; ++i)
    {
        int minVertex = findMinVertex(distance, visited);
        visited[minVertex] = true;
        for (int j = 0; j < nbVertices(); ++j)
        {
            if (matrix[minVertex][j] != 0 && !visited[j])
            {
                double dist = distance[minVertex] + matrix[minVertex][j];
                if (dist < distance[j]) { distance[j] = dist; }
            }
        }
    }

    return distance[dst];
}

double Graph::calcHCost(const int& src, const int& dst)
{
    return 0;
}

Ufollow::Ufollow()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void Ufollow::BeginPlay()
{
	Super::BeginPlay();
    Graph g;
    // Adjacency matrix
    std::vector<int> L1{ 0, 0, 2, 0, 0, 0 };
    std::vector<int> L2{ 1, 0, 0, 0, 0, 0 };
    std::vector<int> L3{ 0, 2, 0, 6, 0, 10 };
    std::vector<int> L4{ 0, 0, 0, 0, 0, 6 };
    std::vector<int> L5{ 0, 0, 0, 0, 0, 0 };
    std::vector<int> L6{ 0, 0, 0, 0, 2, 0 };
    g.pushLine(L1);
    g.pushLine(L2);
    g.pushLine(L3);
    g.pushLine(L4);
    g.pushLine(L5);
    g.pushLine(L6);

    // Coordinates
    g.pushCoord(pos(0, 0));
    g.pushCoord(pos(2, 0));
    g.pushCoord(pos(2, 2));
    g.pushCoord(pos(4, 0));
    g.pushCoord(pos(2, 4));
    g.pushCoord(pos(4, 4));

    UE_LOG(LogTemp, Warning, TEXT("%f"), g.dijkstra(0,5));
}

void Ufollow::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

