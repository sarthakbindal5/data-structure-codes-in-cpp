//HEAP SORT USING HEAPIFY METHOD IMPLEMENTATION
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1, r = 2*i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest); // Repair affected tree using recursive heapify method
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--) // Deletion part of heap sort
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
    int n;
	cout << "Enter number of elements to be entered: ";
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
	    cout << "Enter number " << i+1 << ": ";
	    cin >> arr[i];
	}
	heapSort(arr, n);
	
	cout << "Sorted array using heap sort is:\n";
	printArray(arr, n);
	return 0;
}