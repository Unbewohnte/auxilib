#include "levenshtein.h"

int _min(int a, int b) {
    if (a < b) {
        return a;
    }

    return b;
}

// Calculates Levenshtein distance for str1 and str2 of length len1 and len2 respectively
int levenshtein_distance(const char* str1, const char* str2) {
    unsigned int len1 = strlen(str1) + 1;
    unsigned int len2 = strlen(str2) + 1;

    if (len1 == 0) {
        return len2;
    }

    if (len2 == 0) {
        return len1;
    }

    if (strcmp(str1, str2) == 0) {
        return 0;
    }

    char s1[len2];
    char s2[len2];
    char row[len1];

    strcpy(s1, str1);
    strcpy(s2, str2);

    for (unsigned int i = 0; i < len1; i++) {
        row[i] = i;
    }

    for (unsigned int i = 1; i < len2; i++) {
        int previous = i;

        for (unsigned int j = 1; j < len1; j++) {
            int current = row[j-1];
            if (s2[i-1] != s1[j-1]) {
                current = _min(_min(row[j-1]+1, previous+1), row[j]+1);
            }
            row[j-1] = previous;
            previous = current;
        }
        row[len1] = previous;
    }

    return row[len1];
}