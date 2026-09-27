int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int sum = 0;
    int count =0;

    for (int i =0; i<k ; i++){
        sum += arr[i];
    }
    if (sum >= k * threshold){
        count++;
    }

    for (int i = k; i<arrSize ; i++){
        sum += arr[i];
        sum -= arr[i-k];

        if (sum >= k * threshold){
        count++;
     }
    }
    
    return count;


}
