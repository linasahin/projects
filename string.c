#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int my_str_find(char* str, char* target);
char* my_str_replace(char* str, char* target, char* replacement);
char* my_str_trim(char* str);
char** my_str_split(char* str, char delimiter);

int main() {
    char str1[] = "Hello, world!";
    char target1[] = "world";
    int index = my_str_find(str1, target1);
    printf("Index of '%s' in '%s': %d\n", target1, str1, index);

    char str2[] = "hello world hello";
    char target2[] = "hello";
    char replacement[] = "hi";
    char* replaced_str = my_str_replace(str2, target2, replacement);
    printf("After replacement: %s\n", replaced_str);
    free(replaced_str);

    char str3[] = "   Hello, world!   ";
    char* trimmed_str = my_str_trim(str3);
    printf("Trimmed string: '%s'\n", trimmed_str);
    free(trimmed_str);

    char str4[] = "apple,orange,banana";
    char delimiter = ',';
    char** tokens = my_str_split(str4, delimiter);
    printf("Split string:\n");
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]); // Freeing memory for each token
    }
    free(tokens); // Freeing memory for the token array

    return 0;
}

// Function definitions
int my_str_find(char* str, char* target) {
    char* ptr = strstr(str, target);
    if (ptr != NULL) {
        return ptr - str;
    }
    return -1;
}

char* my_str_replace(char* str, char* target, char* replacement) {
    char* result = (char*)malloc(strlen(str) * 2); // Allocating memory for result
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int resultIndex = 0;
    int targetLen = strlen(target);
    int strLen = strlen(str);

    for (int i = 0; i < strLen; i++) {
        if (strncmp(&str[i], target, targetLen) == 0) {
            strcat(result, replacement);
            resultIndex += strlen(replacement);
            i += targetLen - 1;
        } else {
            result[resultIndex++] = str[i];
        }
    }
    result[resultIndex] = '\0';

    return result;
}

char* my_str_trim(char* str) {
    while (isspace(*str)) {
        str++;
    }

    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';

    char* trimmed_str = (char*)malloc(strlen(str) + 1);
    if (trimmed_str == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(trimmed_str, str);

    return trimmed_str;
}

char** my_str_split(char* str, char delimiter) {
    // Counting number of tokens
    int num_tokens = 1;
    char* ptr = str;
    while (*ptr != '\0') {
        if (*ptr == delimiter) {
            num_tokens++;
        }
        ptr++;
    }

    char** tokens = (char**)malloc((num_tokens + 1) * sizeof(char*));
    if (tokens == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int tokenIndex = 0;
    char* token = strtok(str, &delimiter);
    while (token != NULL) {
        tokens[tokenIndex] = (char*)malloc(strlen(token) + 1);
        if (tokens[tokenIndex] == NULL) {
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
        strcpy(tokens[tokenIndex], token);
        tokenIndex++;
        token = strtok(NULL, &delimiter);
    }
    tokens[tokenIndex] = NULL;

    return tokens;
}