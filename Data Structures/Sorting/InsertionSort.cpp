//Insertion sort(Playing Cards):
//Insert each element into its correct position of the sorted array
#include<iostream>
using namespace std;
void InsertionSort(int arr[], int n) {
    int i, j, value;
    for (i = 1; i < n; i++) { // i=1 since single element is already sorted.
        value = arr[i];
        j = i;
        /* Move the elements of sorted array which are greater than the value, 
        to one position ahead of their current position */
        while (j > 0 && arr[j-1] > value) {
            arr[j] = arr[j-1];
            j = j - 1;
        }  
        arr[j] = value;
    }  
}
int main() {
	int arr[] = {5, 3, 3, 2, 1, 4};
	InsertionSort(arr, 6);
	for(int i=0; i<6; i++)
        cout<<arr[i];
    return 0;
}