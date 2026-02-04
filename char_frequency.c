#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to count frequency of a character in a string
int countCharFrequency(char *str, char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (tolower(str[i]) == tolower(ch)) {
            count++;
        }
    }
    return count;
}

// Function to count number of words in a string using countCharFrequency
int countWords(char *str) {
    // Count spaces and add 1 to get word count
    // A word is defined as characters separated by spaces
    int spaceCount = countCharFrequency(str, ' ');
    
    // Trim leading and trailing spaces for accurate count
    int start = 0, end = strlen(str) - 1;
    
    while (str[start] == ' ') start++;
    while (end >= start && str[end] == ' ') end--;
    
    if (start > end) {
        return 0;  // Empty string
    }
    
    return spaceCount + 1;
}

// Function to print frequency of each alphabet in a string
void printAlphabetFrequency(char *str) {
    printf("\nFrequency of each alphabet:\n");
    printf("============================\n");
    
    int freq[26] = {0};  // Array for 26 alphabets
    
    // Count frequency of each alphabet
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            freq[tolower(str[i]) - 'a']++;
        }
    }
    
    // Print frequencies
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", 'a' + i, freq[i]);
        }
    }
}

int main() {
    char str[200];
    char searchChar;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    
    printf("\n--- String Analysis ---\n");
    printf("String: \"%s\"\n", str);
    
    // Count and display word count
    int wordCount = countWords(str);
    printf("\nNumber of words: %d\n", wordCount);
    
    // Count frequency of a specific character
    printf("\nEnter a character to search: ");
    scanf("%c", &searchChar);
    
    int charFreq = countCharFrequency(str, searchChar);
    printf("Frequency of '%c': %d\n", searchChar, charFreq);
    
    // Print frequency of all alphabets
    printAlphabetFrequency(str);
    
    return 0;
}
