#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 300

int sucet = 0;


int a;
int b;
int c;

struct edge {
    int source;
    int destination;
};

struct node {
    int value;
    int constant_out;
    int constant_in;
    int in_degree_count;
    int out_degree_count;
    int obsadene;
    struct edge edges[MAX_NODES];
    struct edge edges_in[MAX_NODES];
};

struct graph {
    struct node nodes[MAX_NODES];
    int node_count;
};

void add_node(struct graph* g, int value) {
    if (g->node_count < MAX_NODES) {
        struct node n = { value, 0 ,0};
        g->nodes[g->node_count++] = n;
    } else {
        printf("Error: Maximum number of nodes reached!\n");
    }
}

void add_edge(struct graph* g, int source, int destination) {
    for (int i = 0; i < g->nodes[source].out_degree_count; i++)
    {
        if (g->nodes[source].edges[i].destination == destination)
        {
            return;
        }
        
        
        
    }
    

    struct edge e = { source, destination };
    g->nodes[source].edges[g->nodes[source].out_degree_count++] = e;
    g->nodes[source].constant_out++;
    g->nodes[destination].edges_in[g->nodes[destination].in_degree_count++] = e;
    g->nodes[destination].constant_in++;
    g->nodes[source].obsadene = 0;

}

void print_in_degree_counts(struct graph* g) {
    for (int i = 0; i < g->node_count; i++) {
        printf("%d    in %d   out %d\n", g->nodes[i].value, g->nodes[i].in_degree_count, g->nodes[i].out_degree_count);
    }
}

void print_stuff(struct graph* g){
    int starting_node;

    int minimal_out_node;
    int minimal_out_count = 1000;

    for (int i = a+1; i <= a+b+1; i++)
    {
        printf("node cislo:%d  out:%d  obsadene:%d\n",i,g->nodes[i].out_degree_count,g->nodes[i].obsadene);
        if (g->nodes[i].out_degree_count < minimal_out_count && g->nodes[i].obsadene == 0 && g->nodes[i].out_degree_count > 0)
        {
            minimal_out_count = g->nodes[i].out_degree_count;
            minimal_out_node = i;
        }
        
        
    }
    starting_node = minimal_out_node;
    printf("start_node:%d\n",starting_node);

    if (g->nodes[starting_node].out_degree_count == 0 || minimal_out_count == 1000)
    {
        return;
    }
    printf("aktualny node ->>>>>>>>>>>> %d   out:%d\n",starting_node , g->nodes[starting_node].out_degree_count);

    
    int minimal_in_count = 1000;
    int minimal_in_node;
    for (int i = 0; i < g->nodes[starting_node].constant_out; i++)
    {
        printf("%d in:%d  osadene:%d \n",g->nodes[starting_node].edges[i].destination ,g->nodes[g->nodes[starting_node].edges[i].destination].in_degree_count, g->nodes[g->nodes[starting_node].edges[i].destination].obsadene);
        if (g->nodes[g->nodes[starting_node].edges[i].destination].in_degree_count < minimal_in_count && g->nodes[g->nodes[starting_node].edges[i].destination].obsadene == 0)
        {
            minimal_in_count = g->nodes[g->nodes[starting_node].edges[i].destination].in_degree_count;
            minimal_in_node = g->nodes[starting_node].edges[i].destination;
        }
        
    }
    if (minimal_in_count == 1000)
    {
        return;
    }
    printf("aktualny node ->>>>>>>>>>>> %d out:%d\n",minimal_in_node,g->nodes[minimal_in_node].out_degree_count);


    minimal_in_count = 1000;
    int minimal_in_node_2;
    int zaloha1 = NULL;
    int zaloha2 = NULL;
    
    for (int i = 0; i < g->nodes[minimal_in_node].constant_out; i++)
    {
        printf("%d in:%d  osadene:%d \n",g->nodes[minimal_in_node].edges[i].destination ,g->nodes[g->nodes[minimal_in_node].edges[i].destination].in_degree_count, g->nodes[g->nodes[minimal_in_node].edges[i].destination].obsadene);
        if (g->nodes[g->nodes[minimal_in_node].edges[i].destination].in_degree_count < minimal_in_count && g->nodes[g->nodes[minimal_in_node].edges[i].destination].obsadene == 0)
        {

            int skip = 0;
            for (int j = 0; j < g->nodes[g->nodes[minimal_in_node].edges[i].destination].constant_in; j++)
            {
                printf("---------------- %d\n",g->nodes[g->nodes[g->nodes[minimal_in_node].edges[i].destination].edges_in[j].source].out_degree_count);
                if (g->nodes[g->nodes[g->nodes[minimal_in_node].edges[i].destination].edges_in[j].source].out_degree_count == 1)
                {
                    zaloha1 = g->nodes[g->nodes[minimal_in_node].edges[i].destination].in_degree_count;
                    zaloha2 = g->nodes[minimal_in_node].edges[i].destination;
                    skip = 1;
                    break;;
                }
            }
            if (skip)
            {
                continue;
            }
            

            
            minimal_in_count = g->nodes[g->nodes[minimal_in_node].edges[i].destination].in_degree_count;
            minimal_in_node_2 = g->nodes[minimal_in_node].edges[i].destination;
        }
    }
    if (minimal_in_count == 1000)
    {
        if (zaloha1 && zaloha2)
        {
            minimal_in_count = zaloha1;
            minimal_in_node_2= zaloha2;
        }
        else
        {
            return;
        }
    }
    printf("aktualny node ->>>>>>>>>>>> %d   out:%d\n",minimal_in_node_2 , g->nodes[minimal_in_node_2].out_degree_count);
    
    //printf("\n");
    int i;
    for (i = 0; i < g->nodes[starting_node].constant_out; i++)
    {
        printf("odstranujeme outgoing nody: %d   \n",g->nodes[starting_node].edges[i].destination);
        g->nodes[g->nodes[starting_node].edges[i].destination].in_degree_count--;

    }
    
    g->nodes[starting_node].out_degree_count-= i;

    for (i = 0; i < g->nodes[minimal_in_node].constant_out; i++)
    {
        printf("$odstranujeme outgoing nody: %d   \n",g->nodes[minimal_in_node].edges[i].destination);
        g->nodes[g->nodes[minimal_in_node].edges[i].destination].in_degree_count--;
    }
    g->nodes[minimal_in_node].out_degree_count -= i;


    int j = 0;
    for (int i = 0; i < g->nodes[minimal_in_node].constant_in; i++)
    {
        printf(">odstranujeme origin nody: %d    %d\n",g->nodes[minimal_in_node].edges_in[i].source,starting_node);
        if (g->nodes[minimal_in_node].edges[i].source != starting_node)
        {
            g->nodes[g->nodes[minimal_in_node].edges_in[i].source].out_degree_count--;
            j++;
        }
        
    }
    g->nodes[minimal_in_node].in_degree_count -= j;
    j = 0;
    for (int i = 0; i < g->nodes[minimal_in_node_2].constant_in; i++)
    {
        printf("-odstranujeme origin nody: %d    %d\n",g->nodes[minimal_in_node_2].edges_in[i].source,g->nodes[g->nodes[minimal_in_node_2].edges_in[i].source].value);
        if (g->nodes[minimal_in_node_2].edges_in[i].source != minimal_in_node)
        {
            g->nodes[g->nodes[minimal_in_node_2].edges_in[i].source].out_degree_count--;
            j++;
        }
        
        
    }
    g->nodes[minimal_in_node_2].in_degree_count-= j;
    g->nodes[minimal_in_node].obsadene++;
    g->nodes[minimal_in_node_2].obsadene++;
    g->nodes[minimal_out_node].obsadene++;
    sucet++;
}

int main() {




    while (scanf("%d",&a) != EOF)
    {        
        struct graph g;
        g.node_count = 0;
        scanf("%d",&b);
        
        scanf("%d",&c);


        for (int i = 0; i <= a+b+c; i++)
        {
            add_node(&g, i);
           // printf("%d\n",i);
        }


        for (int i = 1; i <= a; i++)
        {
            int p1,p2;
            scanf("%d",&p1);
            scanf("%d",&p2);

            for (int j = 0; j < p1; j++)
            {
                int vstup;
                scanf("%d",&vstup);
                //printf("add_edge(&g, %d + %d, %d)\n",b,vstup,i);
                add_edge(&g, a + vstup, i);
            }
            for (int j = 0; j < p2; j++)
            {
                int vstup;
                scanf("%d",&vstup);
                //printf("add_edge(&g, %d, %d + %d)\n",a+b,i,vstup);
                add_edge(&g, i, a+b + vstup);

            }
            
        }
        for (int i = 0; i < a; i++)
        {        
            print_stuff(&g);
            //print_in_degree_counts(&g);
        }
        printf("%d\n",sucet);
        sucet = 0;
    }

    return 0;
}