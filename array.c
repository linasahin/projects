#include <stdio.h>

void seperate_odd_even( int array[] , int length );
void printer( int array[] , int length );
void rearrenge_sub_arrays(int array[], int size, int sub_size);
void print_matrix( int array[] , int row  , int column);

int main(){

    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
    
    //seperate_odd_even(array,100);
    
    //printer(array,100);
    
    rearrenge_sub_arrays(array,100,10);
    
    //print_matrix(array,10,10);

    return 0;
}

void seperate_odd_even( int array[] , int length ){
    int middle = length / 2 + 1;
    int i = 0 , j = middle;
    while ( i < middle ){
        if ( i % 2 == 0 ){
            if ( j % 2 == 1 ){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        i++;
        j++;
    }
    printer(array,length);
}

void rearrenge_sub_arrays(int array[], int size, int sub_size) {
    int sub_count = size / sub_size;
    
    if (size % sub_size > 0) sub_count += 1; //eğer fazladan eleman kalırsa ona ait fazladan küme açabilmek için
    
    for (int j = 0; j < sub_count; j++) {
        int sub_array[sub_size];
        for (int i = 0; i < sub_size; i++) {
            sub_array[i] = array[i + (j * sub_size)];
        }
        seperate_odd_even(sub_array, sub_size);
    }
}

void print_matrix( int array[] , int row  , int column){
    int i = 0;
    while ( i < row ){
        int j = 0;
        while ( j < column ){
            printf("%d," , array[10*i+1*j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void printer( int array[] , int length){
    int i = 0;
    while ( i < length ){
        if ( array[i] != 0 ){
            printf("%d," , array[i]);
        }
        i++;
    }
    printf("\n");
}