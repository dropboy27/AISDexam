void swap_quick(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for (int j = low; j< high; j++){
        if(arr[j]<pivot){
            i++;
            swap_quick(&arr[i], &arr[j]);
        }
    }
    swap_quick(&arr[i+1], &arr[high]);
    return i+1;
}
int quick_sort(int* arr, int low, int high){
    if (low <high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}
