#include <stdio.h>

int graph[20][20], visited[20];
int n;

void DFS(int v)
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    int queue[20];
    int front = 0, rear = 0;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int i, j, start, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Enter vertices between 1 and 20.\n");
        return 0;
    }

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex!\n");
        return 0;
    }

    printf("\n1. Depth First Search (DFS)");
    printf("\n2. Breadth First Search (BFS)");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    if (choice == 1)
    {
        printf("\nDFS Traversal: ");
        DFS(start);
    }
    else if (choice == 2)
    {
        printf("\nBFS Traversal: ");
        BFS(start);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    printf("\n");
    return 0;
}
