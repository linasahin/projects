#include <stdio.h>
#define SIZE 17

int* find_first_occurence( int A[], int n, int size );
int* find_kth_occurrence( int A[], int n, int size, int k );
int count_occurrences_between( int A[], int* start, int* end, int n );
int count_elements_between_occurrences( int A[], int a, int b, int n, int k );

int main(){
    
    int A[] = {1,2,3,4,5,6,7,8,9,3,5,2,3,6,8,5,3};
    
    printf( "%d\n", find_first_occurence( A, 3, SIZE ) );
    printf( "%d\n", *(find_first_occurence( A, 3, SIZE )) );


    printf( "%d\n", &A[12] );
    printf( "%d\n", find_kth_occurrence( A, 3, SIZE, 3 ) );
    printf( "%d\n", *(find_kth_occurrence( A, 3, SIZE, 3 )) );
    
    int* start = find_first_occurence( A, 3, SIZE );
    int* end = find_kth_occurrence( A, 3, SIZE, 3 );
    printf( "%d\n", count_occurrences_between( A, start, end, 3 ) );
    
    printf( "%d\n", count_elements_between_occurrences( A, 1, 3, 3, 5 ) );
    
    return 0;
}

int* find_first_occurence( int A[], int n, int size ){
    int i = 0;
    while ( i < size ){
        if ( A[i] == n ){
            return A+i;
        }
        i++;
    }
}

int* find_kth_occurrence( int A[], int n, int size, int k ){
    int i = 0, occ = 0;
    while ( i < size ){
        if ( A[i] == n ){
            occ++;
            if ( occ == k ){
                return A+i;
            }
        }
        i++;
    }
}

int count_occurrences_between( int A[], int* start, int* end, int n ){
    int size = ( end - start ), i = 0, occ = 0;
    while ( i < size ){
        if ( *(start+i) == n ){
            occ++;
        }
        i++;
    }
    return occ;
}

int count_elements_between_occurrences( int A[], int a, int b, int n, int k ){
    int* start = find_kth_occurrence( A, n, SIZE, a );
    int* end = find_kth_occurrence( A, n, SIZE, b );
    int size = ( end - start ); 
    int i = 0, occ = 0;
    while ( i < size ){
        if ( *(start+i) == k ){
            occ++;
        }
        i++;
    }
    return occ;
} 