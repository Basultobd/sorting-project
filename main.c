#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "sort.h"
#include "IO.h"


#define SUBJECTS_NUMBER 10
#define NEW_REGISTER 1
#define SORT_REGISTERS 2
#define EXIT_VALUE 0
#define MAX_NAME_SIZE 25
#define EXIT_OPTION 3

int main(int argc, char * argv[]){

	// ---------------- File information ---------------
	char **namesList;
	int **gradesList;
	char ***subjectsList;
	// -------------------------------------------------

	// ---------------- New student register -----------
	char studentName[MAX_NAME_SIZE];
	int studentGrades[SUBJECTS_NUMBER];
	// -------------------------------------------------

	int i;
	int j;

	int studentsNumber;
	int sortMethodSelected;
	int programActionSelected;

	char *srcFilename;
	char *dstFilename;
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
	scanf("%d", &programActionSelected);

	switch(programActionSelected){

		case NEW_REGISTER:

		fflush(stdin);

		printf("Insert name (first name - last name): ");
		gets(studentName);

		fflush(stdin);

		// printToFile(studentName, gradesList);

		break;


		case SORT_REGISTERS:

			printf("\nloading info...\n" );

			//get the students number
			studentsNumber = getStudentsNumber(srcFilename);

			//create lists
			namesList = newNamesList(studentsNumber);
			subjectsList = newSubjectsList(studentsNumber);
			gradesList = newGradesList(studentsNumber);
		
			//get all the required info
			loadNames(srcFilename, studentsNumber, namesList);
			loadSubjectsNames(srcFilename, studentsNumber, subjectsList);
			loadGrades(srcFilename, studentsNumber, gradesList);

			printf("Done\n\n");

			displaySortOptions();
			scanf("%d", &sortMethodSelected);
			sortGrades(sortMethodSelected, gradesList, studentsNumber, subjectsList);

			printf("\n------------ Grades sorted ----------------\n");
			displayFileInformation(subjectsList, namesList, gradesList, studentsNumber);

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