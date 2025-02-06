#include <stdio.h>

int pyramid( int rows );

int main ( ){
	pyramid(5);
	return 0;
}

int pyramid( int rows ){
	int i = 0;
	while ( i < rows ){
		int spaces = 2*(rows-(i+1));
		int e = 0;
		while ( e < spaces ){
			printf(" ");
			e++;
		}
		int stars = 2*(i+1)-1;
		int a = 0;
		while ( a < stars ){
			printf("* ");
			a++;
		}
		printf("\n");
		i++;
	}
}