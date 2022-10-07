#include <iostream>

using namespace std;

int Find_min_distance(int dist[], bool visited_edges[])
{
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < 9; v++) {
        if (visited_edges[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    }
    return min_index;
}

void Dijkstra(int graph[9][9], int user_pick)
{
    int dist[9];
    bool visited_edges[9];

    for (int i = 0; i < 9; i++)
        dist[i] = INT_MAX, visited_edges[i] = false;

    dist[user_pick] = 0;

    for (int count = 0; count < 9 - 1; count++) {
        int u = Find_min_distance(dist, visited_edges);
        visited_edges[u] = true;
        for (int point = 0; point < 9; point++)
            if (!visited_edges[point] && graph[u][point] && dist[u] != INT_MAX && dist[u] + graph[u][point] < dist[point])
                dist[point] = dist[u] + graph[u][point];
    }

    for (int i = 0; i < 9; i++)
        cout << dist[i] << '\t';
}


int main()
{
    int graph[9][9] =
    {
        { 0,  7,  10,  0,  0,  0,  0,  0,  0},
        { 7,  0,   0,  0,  0,  9, 27,  0,  0},
        {10,  0,   0,  0, 31,  8,  0,  0,  0},
        { 0,  0,   0,  0, 32,  0,  0, 17, 21},
        { 0,  0,  31, 32,  0,  0,  0,  0,  0},
        { 0,  9,   8,  0,  0,  0,  0, 11,  0},
        { 0, 27,   0,  0,  0,  0,  0,  0, 15},
        { 0,  0,   0, 17,  0, 11,  0,  0, 15},
        { 0,  0,   0, 21,  0,  0, 15, 15,  0},
    };
    int user_pick;
    bool flag = false;
    do {
        cout << "Choose edge: ";
        cin >> user_pick;
        cin.clear();
        cin.ignore();
    } while (user_pick < 0 || user_pick >= 8);

    Dijkstra(graph, user_pick);
}
