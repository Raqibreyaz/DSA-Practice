#include <iostream>
using namespace std;

int binary_search(int *array, int key, int low, int high)
{

    cout << array << endl;
    int mid = (low + high) / 2;

    if (low > high)
        return -1;

    // checking if we found the element
    if (array[mid] == key)
    {
        return mid;
    }
    // when key is in right part of array then go to right part
    else if (array[mid] < key)
    {
        return binary_search(array, key, mid + 1, high);
    }
    // when key is in left part then go to left part
    else
    {
        return binary_search(array, key, low, mid - 1);
    }

    return 5;
};

void printArray(auto array[], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{

    int array[] = {2, 4, 7, 8, 9, 10, 11};
    int array_size = sizeof(array) / sizeof(int);

    printArray(array, array_size);

    int key;
    cout << "Enter a key to search ";
    cin >> key;

    int index = binary_search(array, key, 0, array_size - 1);
    cout << "Key found at " << index << endl;

    return 0;
}
