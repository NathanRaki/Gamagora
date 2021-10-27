#include <iostream>
#include <vector>
#include <limits>

using pos = std::pair<int, int>;

struct graph
{
    std::vector<pos> coords;
    std::vector<std::vector<int>> matrix;
    int nbVertices() { return coords.size(); }
};

int FindMinVertex(double* distance, bool* visited, graph G)
{
    int minVertex = -1;
    for (int i = 0; i < G.nbVertices(); ++i)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(graph G, const int& src)
{
    double* distance = new double[G.nbVertices()];
    bool* visited = new bool[G.nbVertices()];

    // Initialisation
    for (int i = 0; i < G.nbVertices(); ++i)
    {
        distance[i] = std::numeric_limits<double>::infinity();
        visited[i] = false;
    }

    distance[src] = 0;

    for (int i = 0; i < G.nbVertices()-1; ++i)
    {
        int minVertex = FindMinVertex(distance, visited, G);
        visited[minVertex] = true;
        for (int j = 0; j < G.nbVertices(); ++j)
        {
            if (G.matrix[minVertex][j] != 0 && !visited[j])
            {
                double dist = distance[minVertex] + G.matrix[minVertex][j];
                if (dist < distance[j]) { distance[j] = dist; }
            }
        }
    }

    for (int i = 0; i < G.nbVertices(); ++i)
    {
        if (i != src)
        {
            std::cout << "\t" << src+1 << " -> " << i+1 << " : " << distance[i] << std::endl;
        }
    }
}

double calcHCost(const graph& G, const int& src, const int& dst)
{

}

int main()
{
    graph g;
    // Adjacency matrix
    std::vector<int> L1{0, 0, 2, 0, 0, 0};
    std::vector<int> L2{1, 0, 0, 0, 0, 0};
    std::vector<int> L3{0, 2, 0, 6, 0, 10};
    std::vector<int> L4{0, 0, 0, 0, 0, 6};
    std::vector<int> L5{0, 0, 0, 0, 0, 0};
    std::vector<int> L6{0, 0, 0, 0, 2, 0};
    g.matrix.push_back(L1);
    g.matrix.push_back(L2);
    g.matrix.push_back(L3);
    g.matrix.push_back(L4);
    g.matrix.push_back(L5);
    g.matrix.push_back(L6);

    // Coordinates
    g.coords.push_back(pos(0, 0));
    g.coords.push_back(pos(2, 0));
    g.coords.push_back(pos(2, 2));
    g.coords.push_back(pos(4, 0));
    g.coords.push_back(pos(2, 4));
    g.coords.push_back(pos(4, 4));

    // Exec
    dijkstra(g, 0);
}
