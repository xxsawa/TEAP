#include <stdio.h>
#include <stdlib.h>
 
// Define the maximum number of vertices in the graph
#define N 1000



int sucet = 0;
int kde_ideme;

int running_sum = 0;

int max_price = 0;
int sub = 0;

int a;
int b;
// Data structure to store a graph object
struct Graph
{
    // An array of pointers to Node to represent an adjacency list
    struct Node* head[N];
};
 
// Data structure to store adjacency list nodes of the graph
struct Node
{
    int price;
    int reverse_price;
    int dest;
    struct Node* next;
};
 
struct Node *max_way[4];

struct Edge {
    int src, dest, price;
};

struct Edge getEdge(int src,int dest,int price){
    struct Edge new;
    new.dest = dest;
    new.src = src;
    new.price = price;
    return new;
}

struct Graph* createGraph(struct Edge edges[], int n)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {

        int src = edges[i].src;
        int dest = edges[i].dest;
        int price = edges[i].price;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->price = price;
        newNode->reverse_price = 0;
        newNode->next = graph->head[src];
        graph->head[src] = newNode;
    }
 
    return graph;
}
 

int depth_first(struct Graph* graph, struct Node* ptr){

    struct Node *temp1;
    int best = 0;

    for (int i = 0; i < a; i++)
    {
        if (ptr->price>best)
        {
            temp1 = ptr;
            best = ptr->price;
        }
        ptr = ptr->next;
    }

    if (best == 0)
    {
        return;
    }
    
    struct Node *temp2;
    int destination;
    best = 0;
    ptr = graph->head[temp1->dest];
    for (int i = 0; i < b; i++)
    {
        if (graph->head[ptr->dest]->price>best && ptr->price>0)
        {
            temp2 = ptr;
            best = graph->head[ptr->dest]->price;
            destination = ptr->dest;
        }
        ptr = ptr->next;
    }
    if (best == 0)
    {
        return;
    }
    printf("%d %d %d \n", temp1->price ,temp2->price, graph->head[destination]->price);
    temp1->price--;
    temp2->price--;
    graph->head[destination]->price--;
    sucet++;
}


void printGraph(struct Graph* graph)
{
    for (int i = 0; i < kde_ideme; i++)
    {
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d $%d)\t", i, ptr->dest,ptr->price);
            
            ptr = ptr->next;
        }
 
        printf("\n");
    }
}



int main(void)
{

    

    while (scanf("%d",&a) != EOF)
    {
        scanf("%d",&b);

        struct Edge edges[5000];

        int nedavam_to[100];
        int nedavam_tot[100];

        int vstup;
        int pocitam = 0;


        int n = a+b;
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
                edges[k] = getEdge(0,i+1,nedavam_to[i]);
                k++;
                for (int j = 0; j < b; j++)
                {
                    edges[k] = getEdge(i+1,a+j+1,1);
                    k++;
                }
                
            }
            else
            {
                edges[k] = getEdge(i+1,a+b+1,nedavam_tot[i-a]);
                k++;
            }
        }
        // construct a graph from the given edges
        struct Graph *graph = createGraph(edges, a+b+a*b);
    
        // Function to print adjacency list representation of a graph

        //

        for (int i = 0; i < a+b+a*b; i++)
        {
            
            struct Node *da_waey[4];
            depth_first(graph,graph->head[0]);
            

        }

















        //
        
        printf("-----%d\n", running_sum <= sucet);
        sucet = 0;
        running_sum = 0;
        printGraph(graph);

    } 
    return 0;
}
