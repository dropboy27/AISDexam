    #include <stdio.h>
    #include <stdlib.h>

    int *lin(int *arr, int n) {
        int *result = malloc(n * sizeof(int));
        if (!result) return NULL;
        for (int i = 0; i <n; i++){
            int current = 0;
            for (int j = 0; j < n; j++){
                if (arr[j]<arr[i] ||(arr[j] == arr[i] && j<i)){
                    current++;
                }
            }
            result[current] = arr[i];
        }
        return result;
    }
