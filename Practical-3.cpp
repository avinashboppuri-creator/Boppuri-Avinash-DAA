#include <iostream>
#include <chrono>

using namespace std;

unsigned long long iterativeFactorial(int number)
{
    unsigned long long answer = 1;

    for (int i = 2; i <= number; i++)
    {
        answer = answer * i;
    }

    return answer;
}

unsigned long long recursiveFactorial(int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }

    return number * recursiveFactorial(number - 1);
}

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (number < 0)
    {
        cout << "Please enter a non-negative number." << endl;
        return 1;
    }


    auto begin1 = chrono::high_resolution_clock::now();

    unsigned long long iterativeAnswer = iterativeFactorial(number);

  
    auto finish1 = chrono::high_resolution_clock::now();

    
    auto begin2 = chrono::high_resolution_clock::now();

    unsigned long long recursiveAnswer = recursiveFactorial(number);

    
    auto finish2 = chrono::high_resolution_clock::now();

    auto iterativeTime =
        chrono::duration_cast<chrono::nanoseconds>
        (finish1 - begin1).count();

    auto recursiveTime =
        chrono::duration_cast<chrono::nanoseconds>
        (finish2 - begin2).count();

    cout << "\n===== Factorial Results =====" << endl;

    cout << "Factorial using loop      : "
         << iterativeAnswer << endl;

    cout << "Time using loop           : "
         << iterativeTime << " ns" << endl;

    cout << "\nFactorial using recursion : "
         << recursiveAnswer << endl;

    cout << "Time using recursion      : "
         << recursiveTime << " ns" << endl;

    return 0;
}
