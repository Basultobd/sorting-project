#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "sort.h"
#include "IO.h"

#define EXIT_VALUE 0
#define GRADES_NUMBER 10

int main(int argc, char * argv[]){
	

	int l;
	int i,j;

	char ***subjectsList;
	char **namesList;
	int **gradesList;
	int studentsNumber;
	int sortMethodSelected;

	char *srcFilename;
	char *dstFilename;

	char loadOption; 

	bool isInputFormatValid = argc == 2;
	bool isValidAnswer = false;
	bool isAffirmativeAnswer = false;

	if(isInputFormatValid){
		printf("Invalid input format! - Input format: <program name> <srcFilename.txt> <dstFilename.txt>\n");
		return EXIT_VALUE;
	}else{
		srcFilename = argv[1];
		dstFilename = argv[2];
	}

	printf("Do you want to load the students information - Y or N: ");
	scanf("%c", &loadOption);

	isValidAnswer = (loadOption == 'Y' || loadOption == 'N');
	while(!isValidAnswer){
		//clean the buffer
		fflush(stdin);
		printf("Please insert a valid option -  Y or N: ");
		scanf("%c", &loadOption);
		isValidAnswer = (loadOption == 'Y' || loadOption == 'N');
	}

	isAffirmativeAnswer = (loadOption == 'Y');
	if(isAffirmativeAnswer){

		printf("\nloading info...\n" );

		//get the students number
		studentsNumber = getStudentsNumber(srcFilename);
		// namesList = newNamesList();
		// gradesList = newGradesList();
		// subjectsList = newSubjectsList();

		//get all the required info
		namesList = loadNamesList(srcFilename, studentsNumber);
		gradesList = loadGradesList(srcFilename, studentsNumber);
		subjectsList = loadSubjectsList(srcFilename, studentsNumber);

		printf("Done\n\n");

	}else{

		printf("See you soon\n");
		return EXIT_VALUE;
	}

	displaySortOptions();
	scanf("%d", &sortMethodSelected);

	sortGrades(sortMethodSelected, gradesList, studentsNumber, subjectsList);

	printf("\n------------ Grades sorted ----------------\n");
	printFileInformation(subjectsList, namesList, gradesList, studentsNumber);


	// // int arrayToSort2[] = {67,15,8,16,44,27,12,35};
	//  // int arrayToSort2[] = {38,27,43,3,9,82,10};
	// int arrayToSort2[] = {15,67,8,16,44,27,12,35};

	// //bubbleSortLeft(arrayToSort2);
	// //selectionSort(arrayToSort2);
	// // shellSort(arrayToSort2);
	// //mergeSort(arrayToSort2, 0, MAX_LENGTH-1);
	// quicksort(arrayToSort2, 0, MAX_LENGTH-1);

	// printGradesList(arrayToSort2);



	free(namesList);
	free(gradesList);
	free(subjectsList);
		

	return EXIT_VALUE;
}