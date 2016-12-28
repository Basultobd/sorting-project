#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#include "sort.h"
#include "IO.h"


#define SUBJECTS_NUMBER 10
#define NEW_REGISTER 1
#define SORT_REGISTERS 2
#define EXIT_VALUE 0
#define MAX_NAME_SIZE 15
#define EXIT_OPTION 3
#define MAX_FILENAME_SIZE 20

int main(int argc, char * argv[]){

	// ---------------- File information ---------------
	char **namesList;
	int **gradesList;
	char ***subjectsList;
	// -------------------------------------------------

	// ---------------- New student register -----------
	char studentName[MAX_NAME_SIZE];
	int studentGrades[SUBJECTS_NUMBER];
	char **subjectsNames;
	// -------------------------------------------------

	float *averagesList;
	int *sortedPositions;

	int i;
	int j;

	int studentsNumber;
	int sortMethodSelected;
	int programActionSelected;

	char *srcFilename;
	char *p;
	char dstFilename[MAX_FILENAME_SIZE];

	const char *subjectsFile = "subjects.txt";

	bool isInputFormatValid = (argc == 2);
	bool isValidAnswer = false;
	bool isAffirmativeAnswer = false;

	FILE *file;

	if(isInputFormatValid){
		srcFilename = argv[1];
	}else{
		printf("Invalid input format! - Input format: <program name> <srcFilename.txt>\n");
		return EXIT_VALUE;
	}


	displayProgramOptions();
	scanf("%d%*c", &programActionSelected);

	switch(programActionSelected){

		case NEW_REGISTER:

			printf("Insert name (first name - last name): ");
			fgets(studentName, MAX_NAME_SIZE, stdin );

			p = strchr(studentName,'\n');
   			if (p) *p = '\0';

			subjectsNames = getSubjectsNames("subjects.txt");

			for(i = 0; i < SUBJECTS_NUMBER; i++){
				printf("Grade of subject %s: ", subjectsNames[i]);
				scanf("%d",&studentGrades[i]);  
			}

			addRegisterFile(srcFilename, studentName, studentGrades, subjectsNames);

			free(subjectsNames);

			break;

		case SORT_REGISTERS:

			printf("\nloading info...\n" );

			//get the students number
			studentsNumber = getStudentsNumber(srcFilename);

			//create lists
			namesList = newNamesList(studentsNumber);
			subjectsList = newSubjectsList(studentsNumber);
			gradesList = newGradesList(studentsNumber);

			//considerar poner getStudenstNumber en sort.c
		
			//get all the required info
			loadNames(srcFilename, studentsNumber, namesList);
			loadSubjectsNames(srcFilename, studentsNumber, subjectsList);
			loadGrades(srcFilename, studentsNumber, gradesList);

			printf("Done\n\n");

			displaySortOptions();
			scanf("%d%*c", &sortMethodSelected);
			sortGrades(sortMethodSelected, gradesList, studentsNumber, subjectsList);

			printf("\n------------ Grades sorted ----------------\n");
			// displayFileInformation(subjectsList, namesList, gradesList, studentsNumber);

			averagesList = calculateAverages(gradesList, studentsNumber);

			sortedPositions = getSortedPositions(averagesList,studentsNumber);

			printf("Insert the name of the destiny file: ");
			fgets(dstFilename, MAX_FILENAME_SIZE, stdin);

			p = strchr(dstFilename,'\n');
   			if (p) *p = '\0';


			printToFile(namesList, gradesList, subjectsList, averagesList, studentsNumber, sortedPositions, dstFilename);

			printf("File created...\n");

			free(sortedPositions);
			free(averagesList);
			free(namesList);
			free(gradesList);
			free(subjectsList);

			break;

		case EXIT_OPTION:

			printf("See you soon\n");
			return EXIT_VALUE;

	}
		
	return EXIT_VALUE;
}