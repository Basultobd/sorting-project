//librarys
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//header
#include "sort.h"
#include "IO.h"

//Constants
#define SUBJECTS_NUMBER 10
#define FIRST_SUBJECT_ID 0
#define LAST_SUBJECT_ID 9
#define INSERTION_SORT_ID 1
#define SELECTION_SORT_ID 2
#define BUBBLE_SORT_RIGHT_ID 3
#define BUBBLE_SORT_LEFT_ID 4
#define SHELL_SORT_ID 5
#define MERGE_SORT_ID 6
#define QUICKSORT_SORT_ID 7
#define SUBJECT_NAME_SIZE 3

void insertionSort( int **gradesList, int studentIndex, char ***subjectsList ){
	
	int i;
	int j;
	int key;
	int keyIndex;
	bool isFirstPosition;
	bool isActualNumberGTKey;

	char auxStringSubject[SUBJECT_NAME_SIZE];

	for(j = 1; j < SUBJECTS_NUMBER; j++){
	
		key = gradesList[studentIndex][j];
		keyIndex = j;
		strcpy(auxStringSubject,subjectsList[studentIndex][keyIndex]);
		i = j - 1;

		isFirstPosition = (i >= 0);
		isActualNumberGTKey = gradesList[studentIndex][i] > key;

		while( isFirstPosition && isActualNumberGTKey ){

			gradesList[studentIndex][i+1] = gradesList[studentIndex][i];
			strcpy(subjectsList[studentIndex][i+1], subjectsList[studentIndex][i]);

			i = i - 1;
			gradesList[studentIndex][i+1] = key;
			strcpy(subjectsList[studentIndex][i+1], auxStringSubject);

			isFirstPosition = (i >= 0);
			isActualNumberGTKey = gradesList[studentIndex][i] > key;
		}
	}
}

void selectionSort( int **gradesList, int studentIndex, char ***subjectsList ){

	int i;
	int j;
	int auxValue;
	char auxStringSubject[SUBJECT_NAME_SIZE];
	for( i = 0; i < SUBJECTS_NUMBER; i++){
		for( j = i+1; j < SUBJECTS_NUMBER; j++){
			// printf("gradesList[%d] = %d > gradesList[%d] = %d \n", j, gradesList[j] ,j+1 , gradesList[j+1] );
			if( gradesList[studentIndex][j] < gradesList[studentIndex][i] ){
				// printf("SWAP\n");
				auxValue = gradesList[studentIndex][j];
				strcpy(auxStringSubject, subjectsList[studentIndex][j]);
				gradesList[studentIndex][j] = gradesList[studentIndex][i];
				strcpy(subjectsList[studentIndex][j], subjectsList[studentIndex][i]);
				gradesList[studentIndex][i] = auxValue;
				strcpy(subjectsList[studentIndex][i], auxStringSubject);
			}// }else{
			// 	printf("NO SWAP\n");
			// }
		}

	}
}


// moves the max value to the right 
void bubbleSortRight( int **gradesList, int studentIndex, char ***subjectsList ){

	int i;
	int j;
	int auxValue;
	char auxStringSubject[SUBJECT_NAME_SIZE];
	for( i = SUBJECTS_NUMBER - 2; i >= 0; i--){
		for( j = 0; j < i; j++){
			// printf("gradesList[%d] = %d > gradesList[%d] = %d \n", j, gradesList[j] ,j+1 , gradesList[j+1] );
			if( gradesList[studentIndex][j] > gradesList[studentIndex][j+1] ){
				// printf("SWAP\n");
				auxValue = gradesList[studentIndex][j];
				strcpy(auxStringSubject, subjectsList[studentIndex][j]);
				gradesList[studentIndex][j] = gradesList[studentIndex][j+1];
				strcpy(subjectsList[studentIndex][j], subjectsList[studentIndex][j+1]);
				gradesList[studentIndex][j+1] = auxValue;
				strcpy(subjectsList[studentIndex][j+1], auxStringSubject);
			}// }else{
			// 	printf("NO SWAP\n");
			// }
		}

	}
}


// moves the max value to the left
void bubbleSortLeft( int **gradesList, int studentIndex, char ***subjectsList ){

	int i;
	int j;
	int auxValue;
	char auxStringSubject[SUBJECT_NAME_SIZE];
	for( i = 0; i < SUBJECTS_NUMBER; i++){
		for( j = SUBJECTS_NUMBER - 1  ; j > i; j--){
			// printf("gradesList[%d] = %d < gradesList[%d] = %d \n", j-1, gradesList[j-1] ,j , gradesList[j] );
			if( gradesList[studentIndex][j] < gradesList[studentIndex][j-1] ){
				// printf("SWAP\n");
				auxValue = gradesList[studentIndex][j-1];
				strcpy(auxStringSubject, subjectsList[studentIndex][j-1]);
				gradesList[studentIndex][j-1] = gradesList[studentIndex][j];
				strcpy(subjectsList[studentIndex][j], subjectsList[studentIndex][j+1]);
				gradesList[studentIndex][j] = auxValue;
				strcpy(subjectsList[studentIndex][j+1], auxStringSubject);
			}// }else{
			// 	printf("No hay intercambio\n");
			// }
		}

	}
}

void shellSort( int **gradesList, int studentIndex, char ***subjectsList ){

	int step = SUBJECTS_NUMBER;
	bool isStepSequenceNotFinish;
	int indexIterator;
	int auxValue;
	char auxStringSubject[SUBJECT_NAME_SIZE];

	while( step > 0 ) {

		step = step / 2;
		isStepSequenceNotFinish = true;

		while ( isStepSequenceNotFinish ){

			isStepSequenceNotFinish = false;
			indexIterator = 0;

			while ( (indexIterator + step) < SUBJECTS_NUMBER ){

				if( gradesList[studentIndex][indexIterator] > gradesList[studentIndex][indexIterator + step]){
					
					// printf(" %d > %d \n", gradesList[indexIterator], gradesList[indexIterator+step]);

					// printf("Before \n");
					// printArray(gradesList);
					// printf("\n");

					auxValue = gradesList[studentIndex][indexIterator];
					strcpy( auxStringSubject, subjectsList[studentIndex][indexIterator] );
					gradesList[studentIndex][indexIterator] = gradesList[studentIndex][indexIterator + step];
					strcpy( subjectsList[studentIndex][indexIterator], subjectsList[studentIndex][indexIterator + step]);
					gradesList[studentIndex][indexIterator + step] = auxValue;
					strcpy( subjectsList[studentIndex][indexIterator + step], auxStringSubject );

					// printf("After \n");
					// printArray(gradesList);
					// printf("\n");

					isStepSequenceNotFinish = true;
				}

				indexIterator++;
			}

		}
	}
}

void merge(int **gradesList, int lowPosition, int midPosition, int highPosition, int studentIndex, char ***subjectsList, char ***auxSubjectList){


	int i;
	int subjectNumber;
   	int auxArray[ SUBJECTS_NUMBER ];

   	int firstListCounter;
   	int secondListCounter;
   	firstListCounter = lowPosition;
   	secondListCounter = midPosition + 1;

   	bool isFirstListEmpty;
   	bool isSecondListEmpty;
   	isFirstListEmpty = firstListCounter <= midPosition;
   	isSecondListEmpty = secondListCounter <= highPosition;

	for(firstListCounter = lowPosition, secondListCounter = midPosition + 1, i = lowPosition; isFirstListEmpty && isSecondListEmpty ; i++){
    	if(gradesList[studentIndex][firstListCounter] <= gradesList[studentIndex][secondListCounter]){
      		auxArray[i] = gradesList[studentIndex][firstListCounter];
      		strcpy(auxSubjectList[studentIndex][i], subjectsList[studentIndex][firstListCounter]);
      		firstListCounter++;
      	} 
      	else{
      		auxArray[i] = gradesList[studentIndex][secondListCounter];
      		strcpy( auxSubjectList[studentIndex][i] , subjectsList[studentIndex][secondListCounter]);
      		secondListCounter++;
      	}  
      	
      	isFirstListEmpty = firstListCounter <= midPosition;
      	isSecondListEmpty = secondListCounter <= highPosition;
   	}
   
   	// if remain numbers to add to auxilar list
   	while(firstListCounter <= midPosition){
   		auxArray[i] = gradesList[studentIndex][firstListCounter];
   		strcpy(auxSubjectList[studentIndex][i], subjectsList[studentIndex][firstListCounter]);
   		i++;
   		firstListCounter++;
   	}
   
   	// if remain numbers to add to auxilar list
   	while(secondListCounter <= highPosition){
   		auxArray[i] = gradesList[studentIndex][secondListCounter];
   		strcpy( auxSubjectList[studentIndex][i] , subjectsList[studentIndex][secondListCounter]);
   		i++;
   		secondListCounter++;
   	}  
      
   	// 
   	for(i = lowPosition; i <= highPosition; i++){
   		gradesList[studentIndex][i] = auxArray[i];
   		strcpy( subjectsList[studentIndex][i] , auxSubjectList[studentIndex][i]);
    }

}

void mergeSort( int **gradesList, int lowPosition, int highPosition, int studentIndex, char ***subjectsList, char ***auxSubjectList){

	// int j;
	int midPosition;

	// for( j = lowPosition; j <= highPosition; j++){
	// 	printf("%d ", gradesList[j] );
	// }

	if ( lowPosition < highPosition){

		midPosition = (lowPosition + highPosition) / 2;
		// printf("\n LEFT\n");
		mergeSort(gradesList, lowPosition, midPosition, studentIndex, subjectsList, auxSubjectList);
		// printf("\n RIGHT\n");
		mergeSort(gradesList, midPosition+1, highPosition, studentIndex, subjectsList, auxSubjectList);

		merge(gradesList, lowPosition, midPosition, highPosition, studentIndex, subjectsList, auxSubjectList);
	}

}

void quicksort(int **gradesList, int firstPosition ,int endPosition, int studentIndex, char ***subjectsList){
	fastRecursive(gradesList, firstPosition, endPosition, studentIndex, subjectsList);
}

void fastRecursive(int **gradesList, int beginPosition, int endPosition, int studentIndex, char ***subjectsList){

	int firstPosition = beginPosition;
	int lastPosition = endPosition;
	int actualPosition = beginPosition;
	int auxValue;

	char auxStringSubject[ SUBJECT_NAME_SIZE ];

	bool flag = true;

	while(flag){

		flag = false;
		
		while(gradesList[studentIndex][actualPosition] <= gradesList[studentIndex][lastPosition] && actualPosition != lastPosition){
			lastPosition--;
		}

		//entra si es mas grande 
		// pasa de adelante a atras
		if(actualPosition != lastPosition){
			auxValue = gradesList[studentIndex][actualPosition];
			strcpy(auxStringSubject, subjectsList[studentIndex][actualPosition]);
			gradesList[studentIndex][actualPosition] = gradesList[studentIndex][lastPosition];
			strcpy(subjectsList[studentIndex][actualPosition], subjectsList[studentIndex][lastPosition]);
			gradesList[studentIndex][lastPosition] = auxValue;
			strcpy(subjectsList[studentIndex][lastPosition], auxStringSubject);
			actualPosition = lastPosition;

			while(gradesList[studentIndex][actualPosition] >= gradesList[studentIndex][firstPosition] && actualPosition != firstPosition){
				firstPosition++;
			}

			//entra si es mas pequeño
			// pasa de atras a adelante
			if(actualPosition != firstPosition){
				flag = true;
				auxValue = gradesList[studentIndex][actualPosition];
				strcpy(auxStringSubject, subjectsList[studentIndex][actualPosition]);
				gradesList[studentIndex][actualPosition] = gradesList[studentIndex][firstPosition];
				strcpy(subjectsList[studentIndex][actualPosition], subjectsList[studentIndex][firstPosition]);
				gradesList[studentIndex][firstPosition] = auxValue;
				strcpy(subjectsList[studentIndex][firstPosition], auxStringSubject);
				actualPosition = firstPosition;
			}

		}

	}
	
	if((actualPosition - 1) > beginPosition){
		fastRecursive(gradesList, beginPosition, actualPosition-1, studentIndex, subjectsList);
		}

	if((actualPosition + 1) < endPosition){
		// printf("%d\n", endPosition );
		fastRecursive(gradesList, actualPosition+1, endPosition, studentIndex, subjectsList);
		}
}


void displaySortOptions(){

	printf("-- Sort options -- \n"
		"1. Insertionsort \n"
		"2. Selectionsort \n"
		"3. Bubblesort right \n"
		"4. Bubblesort left \n"
		"5. Shellsort \n"
		"6. Mergesort \n"
		"7. Quicksort \n"
		"Choose an option: ");

}

void sortGrades(int sortMethodSelected, int **gradesList, int studentsNumber, char ***subjectsList){

	int studentIndex;
	char ***auxSubjectsList;

	switch(sortMethodSelected){

		case INSERTION_SORT_ID:

			for(studentIndex = 0; studentIndex < studentsNumber; studentIndex++){
				insertionSort(gradesList, studentIndex, subjectsList); 
			}

			break;

		case SELECTION_SORT_ID:

			for(studentIndex = 0; studentIndex < studentsNumber; studentIndex++){
				selectionSort(gradesList, studentIndex, subjectsList); 
			}

			break;

		case BUBBLE_SORT_RIGHT_ID:

			for(studentIndex = 0; studentIndex < studentsNumber; studentIndex++){
				bubbleSortRight(gradesList, studentIndex, subjectsList); 
			}

			break;

		case BUBBLE_SORT_LEFT_ID:

			for(studentIndex = 0; studentIndex < studentsNumber; studentIndex++){
				bubbleSortRight(gradesList, studentIndex, subjectsList); 
			}

			break;

		case SHELL_SORT_ID:

			for(studentIndex = 0; studentIndex < studentsNumber; studentIndex++){
				shellSort(gradesList, studentIndex, subjectsList); 
			}

			break;

		case MERGE_SORT_ID:

			auxSubjectsList = newSubjectsList(studentsNumber);

			for(studentIndex = 0; studentIndex < studentsNumber; studentIndex++){
				mergeSort(gradesList, FIRST_SUBJECT_ID, LAST_SUBJECT_ID, studentIndex, subjectsList, auxSubjectsList);
			}

			break;

		case QUICKSORT_SORT_ID:

			for(studentIndex = 0; studentIndex < studentsNumber; studentIndex++){
				quicksort(gradesList, FIRST_SUBJECT_ID, LAST_SUBJECT_ID, studentIndex, subjectsList);
			}

			break;

	}

}


void printGradesList( int **gradesList, int studentIndex){
	int gradeIndex;
	for(gradeIndex = 0; gradeIndex < SUBJECTS_NUMBER; gradeIndex++ ){
		printf("%d ", gradesList[studentIndex][gradeIndex] );
	}

}
