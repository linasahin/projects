#include <stdio.h>

#define variable 11
#define cat '*'

//this function depends on the BASE!

void pyramid(int,char);

int main(void){

    pyramid(variable,cat);

    return 0;
}

void pyramid(int base,char ch){
    int row,space,stars;
    int i; //lcv

    for(row=1,space=(base/2),stars=row;row<=(base/2)+1;row++,stars+=2,space--){
        for(i=0;i<space;i++){
            printf(" ");
        }
        for(i=0;i<stars;i++){
            printf("%c",ch);
        }
        printf("\n");
    }
}