#include <stdio.h>

void maxHeapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        maxHeapify(a, n, largest);
    }
}

void minHeapify(int a[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i)
    {
        temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;

        minHeapify(a, n, smallest);
    }
}

void maxHeapSort(int a[], int n)
{
    int i, temp;

  
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        maxHeapify(a, i, 0);
    }
}

void minHeapSort(int a[], int n)
{
    int i, temp;

    
    for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        minHeapify(a, i, 0);
    }

    
    for (i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

void display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[100], b[100];
    int n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Please enter between 1 and 100 elements.\n");
        return 0;
    }

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    printf("\n1. Max Heap Sort");
    printf("\n2. Min Heap Sort");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        maxHeapSort(a, n);
        printf("\nSorted array using Max Heap Sort:\n");
        display(a, n);
    }
    else if (choice == 2)
    {
        minHeapSort(b, n);
        printf("\nSorted array using Min Heap Sort:\n");
        display(b, n);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}
