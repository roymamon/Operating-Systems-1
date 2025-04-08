#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define V 9

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        if (u == -1) break;
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    for (;;) {
        int graph[V][V];
        bool valid = true;
        char buffer[256];

        printf("enter a 9x9 adjacency matrix (0 to quit):\n");

        for (int i = 0; i < V && valid; i++) {
            if (!fgets(buffer, sizeof(buffer), stdin)) {
                valid = false;
                break;
            }

            int count = 0;
            char *token = strtok(buffer, " \t\n");
            while (token && count < V) {
                int val = atoi(token);
                if (val < 0) {
                    printf("invalid input: negative edge detected\n");
                    valid = false;
                    break;
                }
                graph[i][count++] = val;
                token = strtok(NULL, " \t\n");
            }
            if(!valid) break;
            if (count < V) {
                printf("too few values in row %d.\n", i + 1);
                valid = false;
                break;
            } else if (token != NULL) {
                printf("too many values in row %d.\n", i + 1);
                valid = false;
                break;
            }
        }

        if (!valid) {
            break;
        }

        dijkstra(graph, 0);
        printf("\n");
    }

    return 0;
}
