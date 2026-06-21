void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void godown(int *arr, int start, int size){
    int i = start;
    while (true){
        int left = i*2+1;
        int right = i*2+2;
        int largest = i;
        if (left < size && arr[left]>arr[largest]){
            largest = left;
        }
        if (right < size && arr[right]>arr[largest]){
            largest = right;
        }
        if (largest == i){
            break;
        }
        swap(&arr[i], &arr[largest]);
        i = largest;
    }
}

void heap_sort(int *arr, int n){
    for (int i = n/2 -1; i>=0;i--){
        godown(arr, i, n);
    }
    for (int end = n-1; end >0; end--){
        swap(&arr[end], &arr[0]);
        godown(arr, 0 , end);
    }
}

