#include <stdio.h>
#include <stdbool.h>

#include "sortFunctions.h"
#define MAX_LENGTH 8

void insertionSort( int arrayToSort[ MAX_LENGTH ] ){
	
	int i;
	int j;
	int key;
	bool isLastNumber;
	bool isActNumberGTKey;

	for(j = 1; j < MAX_LENGTH; j++){
	
		key = arrayToSort[j];
		i = j - 1;

		isLastNumber = (i >= 0);
		isActNumberGTKey = arrayToSort[i] > key;

		while( isLastNumber && isActNumberGTKey ){

			arrayToSort[i+1] = arrayToSort[i];
			i = i - 1;
			arrayToSort[i+1] = key;

			isLastNumber = (i >= 0);
			isActNumberGTKey = arrayToSort[i] > key;
		}
	}
}

// moves the max value to the right ( maxBubbleSort() )
void selectionSort( int arrayToSort[ MAX_LENGTH ]){

	int i;
	int j;
	int auxValue;
	for( i = 0; i < MAX_LENGTH; i++){
		for( j = i+1; j < MAX_LENGTH; j++){
			// printf("arrayToSort[%d] = %d > arrayToSort[%d] = %d \n", j, arrayToSort[j] ,j+1 , arrayToSort[j+1] );
			if( arrayToSort[j] < arrayToSort[i] ){
				// printf("SWAP\n");
				auxValue = arrayToSort[j];
				arrayToSort[j] = arrayToSort[i];
				arrayToSort[i] = auxValue;
			}// }else{
			// 	printf("NO SWAP\n");
			// }
		}

	}
}


// moves the max value to the right ( maxBubbleSort() )
void bubbleSortRight( int arrayToSort[ MAX_LENGTH ]){

	int i;
	int j;
	int auxValue;
	for( i = MAX_LENGTH - 2; i >= 0; i--){
		for( j = 0; j < i; j++){
			// printf("arrayToSort[%d] = %d > arrayToSort[%d] = %d \n", j, arrayToSort[j] ,j+1 , arrayToSort[j+1] );
			if( arrayToSort[j] > arrayToSort[j+1] ){
				// printf("SWAP\n");
				auxValue = arrayToSort[j];
				arrayToSort[j] = arrayToSort[j+1];
				arrayToSort[j+1] = auxValue;
			}// }else{
			// 	printf("NO SWAP\n");
			// }
		}

	}
}


// moves the max value to the right ( maxBubbleSort() )
void bubbleSortLeft( int arrayToSort[ MAX_LENGTH ]){

	int i;
	int j;
	int auxValue;
	for( i = 0; i < MAX_LENGTH; i++){
		for( j = MAX_LENGTH - 1  ; j > i; j--){
			// printf("arrayToSort[%d] = %d < arrayToSort[%d] = %d \n", j-1, arrayToSort[j-1] ,j , arrayToSort[j] );
			if( arrayToSort[j] < arrayToSort[j-1] ){
				// printf("SWAP\n");
				auxValue = arrayToSort[j-1];
				arrayToSort[j-1] = arrayToSort[j];
				arrayToSort[j] = auxValue;
			}// }else{
			// 	printf("No hay intercambio\n");
			// }
		}

	}
}


