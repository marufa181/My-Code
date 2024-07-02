#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

void common_prefix(char* result, char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j;
    for (i = 0, j = 0; i < len1 && j < len2; i++, j++) {
        if (str1[i] != str2[j]) {
            break;
        }
        result[i] = str1[i];
    }
    result[i] = '\0';
}

void longest_common_prefix(char result[], char strings[][MAX_LENGTH], int left, int right) {
    if (left == right) {
        strcpy(result, strings[left]);
        return;
    }

    int mid = left + (right - left) / 2;
    char lcp_left[MAX_LENGTH], lcp_right[MAX_LENGTH];

    longest_common_prefix(lcp_left, strings, left, mid);
    longest_common_prefix(lcp_right, strings, mid + 1, right);
    
    common_prefix(result, lcp_left, lcp_right);
}

int main() {
    int n;
    char strings[MAX_STRINGS][MAX_LENGTH];
    char lcp[MAX_LENGTH];

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        printf("String %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    longest_common_prefix(lcp, strings, 0, n - 1);
    printf("Longest common prefix: %s\n", lcp);

    return 0;
}
