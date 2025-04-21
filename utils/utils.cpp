#include <iostream>
#include <vector>
void printVector(std::vector<int> &v)
{
    for (auto &element : v)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}