#include <stdio.h>
#include <stdlib.h>

#define SINK (2*a + b + c + 1)


typedef struct node {
    int data;
    struct node* next;
} node;

int array[450][450];
int a, b, c;
node* queue = NULL;

void queue_add(int data) {
    if (queue == NULL) {
        queue = (node*) malloc(sizeof(node));
        queue->next = NULL;
        queue->data = data;
        return;
    }
    node* new_node = (node*) malloc(sizeof(node));
    new_node->next = queue;
    new_node->data = data;
    queue = new_node;
}

int queue_pop() {
    node* old = queue;
    int data = queue->data;
    queue = queue->next;
    free(old);
    return data;
}

int bfs(int* parent) {
    int visited[450];
    for (int i = 0; i < SINK + 1; i++) {
        visited[i] = 0;
    }
    queue = NULL;
    queue_add(0);
    visited[0] = 1;
    while (queue != NULL) {
        int u = queue_pop();
        for (int i = 0; i < SINK + 1; i++) {
            if (array[u][i] > 0 && !visited[i]) {
                parent[i] = u;
                visited[i] = 1;
                if (i == SINK) {
                    return 1;
                }
                queue_add(i);
            }
        }
    }
    return 0;
}



int main() {
    
    int voda;

    int jedlo[90];
    while (scanf("%d", &a) != EOF) {
        memset(array, 0, sizeof(array));

        scanf("%d", &b);

        scanf("%d", &c);
        
        for (int i = 0; i < b; i++) {
            array[0][i + 1] = 1;
        }

        for (int i = 0; i < a; i++) {
            array[i+1+b][i+1+b+a] = 1;
            int p1,p2;

            scanf("%d", &p1);
            scanf("%d", &p2);

            for (int j = 0; j < p1; j++) {
                scanf("%d", jedlo + j);
                array[jedlo[j]][b + i + 1] = 1;
            }
            for (int j = 0; j < p2; j++) {
                scanf("%d", &voda);
                array[i+1+a+b][2*a+b+voda] = 1;   
            }
        }
        for (int i = 0; i < c; i++) {
            array[2*a + b + i + 1][SINK] = 1;
        }


        int flow = 0;
        int arr2[450]; 
        
        for (int i = 0; i < SINK + 1; i++) {
            arr2[i] = -1;
        }
        while (bfs(arr2)) {
            int pocitadlo =SINK;
            flow += 1;
            while (pocitadlo != 0) {

                int prem = arr2[pocitadlo];
                array[prem][pocitadlo] = 0;
                array[pocitadlo][prem] = 1;
                pocitadlo = arr2[pocitadlo];
            }
        }
        printf("%d\n", flow);
    }

    return 0;
}