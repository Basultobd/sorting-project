#include <stdio.h>
#include "sortFunctions.h"
#define MAX_LENGTH 8

int main(int argc, char const *argv[]){
	
	// int arrayToSort[] = {15,67,8,16,44,27,12,35};

	// bubbleSortMIN(arrayToSort);

	// int l;
	// for(l = 0; l < MAX_LENGTH; l++ ){
	// 	printf("%d ", arrayToSort[l] );
	// }

	int l;

	int arrayToSort2[] = {15,67,8,16,44,27,12,35};

	//bubbleSortLeft(arrayToSort2);
	selectionSort(arrayToSort2);

	for(l = 0; l < MAX_LENGTH; l++ ){
		printf("%d ", arrayToSort2[l] );
	}


	return 0;
}