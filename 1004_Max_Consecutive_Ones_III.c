int longestOnes(int* nums, int numsSize, int k) {
  int Left = 0;
  int Zeroes = 0;
  int maxlen = 0;

  for(int Right = 0; Right < numsSize ; Right++){
    if (nums[Right] == 0){
        Zeroes++;
    }
    
    while( Zeroes > k){
        if( nums[Left] == 0){
            Zeroes--;
        }
        Left++;
    }

    int currentLength = Right - Left + 1;

    if( currentLength > maxlen){
        maxlen = currentLength ;
    }
  }
    return maxlen ;

}


