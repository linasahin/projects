//I am aware my code doesn't work correctly but I will still upload.
#include <stdio.h>
#include <string.h>

char *first(char *s1, char *s2);
int count_of_first(char *s1, char *s2);
void print_counts(char *s1, char *s2);

int main(){
    char s1[] = "abc cd ef";
    char s2[] = "efg ef abc cd abc";
//                      *           <-- first func should return a pointer there.
    char *first_occ = first(s1, s2);
    printf("First occurrence: %s\n", first_occ);
    int x = count_of_first(s1, s2);
    printf("%d\n", x);//expected output is 2 (2 abc s in s2).
    print_counts(s1, s2);//couldn't write this func.

    return 0;
}

char *first(char *s1, char *s2){
    int i, j;
    for (i = 0; s2[i] != '\0'; i++){//loop the s2 array until the end.
        if (s1[0] == s2[i]){//if their first elements match, check the rest.
            for (j = 0; s1[j] != '\0'; j++){//loop until the end of word s1.
                if (s1[j] != s2[i + j]){//if any of the elements don't match, break.
                    break;
                }
            }
            if (s1[j] == '\0'){//if we reached the end of word s1 without any mismatch (without breaking), then return the address of when the word first starts.
                return (s2 + i);
            }
        }
    }
    return NULL;//return NULL if no match found.
}

int count_of_first(char *s1, char *s2){//couldn't do :(
    int count = 0;//count is initially 0.
    char *s1_search;
    int length = strlen(s2);

    for(int i = 0; i< length; i++){
        if(*s1_search == *s1){
            count++;
        }
    }
    return count;
}

void print_counts(char *s1, char *s2){//couldn't do :(
    while (*s2 != '\0'){//up until the end of s2 we loop.
        int count = count_of_first(s1, s2);//but this only displays the count of first word of s1, not others??
        printf("word: %s count: %d\n", s1, count);
    }
}