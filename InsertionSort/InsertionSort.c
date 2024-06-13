#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int num);

int main() {
  int arr[10];
  int size = sizeof(arr) / sizeof(arr[0]);
  int i;
  
  // Ask and Display input
  for (i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }
  
  printf("%s\n", "Input Array:");
  for (i = 0; i < size; i++){
    printf("[%d] ",arr[i]);
  }
  

  // insertionSort

  printf("\n%s\n", "Sorted Array: " );
  insertionSort(arr,size);
  for (i = 0; i < size; i++){
    printf("[%d] ",arr[i]);
  }
 
    return EXIT_SUCCESS;
}

void insertionSort(int arr[], int num) {
  int i, key, j;
  for (i = 1; i < num; i++ ){
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j = j - 1;
    }
  arr[j + 1] = key;
  }
}
