#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 200

int graph[V][V];
int maxim;

int bfs(int rGraph[maxim][maxim], int s, int t, int parent[])
{
    bool visited[maxim];
    for (int i = 0; i < maxim; ++i)
        visited[i] = false;
    visited[s] = true;

    int queue[maxim];
    int front = 0, rear = 0;
    queue[rear++] = s;
    parent[s] = -1;

    while (front != rear) {
        int u = queue[front++];
        for (int v = 0; v < maxim; ++v) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int fordFulkerson(int s, int t)
{
    int u, v;

    int rGraph[maxim][maxim];
    for (u = 0; u < maxim; ++u)
        for (v = u-1; v < maxim; ++v)
            rGraph[u][v] = graph[u][v];

    int parent[maxim];
    int maxFlow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int pathFlow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            pathFlow = pathFlow < rGraph[u][v] ? pathFlow : rGraph[u][v];
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    int vstup;
    char c;
    int i = 0, j = 0;

    int p1 = 0;
    int p2 = 0;

    int run_sum = 0;
    while (scanf("%d%c ", &vstup, &c) != EOF) {

        if (i == 0)
        {
            if(j == 0){
                p1 = vstup;
                j++;
            }
            else
            {
                p2 = vstup;
                j = 0;
                for (int k = 1; k < 1 + p1; k++)
                {
                    for (int q = 1 + p1; q < 1 + p1 + p2; q++)
                    {
                        graph[k][q] = 1;
                    }
                }
                maxim = p1+p2+3;
            }
        }
        if (i == 1)
        {
            run_sum += vstup;
            graph[0][j+1] = vstup;
            j++;
        }

        if (i == 2)
        {
            graph[j+1][p1+p2+1] = vstup;
            j++;
        }

        if (c == '\n') {
            if (i == 2)
            {
                 printf("--------%d %d\n",run_sum , fordFulkerson(0, p1+p2+1));
                 i = -1;
                 run_sum = 0;
                 j = 0;
             for (int q = 0; q < p1+p2+2; q++)
             {
                for (int k = 0; k < p1+p2+2; k++)
                {
                    graph[k][q] = 0;
                }
                
             }
             
        }
        i ++;
    }


    }
    return 0;
}