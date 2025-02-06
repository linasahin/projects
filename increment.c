#include <stdio.h>

int main(){
    int i, j;
    int initial_increment = 2;

    for (i = 0; i < 10; i++ ){
        initial_increment *= 2;
        for ( j = 0; j < 10; j++){
            initial_increment *= 2;
        }
    }

    for (i = 0; i < 10; i++){
        int starting_num = 1;
        int new_num = starting_num + initial_increment*i;
        printf("%d\n", new_num);

        int new_start_num = starting_num + 1;
        for(j = 0; j < 10; j++){
            int new_new_num = new_start_num + initial_increment*i;
            printf("%d\n", new_new_num);
            new_start_num++;
        }printf("\n");
    }
    return 0;
} //i am aware it doesn't give the correct output but i couldn't fix