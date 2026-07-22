#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

// Insertion Sort
void insertionSort(vector<int> &a)
{
    int n = a.size();

    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > current)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = current;
    }
}

// Merge Function
void merge(vector<int> &a, int left, int mid, int right)
{
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (a[i] < a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(a[j]);
        j++;
    }

    for (int k = left; k <= right; k++)
    {
        a[k] = temp[k - left];
    }
}

void mergeSort(vector<int> &a, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

// Partition Function
int partition(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(a, low, high);

        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}

int main()
{
    int n = 100;

    vector<int> numbers(n);
    vector<int> copy;

    srand(time(0));

    // Generate random numbers
    for (int i = 0; i < n; i++)
    {
        numbers[i] = rand() % 1000;
    }

    cout << "Total Elements : " << n << endl << endl;

    auto start = high_resolution_clock::now();
    copy = numbers;
    bubbleSort(copy);
    auto end = high_resolution_clock::now();
    cout << "Bubble Sort    : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    copy = numbers;
    selectionSort(copy);
    end = high_resolution_clock::now();
    cout << "Selection Sort : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    copy = numbers;
    insertionSort(copy);
    end = high_resolution_clock::now();
    cout << "Insertion Sort : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    copy = numbers;
    mergeSort(copy, 0, n - 1);
    end = high_resolution_clock::now();
    cout << "Merge Sort     : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    copy = numbers;
    quickSort(copy, 0, n - 1);
    end = high_resolution_clock::now();
    cout << "Quick Sort     : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    return 0;
}