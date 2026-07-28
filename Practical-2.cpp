#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int linear_search(const vector<int>& numbers, int value)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == value)
        {
            return i;
        }
    }

    return -1;
}

int binary_search(const vector<int>& numbers, int value)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (numbers[middle] == value)
        {
            return middle;
        }

        if (numbers[middle] < value)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;
}

int main()
{
    const int SIZE = 100000;
    vector<int> numbers;

    for (int i = 1; i <= SIZE; i++)
    {
        numbers.push_back(i);
    }

    int value;
    cout << "Enter the number you want to find: ";
    cin >> value;

    // Measuring Linear Search
    auto startLinear = chrono::high_resolution_clock::now();

    int resultLinear = linear_search(numbers, value);

    auto endLinear = chrono::high_resolution_clock::now();

    auto linearTime =
        chrono::duration_cast<chrono::microseconds>
        (endLinear - startLinear).count();

    cout << "\n--- Linear Search ---\n";

    if (resultLinear >= 0)
        cout << "Number found at index: " << resultLinear << endl;
    else
        cout << "Number was not found." << endl;

    cout << "Execution time: " << linearTime << " microseconds\n";


    // Measuring Binary Search
    auto startBinary = chrono::high_resolution_clock::now();

    int resultBinary = binary_search(numbers, value);

    auto endBinary = chrono::high_resolution_clock::now();

    auto binaryTime =
        chrono::duration_cast<chrono::microseconds>
        (endBinary - startBinary).count();

    cout << "\n--- Binary Search ---\n";

    if (resultBinary >= 0)
        cout << "Number found at index: " << resultBinary << endl;
    else
        cout << "Number was not found." << endl;

    cout << "Execution time: " << binaryTime << " microseconds\n";

    return 0;
}
