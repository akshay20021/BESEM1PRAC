#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Function to partition the array
int partition(int arr[], int start, int end) {
int pivot = arr[end];
int i = (start - 1);
for (int j = start; j <= end - 1; j++) {
if (arr[j] <= pivot) {
i++;
swap(arr[i], arr[j]);
}
}
swap(arr[i + 1], arr[end]);
return (i + 1);
}
// Function to choose a random pivot
int randomPartition(int arr[], int start, int end) {
srand(time(0)); // Seed the random number generator
int randomIndex = start + rand() % (end - start + 1);
swap(arr[randomIndex], arr[end]);
return partition(arr, start, end);
}
// Randomized QuickSort
void randomizedQuickSort(int arr[], int start, int end) {
if (start < end) {
int pivotIndex = randomPartition(arr, start, end);
randomizedQuickSort(arr, start, pivotIndex - 1);
randomizedQuickSort(arr, pivotIndex + 1, end);
}
}
// Deterministic QuickSort using the median-of-three pivot selection
void deterministicQuickSort(int arr[], int start, int end) {
if (start < end) {
int mid = (start + end) / 2;
// Find the median of three: arr[start], arr[mid], and arr[end]
if (arr[start] > arr[mid])
swap(arr[start], arr[mid]);
if (arr[start] > arr[end])
swap(arr[start], arr[end]);
if (arr[mid] > arr[end])
swap(arr[mid], arr[end]);
int pivotIndex = partition(arr, start, end);
deterministicQuickSort(arr, start, pivotIndex - 1);
deterministicQuickSort(arr, pivotIndex + 1, end);
}
}
int main() {
int n;
cout << "Enter the number of elements in the array: ";
cin >> n;
int arr1[n], arr2[n];
cout << "Enter elements:" << endl;
for (int i = 0; i < n; i++) {
cin >> arr1[i];
arr2[i] = arr1[i];
}
cout << "Before sorting, the array elements are:" << endl;
for (int i = 0; i < n; i++) {
cout << arr1[i] << " ";
}
cout << endl;
randomizedQuickSort(arr1, 0, n - 1);
cout << "After Randomized QuickSort, the array elements are:" << endl;
for (int i = 0; i < n; i++) {
cout << arr1[i] << " ";
}
cout << endl;
deterministicQuickSort(arr2, 0, n - 1);
cout << "After Deterministic QuickSort, the array elements are:" << endl;
for (int i = 0; i < n; i++) {
cout << arr2[i] << " ";
}
cout << endl;
return 0;
}