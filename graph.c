#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"

Graph *graph_initialize()
{
    int i = 0;
    int j = 0;
    Graph *graph = malloc(sizeof(Graph));
    if (graph != NULL) //Checking if Graph is NULL.
    {                  // if the graph is not NULL initializaing it with -1.
        graph->max_vertex = 0;
        for (i = 0; i < MAX_VERTICES; i++)
        {
            for (j = 0; j < MAX_VERTICES; j++)
            {
                graph->adj_matrix[i][j] = -1;
            }
            graph->visited[i] = 0; // used the VISITED array to check vertex exists or not                                                       // not by using the
        }                          //hence initializing with 0
        return graph;
    }
    else
    {
        return NULL;
    }
}

int graph_add_vertex(Graph *graph, int v1)
{
    int i = 0;
    int j = 0;
    if (graph == NULL)
    {
        return -1;
    }
    if (v1 >= MAX_VERTICES || v1 < 0) // Checking if the eceived value in v1 i valid or not
    {
        return -1;
    }
    else
    {
        if (graph->visited[v1] == 1) //Condition to check if the vertex already exist or not
        {
            //vertex exists return 0
            return 0;
        }
        else
        {
            for (i = 0; i < MAX_VERTICES; i++)
            {
                graph->adj_matrix[i][v1] = 0; // Initializaing the rows with 0
            }
            for (j = 0; j < MAX_VERTICES; j++)
            {
                graph->adj_matrix[v1][j] = 0; // Initializing the Columns with 0
            }
            graph->visited[v1] = 1; // setting the vertex exist to 1
            return 0;
        }
    }
}

int graph_contains_vertex(Graph *graph, int v1)
{
    if (graph == NULL)
    {
        return 0;
    }
    if (graph->visited[v1] == 1) // if the value in the Vertex array is 1 then graph exists.
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int graph_remove_vertex(Graph *graph, int v1)
{
    int i = 0;
    int j = 0;
    if (graph == NULL)
    {
        return -1;
    }
    if (graph->visited[v1 == 0])
    {
        return 0;
    }
    else if (v1 > MAX_VERTICES || v1 < 0) // Checking for the validity of vertex.
    {
        return -1;
    }
    else
    {
        for (i = 0; i < v1; i++)
        {
            graph->adj_matrix[i][v1] = -1; //setting all the rows to -1
        }
        for (j = 0; j < v1; j++)
        {
            graph->adj_matrix[v1][j] = -1; // setting all the columns to -1
        }
        graph->visited[v1] = 0;
        return 0;
    }
}

int graph_add_edge(Graph *graph, int v1, int v2, int wt)
{
    if (graph == NULL)
    {
        return -1;
    }
    if (graph->visited[v1] == 0 || graph->visited[v2] == 0) // IF vertex 1 or vertex 2 does not exists its an error.
    {
        return -1;
    }
    else
    {
        graph->adj_matrix[v1][v2] = wt; // setting the edge Weight.
        return 0;
    }
}

int graph_contains_edge(Graph *graph, int v1, int v2)
{
    if (graph == NULL)
    {
        return 0;
    }
    if (graph->adj_matrix[v1][v2] > 0) //if in the generated 2 D Matrix there exist a values > 0 that means edge exists.
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int graph_remove_edge(Graph *graph, int v1, int v2)
{
    if (graph == NULL)
    {
        return -1;
    }
    if (graph->visited[v1] == 0 || graph->visited[v2] == 0)
    {
        return -1;
    }
    else
    {
        graph->adj_matrix[v1][v2] = 0; //setting the value at position v1,v2 to 0 will remove the edge.
        return 0;
    }
}

int graph_num_vertices(Graph *graph)
{
    int i = 0;
    int add = 0;
    for (i = 0; i < MAX_VERTICES; i++)
    {
        if (graph->visited[i] == 1)
        {
            add = add + 1; // Increment ADD with 1 for every Valid Vertex in visited array.
        }
    }
    return add;
}

int graph_num_edges(Graph *graph)
{
    int i = 0;
    int j = 0;
    int add = 0;
    if (graph == NULL)
    {
        return -1;
    }
    for (i = 0; i < MAX_VERTICES; i++)
    {
        for (j = 0; j < MAX_VERTICES; j++)
        {
            if (graph->adj_matrix[i][j] > 0)
            {
                add++; // iterating ADD with 1 whenever an edge is found at loc v1,v2.
            }
        }
    }
    return add;
}

int graph_total_weight(Graph *graph)
{
    int i = 0;
    int j = 0;
    int add = 0;
    if (graph == NULL)
    {
        return -1;
    }
    for (i = 0; i < MAX_VERTICES; i++)
    {
        for (j = 0; j < MAX_VERTICES; j++)
        {
            if (graph->adj_matrix[i][j] > 0)
            {
                add = add + graph->adj_matrix[i][j]; // Adding the weight found to the ADD.
            }
        }
    }
    return add;
}

int graph_get_degree(Graph *graph, int v1)
{
    int i = 0;
    int j = 0;
    int add = 0;
    if (graph == NULL)
    {
        return -1;
    }
    if (graph->visited[v1] == 0)
    {
        return -1;
    }
    else
    {
        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (graph->adj_matrix[i][v1] > 0)
            {
                add++; // Iterating ADD for out degree.
            }
        }
        for (j = 0; j < MAX_VERTICES; j++)
        {
            if (graph->adj_matrix[v1][j] > 0)
            {
                add++; // Iterating ADD for in degree.
            }
        }
        return add;
    }
}

int graph_get_edge_weight(Graph *graph, int v1, int v2)
{
    if (graph == NULL)
    {
        return -1;
    }
    if (graph->visited[v1] == 0 || graph->visited[v2] == 0)
    {
        return -1;
    }
    else
    {
        return (graph->adj_matrix[v1][v2]); // if v1 and v2 both are valid returning the value at v1,v2.
    }
}

int graph_is_neighbor(Graph *graph, int v1, int v2)
{
    if (graph == NULL)
    {
        return 0;
    }
    else if (graph->visited[v1] == 0 || graph->visited[v2] == 0)
    {
        return 0;
    }
    else if (graph->adj_matrix[v1][v2] > 0)
    {
        return 1; // if edge exist from v1 to v2
    }
    else if (graph->adj_matrix[v2][v1] > 0)
    {
        return 1; // if edge exist from v2,v1.
    }
    return 0;
}

int *graph_get_predecessors(Graph *graph, int v1)
{
    int i = 0;
    int k = 0;
    int *arra = malloc(sizeof(int) * MAX_VERTICES);
    if (arra == NULL)
    {
        return NULL;
    }
    else
    {
        if (graph->visited[v1] == 0)
        {
            for (i = 0; i < MAX_VERTICES; i++)
            {
                arra[i] = -1; // Initializing with -1.
            }
            for (i = 0; i < MAX_VERTICES; i++)
            {
                if (graph->adj_matrix[i][v1] > 0)
                {
                    arra[k] = i; // for every edge found put in array
                    k++;
                }
            }
            return arra;
        }
        else
        {
            return NULL;
        }
    }
}

int *graph_get_successors(Graph *graph, int v1)
{
    int j = 0;
    int k = 0;
    int i = 0;
    int *arras = malloc(sizeof(int) * MAX_VERTICES);
    if (arras == NULL)
    {
        return NULL;
    }
    if (graph == NULL)
    {
        return NULL;
    }
    else
    {
        for (i = 0; i < MAX_VERTICES; i++)
        {
            arras[i] = -1; // initialized to -1
        }
        for (j = 0; j < MAX_VERTICES; j++)
        {
            if (graph->adj_matrix[v1][j] > 0)
            {
                arras[k] = j; // for every value found put in array.
                k++;
            }
        }
        return arras;
    }
}

int graph_has_path(Graph *graph, int v1, int v2)
{
    int *ptr = graph_get_successors(graph, v1);
    int k = 0;
    int counter = 0;
    int arr[MAX_VERTICES * MAX_VERTICES] = {0};
    int VIS[MAX_VERTICES] = {0};
    if (graph == NULL)
    {
        return 0;
    }
    while (*(ptr + k) != -1)
    {
        arr[k] = *(ptr + k);
        VIS[arr[k]] = 1;
        if (VIS[v2] == 1)
        {
            return 1; // Putting value in Queue
        }
        k = k + 1;
    }
    while (arr[counter] != 0)
    {
        int j = 0;
        ptr = graph_get_successors(graph, arr[counter]);
        while (*(ptr + j) != -1) // while the value is not equal to -1 iterating the received array
        {
            if (VIS[*(ptr + j)] == 1)
            {
                j++;
                continue;
            }
            else
            {
                arr[k] = *(ptr + j);
                VIS[arr[k]] = 1; // Putting the values from received array to QUEUE if not already enqued.
                k++;
            }
            j++;
        }
        if (arr[counter] == v2)
        {
            return 1;
        }
        counter++;
    }

    return 0;
}

void graph_print(Graph *graph)
{ // Printing the graph on screen
    int i = 0;
    int j = 0;
    int counter = 0;
    int k = 0;
    printf("     ");
    while (i < MAX_VERTICES)
    {
        if (graph->visited[i] == 1)
        {
            printf("%d ", i);
            counter++;
        }
        i++;
    }
    printf("\n");
    printf("     ");
    while (k < MAX_VERTICES)
    {
        if (graph->visited[k] == 1)
        {
            if (k > 9)
            {
                printf("__ ");
            }
            else
            {
                printf("_ ");
            }
        }
        k++;
    }
    printf("\n");
    for (i = 0; i < MAX_VERTICES; i++)
    {
        if (graph->visited[i] == 1)
        {
            if (i > 9)
            {
                printf("%d  |", i);
            }
            else
            {
                printf("%d   |", i);
            }
            for (j = 0; j < MAX_VERTICES; j++)
            {
                if (graph->visited[j] == 1)
                {
                    if (j > 9)
                    {
                        printf("%d  ", graph->adj_matrix[i][j]);
                    }
                    else
                    {
                        printf("%d ", graph->adj_matrix[i][j]);
                    }
                }
            }
            printf("\n");
        }
        else
        {
            continue;
        }
    }
}

void graph_output_dot(Graph *graph, char *filename)
{ // Saving the graph in dot format.
    int i = 0;
    int j = 0;
    if (graph == NULL)
    {
        return;
    }
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        return;
    }
    fprintf(fp, "digraph {\n");
    for (i = 0; i < MAX_VERTICES; i++)
    {
        if (graph->visited[i] == 0)
        {
            continue;
        }
        else
        {
            fprintf(fp, "%d;\n", i);
            for (j = 0; j < MAX_VERTICES; j++)
            {
                if (graph->adj_matrix[i][j] > 0) // if the edge is greater than 0 then print from and to vertexs and edge.
                {
                    fprintf(fp, "%d -> %d [label = %d];\n", i, j, graph->adj_matrix[i][j]);
                }
                else
                {
                    continue;
                }
            }
        }
    }
    fprintf(fp, "}");
    fclose(fp);
}

int graph_load_file(Graph *graph, char *filename)
{
    char buffer[FILE_ENTRY_MAX_LEN];
    int v1 = 0;
    int v2 = 0;
    int edge = 0;
    int i = 0;
    int j = 0;
    char *a = NULL;
    FILE *fp = fopen(filename, "r"); // Loading from the given file name
    if (fp == NULL)
    {
        return -1;
    }
    if (graph == NULL)
    {
        return -1;
    }
    for (i = 0; i < MAX_VERTICES; i++)
    {
        for (j = 0; j < MAX_VERTICES; j++)
        {
            graph->adj_matrix[i][j] = -1;
        }
        graph->visited[i] = 0;      
    }
    while (feof(fp) == 0)
    { // using strtok to get the values from the file.
        fgets(buffer, FILE_ENTRY_MAX_LEN, fp);
        a = strtok(buffer, ",");
        sscanf(a, "%d", &v1);
        a = strtok(NULL, ",");
        if (a != NULL)
        {
            sscanf(a, "%d", &v2);
            a = strtok(NULL, ",");
            sscanf(a, "%d", &edge);
            if (graph->visited[v1] == 0) //if the vertex is not already present then create
            {
                graph_add_vertex(graph, v1);
            }
            if (graph->visited[v2] == 0)
            {
                graph_add_vertex(graph, v2);
            }
            graph_add_edge(graph, v1, v2, edge); // calling graph add edge to add the edge at v1,v2.
        }
        else
        {
            if (graph->visited[v1] == 0)
            {
                graph_add_vertex(graph, v1);
            }
        }
    }
    fclose(fp);
    return 0;
}

int graph_save_file(Graph *graph, char *filename)
{ // Saving the graph file in the format as load
    int i, j, k;
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        return -1;
    }
    if (graph == NULL)
    {
        return -1;
    }
    for (i = 0; i < MAX_VERTICES; i++)
    {
        if (graph->visited[i] == 0)
        {
            continue;
        }
        else
        {
            j = 0;
            k = j;
            for (j = 0; j < MAX_VERTICES; j++)
            {
                if (graph->adj_matrix[i][j] > 0) // if edge exists then print  both vertex and the edge
                {
                    fprintf(fp, "%d,%d,%d\n", i, j, graph->adj_matrix[i][j]);
                }
                else if (graph->adj_matrix[i][j] <= 0)
                {
                    k++;
                    continue;
                }
            }
            if (k == j)
            {
                fprintf(fp, "%d\n", i);
            }
        }
    }
    fclose(fp); //Closing the file when done.
    return 0;
}
