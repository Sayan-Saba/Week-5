#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return (i + 1);
}

// Implemented iterative algorithm for quicksort
void itrQuickSort(int arr[], int left, int right)
{

    vector<pair<int, int>> stack;
    stack.push_back({left, right});
    while (!stack.empty())
    {
        pair<int, int> top = stack.back();
        stack.pop_back();
        int low = top.first, high = top.second;
        if (low < high)
        {
            int pivotIndex = partition(arr, low, high);
            stack.push_back({low, pivotIndex - 1});
            stack.push_back({pivotIndex + 1, high});
        }
    }
}
int main()
{
    int size;
    cout << "total elements in array:";
    cin >> size;

    int arr[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
    auto startTime = chrono::high_resolution_clock::now();
    itrQuickSort(arr, 0, (size - 1));
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

    cout << "time taken for iterative is " << duration << endl;

    return 0;
}