#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 200
#define INF 1000000000
#define min(a, b) ((a) < (b) ? (a) : (b))

int n; // number of nodes
int c[MAX_NODES][MAX_NODES]; // capacity matrix
int f[MAX_NODES][MAX_NODES]; // flow matrix
int d[MAX_NODES]; // distance array
int p[MAX_NODES]; // parent array

int kde_ideme;
int running_sum = 0;

// Breadth-first search to find the shortest augmenting path
bool bfs(int s, int t) {
    memset(d, -1, sizeof(d));
    d[s] = 0;
    p[s] = -1;
    int q[MAX_NODES];
    int front = 0, rear = 0;
    q[rear++] = s;
    while (front < rear) {
        int u = q[front++];
        for (int v = 0; v < n; v++) {
            if (d[v] == -1 && f[u][v] < c[u][v]) {
                d[v] = d[u] + 1;
                p[v] = u;
                q[rear++] = v;
            }
        }
    }
    return d[t] != -1;
}

// Augment flow along the shortest augmenting path
int dfs(int u, int t, int flow) {
    if (u == t) return flow;
    for (int v = 0; v < n; v++) {
        if (f[u][v] < c[u][v] && d[v] == d[u] + 1) {
            int df = dfs(v, t, min(flow, c[u][v] - f[u][v]));
            if (df > 0) {
                f[u][v] += df;
                f[v][u] -= df;
                return df;
            }
        }
    }
    return 0;
}

// Compute the maximum flow from s to t using the Edmonds-Karp algorithm
int edmonds_karp(int s, int t) {
    int max_flow = 0;
    while (bfs(s, t)) {
        int flow;
        do {
            flow = dfs(s, t, INF);
            max_flow += flow;
        } while (flow > 0);
    }
    return max_flow;
}

int main() {
    // Read input and initialize capacity matrix
    int a;
    int b;
    while (scanf("%d",&a) != EOF)
    {

        scanf("%d",&b);
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));


        int nedavam_to[100];
        int nedavam_tot[100];

        int vstup;
        int pocitam = 0;


        n = a+b;
        kde_ideme = n+1;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vstup);
            if (i < a)
            {
                running_sum += vstup;
                nedavam_to[i] = vstup;
            }
            else
            {                
                nedavam_tot[i-a] = vstup;
            }
        }


        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < a)
            {
                c[0][i+1] += nedavam_to[i];
                for (int j = 0; j < b; j++)
                {
                    c[i+1][a+j+1] += 1;
                }
                
            }
            else
            {
                c[i+1][a+b+1] += nedavam_tot[i-a];
            }
        }
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                printf("%d",c[i][j]);
            }
            printf("\n");
        }
    
        printf("%d\n", edmonds_karp(0, n-1));
    }

    // Compute and print the maximum flow from node 0 to node n-1
    
    return 0;
}