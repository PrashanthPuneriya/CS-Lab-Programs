#include<iostream>
using namespace std;

void Merge (int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;   //index is counted from 0. Hence, + 1
    int n2 = right - mid;
    int i, j, k;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; 
            i++;
        }
        else {
            arr[k] = R[j]; 
            j++;
        }
        k++;
    }
    /* Copy the remaining elements of L[] and R[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void MergeSort (int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort (arr, left, mid);
        MergeSort (arr, mid + 1, right);
        // merge the both parts by comparing elements of both the parts.
        Merge (arr, left, mid, right);
    }                    
}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    cout<<"Given array is:\n";
    printArray(arr, arr_size); 
  
    MergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
}