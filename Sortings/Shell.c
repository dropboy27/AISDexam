void shell(int *arr,  int n){
    int g = n/2;
    while(g>0){
        for(int i = g; i<n; i++){
            int current = arr[i];
            int j = i-g;
            while(j>=0 && arr[j] > current){
                arr[j+g] = arr[j];
                j-=g;
            }
            arr[j+g] = current;
        }
        g/=2;
    }
}
