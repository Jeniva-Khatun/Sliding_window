int lengthOfLongestSubstring(char* s) {

    int alreadySeen[128];

  
    for (int i = 0; i < 128; i++) {
        alreadySeen[i] = -1;
    }

    int left = 0;
    int maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        char ch = s[right];

      
        if (alreadySeen[(unsigned char)ch] >= left) {
            left = alreadySeen[(unsigned char)ch] + 1;
        }

        alreadySeen[(unsigned char)ch] = right;

     
        int currentLen = right - left + 1;

        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}
