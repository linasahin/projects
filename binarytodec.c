#include <stdio.h>
#include <string.h>

int convert(char *str){
    int total = 0;
    int decimal_val = 1;
    for(int i=strlen(str) - 1; i>= 0; i--){
        if(str[i] == '1') total += decimal_val;
        decimal_val *= 2;
    }
    return total;
}

int main(){
    int x = convert("10011");
    printf("%d\n", x);

    return 0;
}