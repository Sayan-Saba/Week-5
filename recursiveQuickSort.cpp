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

void recQuickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivotID = partition(arr, left, right);
        recQuickSort(arr, left, pivotID - 1);
        recQuickSort(arr, pivotID + 1, right);
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

    auto startTime1 = chrono::high_resolution_clock::now();
    recQuickSort(arr, 0, (size - 1));
    auto endTime1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(endTime1 - startTime1).count();

    cout << "time taken for recursive is " << duration1 << endl;
    return 0;
}