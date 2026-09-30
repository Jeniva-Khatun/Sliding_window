long long maximumSubarraySum(int* nums, int numsSize, int k) {
    int freq[100001] = {0};
    long long sum = 0;
    long long maxSum = 0;
    int distinct = 0;

   
    for (int i = 0; i < k; i++) {
        sum += nums[i];

        if (freq[nums[i]] == 0)
            distinct++;

        freq[nums[i]]++;
    }

    if (distinct == k)
        maxSum = sum;


    for (int i = k; i < numsSize; i++) {

      
        sum += nums[i];

        if (freq[nums[i]] == 0)
            distinct++;

        freq[nums[i]]++;

   
        int removed = nums[i - k];
        sum -= removed;

        freq[removed]--;

        if (freq[removed] == 0)
            distinct--;

       
        if (distinct == k && sum > maxSum)
            maxSum = sum;
    }

    return maxSum;
}
