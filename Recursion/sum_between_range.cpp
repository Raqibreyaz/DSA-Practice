#include <iostream>
#include<time.h>
using namespace std;

void printArray(auto array[], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// this function will caluclate sum between a range in an array recursively
int giveSumBetweenRange(int *array, int a, int b)
{
    if (a > b)
        return 0;

    int midIndex = (a + b) / 2;

    int leftSum = giveSumBetweenRange(array, a, midIndex - 1);
    int rightSum = giveSumBetweenRange(array, midIndex + 1, b);

    return leftSum + array[midIndex] + rightSum;
}

int highOrderFn(int fn(int *array, int a, int b), int *array, int a, int b)
{
    return fn(array, a, b);
}

int main()
{
    int array[] = {4, 5, 2, 3, 7, 8, 1};
    int a, b;
    int array_size = sizeof(array) / sizeof(int);

    printArray(array, array_size);
    cout << "Enter range as a & b" << endl
         << "a ";
    cin >> a;
    cout << "b ";
    cin >> b;

    int sum = giveSumBetweenRange(array, a, b);
    cout << "sum between " << a << " & " << b << " is " << sum << endl;

    return 0;
}
