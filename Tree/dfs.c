#include <stdio.h>
#include <stdlib.h>

struct node{
    int ve;
    struct node *next;
};

struct node *createNode(int v);

struct gr{
    int num;
    int *visited;
    struct node **adjLists;
};

// DFS algo
void DFS(struct gr *gr, int ve){
    struct node *adjList = gr->adjLists[ve];
    struct node *temp = adjList;

    gr->visited[ve] = 1;
    printf("Visited %d \n", ve);

    while (temp != NULL)
    {
        int connectedve = temp->ve;

        if (gr->visited[connectedve] == 0)
        {
            DFS(gr, connectedve);
        }
        temp = temp->next;
    }
}

// Create a node
struct node *createNode(int v){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->ve = v;
    newNode->next = NULL;
    return newNode;
}

// Create gr
struct gr *createGraph(int vertices){
    struct gr *gr = malloc(sizeof(struct gr));
    gr->num = vertices;

    gr->adjLists = malloc(vertices * sizeof(struct node *));

    gr->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        gr->adjLists[i] = NULL;
        gr->visited[i] = 0;
    }
    return gr;
}

// Add edge
void addEdge(struct gr *gr, int src, int dest){
    struct node *newNode = createNode(dest);
    newNode->next = gr->adjLists[src];
    gr->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = gr->adjLists[dest];
    gr->adjLists[dest] = newNode;
}

// Print the gr
void printGraph(struct gr *gr){
    int v;
    for (v = 0; v < gr->num; v++)
    {
        struct node *temp = gr->adjLists[v];
        printf("\n Adjacency list of ve %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->ve);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct gr *gr = createGraph(4);
    addEdge(gr, 0, 1);
    addEdge(gr, 0, 2);
    addEdge(gr, 1, 2);
    addEdge(gr, 2, 3);
    printGraph(gr);
    DFS(gr, 2);
    return 0;
}