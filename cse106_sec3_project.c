#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define n 5000

int matrix[n][n];

int main()
{

    int edge_count = 0, degree_count = 0, option, vertice;

    printf("\n");
    printf("Array size: %d\n", n);
    printf("Number of the vertices: ");
    scanf("%d", &vertice);

    double timeSpent = 0.0;

    srand(time(0));

    // initialize the graph values to 0
    for (int i = 0; i < vertice; i++)
    {
        for (int j = 0; j < vertice; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // create the graph randomly
    for (int i = 0; i < vertice; i++)
    {
        for (int j = 0; j < vertice; j++)
        {
            matrix[i][j] = matrix[j][i] = rand() % 2;
        }
    }

    clock_t begin = clock();

    // counting the edge
    for (int i = 0; i < vertice; i++)
    {
        for (int j = 0; j < vertice; j++)
        {
            if (matrix[i][j] == 1 && i < j)
            {
                edge_count++;
            }

            if (matrix[i][j] == 1 && i == j)
            {
                edge_count++;
            }
        }
    }

    // counting the degree
    for (int i = 0; i < vertice; i++)
    {
        for (int j = 0; j < vertice; j++)
        {
            if (matrix[i][j] == 1)
            {
                degree_count++;
            }

            if (matrix[i][j] == 1 && i == j)
            {
                degree_count++;
            }
        }
    }

    printf("number of edge: %d\n", edge_count);
    printf("number of degree: %d\n", degree_count);
    printf("does the handshaking theorem hold?\n");
    bool handshake = (degree_count % edge_count == 0);
    if (handshake == 1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    clock_t end = clock();
    timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("execution time: %lf ms\n", timeSpent * 1000);

    printf("print the graph?\n");
    printf("1. Yes\n");
    printf("2. no\n");
    printf("Select option: ");
    scanf("%d", &option);

    if (option == 1)
    {
        // printing the graph
        printf("Here is the graph\n");

        for (int i = 0; i < vertice; i++)
        {
            for (int j = 0; j < vertice; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        exit;
    }

    return 0;
}
