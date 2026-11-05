#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* minWindow(char* s, char* t) {

    int letter[128] = {0};

    int m = strlen(s);
    int n = strlen(t);

    if (n == 0 || m < n)
        return "";

    
    for (int i = 0; i < n; i++) {
        letter[(int)t[i]]++;
    }

    int missingletter = n;

    int left = 0;
    int minStart = 0;
    int minLen = m + 1;

   
    for (int right = 0; right < m; right++) {

        char c = s[right];

        if (letter[(int)c] > 0) {
            missingletter--;
        }

        letter[(int)c]--;

        
        while (missingletter == 0) {

            int windowLen = right - left + 1;

            if (windowLen < minLen) {
                minLen = windowLen;
                minStart = left;
            }

           
            char d = s[left];

            letter[(int)d]++;

            if (letter[(int)d] > 0) {
                missingletter++;
            }

            left++;
        }
    }

    
    if (minLen == m + 1)
        return "";

    
    char* ans = malloc(minLen + 1);

    strncpy(ans, s + minStart, minLen);
    ans[minLen] = '\0';

    return ans;
}
