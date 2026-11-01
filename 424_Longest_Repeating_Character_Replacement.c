
int characterReplacement(char* s, int k) {
    int frequency[26] = {0};

    int Left = 0;
    int maxFrequency = 0;
    int maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        frequency[s[right] - 'A']++;

        if (frequency[s[right] - 'A'] > maxFrequency) {
            maxFrequency = frequency[s[right] - 'A'];
        }

  
        while ((right - Left + 1) - maxFrequency > k) {

            frequency[s[Left] - 'A']--;
            Left++;
        }

      
        int windowLength = right - Left + 1;

        if (windowLength > maxLength) {
            maxLength = windowLength;
        }
    }

    return maxLength;
}
