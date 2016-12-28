#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//header file
#include "IO.h"

//constants 
#define BUFFER_SIZE 90
#define BUFFER_SUBJECT_SIZE 3
#define SUBJECT_NAME_SIZE 3
#define SUBJECTS_NUMBER 10
#define DELIMITER_SIZE 2
#define MAX_NAME_SIZE 25

void loadNames(const char *filename, int studentsNumber, char **namesList){

	FILE *file = fopen(filename, "r");

	if(file == NULL){
		return;
	}

	int nameElementsCounter = 0;
	int nameElementsNumber = 2;
	int i;

	char *token;
	char userName[MAX_NAME_SIZE];
	char readLine[BUFFER_SIZE];

	const char delimiter[DELIMITER_SIZE] = " ";

	bool isEOF = false;
	bool isUsernameComplete = false;

	i = 0;
	while(!isEOF){
		if(fgets(readLine, BUFFER_SIZE, file) == NULL){
			isEOF = true;
		}else{

			//first token
			token = strtok(readLine, delimiter);

			isUsernameComplete = nameElementsCounter < nameElementsNumber;
			while( isUsernameComplete && token != NULL){

				// if reads the first name
				if(nameElementsCounter == 0){
					strcpy(userName, token);
				}else{
					// if reads the last name
					strcat(userName, " ");
					strcat(userName, token);
				}

				// next token
				token = strtok(NULL, delimiter);
				nameElementsCounter++;

				//have the name a first and last name
				isUsernameComplete = nameElementsCounter < nameElementsNumber;
			}

			// store actual name
			strcpy(namesList[i], userName);
			//reset for new name
			nameElementsCounter = 0;
			i++;
		}
	}

	fclose(file);

}

void loadGrades(const char *filename, int studentsNumber, int **gradesList){

	FILE *file = fopen(filename, "r");

	if(file == NULL){
		return;
	}

	int NumberGradesRead = 0;
	int registerElementRead = 0;
	int nameElementsRead = 0;
	int j;
	int i;

	char readLine[BUFFER_SIZE];
	char *token;

	const char delimiter[DELIMITER_SIZE] = " ";

	bool isEOF = false;
	bool isGradesListNotComplete = false;
	bool areAllNameElementsAvoided = false;

	i = 0;
	j = 0;
	while(!isEOF){
		if(fgets(readLine, BUFFER_SIZE, file) == NULL){
			isEOF = true;
		}else{

			// ****************************** ignore the names *****************
			//first token
			token = strtok(readLine, delimiter);
			//first name read 
			nameElementsRead++;

			areAllNameElementsAvoided = nameElementsRead < 2; 
			while( areAllNameElementsAvoided && token != NULL){
				//last name read
				nameElementsRead++;
				token = strtok(NULL, delimiter);

				//new verification
				areAllNameElementsAvoided = nameElementsRead < 2;
			}

			nameElementsRead = 0;

			// ****************************************************************

			token = strtok(NULL, delimiter);
			registerElementRead++;

			isGradesListNotComplete = NumberGradesRead < SUBJECTS_NUMBER;
			while( isGradesListNotComplete && token != NULL){

				// if is a subject name or the grade 
				if( registerElementRead % 2 == 0){
					gradesList[i][j] = atoi(token);
					NumberGradesRead++;
					registerElementRead++;
					j++;
				}else{
					registerElementRead++;
				}

				token = strtok(NULL, delimiter);

				//have the name a first and last name
				isGradesListNotComplete = NumberGradesRead < SUBJECTS_NUMBER;
			}

			j = 0;
			NumberGradesRead = 0;
			registerElementRead = 0; 
			i++;
		}

	}

	fclose(file);
}

void loadSubjectsNames(const char *filename, int studentsNumber, char ***subjectsList){

	FILE *file = fopen(filename, "r");

	if(file == NULL){
		return;
	}

	int i; 
	int j; 
	int NumberSubjectsRead = 0;
	int registerElementRead = 0;
	int nameElementsRead = 0;

	char readLine[BUFFER_SIZE];
	char *token;

	const char delimiter[DELIMITER_SIZE] = " ";

	bool isEOF = false;
	bool isSubjectsListNotComplete = false;
	bool areAllNameElementsAvoided = false;

	i = 0;
	j = 0;
	while(!isEOF){
		if(fgets(readLine, BUFFER_SIZE, file) == NULL){
			isEOF = true;
		}else{

			// ****************************** ignore the names *****************
			//first token
			token = strtok(readLine, delimiter);
			//first name read 
			nameElementsRead++;

			areAllNameElementsAvoided = nameElementsRead < 2; 
			while( areAllNameElementsAvoided && token != NULL){
				//last name read
				nameElementsRead++;
				token = strtok(NULL, delimiter);

				//new verification
				areAllNameElementsAvoided = nameElementsRead < 2;
			}

			nameElementsRead = 0;

			// ****************************************************************

			token = strtok(NULL, delimiter);
			registerElementRead++;

			isSubjectsListNotComplete = NumberSubjectsRead < SUBJECTS_NUMBER;
			while( isSubjectsListNotComplete && token != NULL){

				// if is a subject name or the grade 
				if( registerElementRead % 2 != 0 ){
					strcpy(subjectsList[i][j], token);
					NumberSubjectsRead++;
					registerElementRead++;
					j++;
				}else{
					registerElementRead++;
				}

				token = strtok(NULL, delimiter);

				//have the name a first and last name
				isSubjectsListNotComplete = NumberSubjectsRead < SUBJECTS_NUMBER;
			}

			j = 0;
			NumberSubjectsRead = 0;
			registerElementRead = 0; 
			i++;
		}
	}

	fclose(file);
}



int getStudentsNumber(const char *fileName){

	FILE *file = fopen(fileName, "r");

  	char character;
  	int studentsNumber = 1;

  	character = fgetc(file);

  	while (!feof(file)){
      	if (character == '\n'){
      		studentsNumber++;
      	}	

      	character = fgetc(file);
    }

    fclose(file);

  	return studentsNumber;
}

char ***newSubjectsList(int studentsNumber){

	int i;
	int j;
	char ***newSubjectsList;
	newSubjectsList = malloc(sizeof(char**) * studentsNumber);

	for(i = 0; i < studentsNumber; i++){
		newSubjectsList[i] = malloc(sizeof(char*) * SUBJECTS_NUMBER);
		for(j = 0; j < SUBJECTS_NUMBER; j++){
			newSubjectsList[i][j] = malloc(sizeof(char) * SUBJECT_NAME_SIZE);
		}
	}

	return newSubjectsList;
}

char **newNamesList(int studentsNumber){

	int i;
	int j;
	char **newNamesList;
	newNamesList = malloc(sizeof(char*) * studentsNumber);	

	for (i = 0; i < studentsNumber; i++){
		newNamesList[i] = malloc(sizeof(char) * MAX_NAME_SIZE);
	}

	return newNamesList;
}

int **newGradesList(int studentsNumber){

	int i;
	int **newGradesList;

	newGradesList = malloc(sizeof(int*) * studentsNumber);

	for(i = 0; i < studentsNumber; i++){
		newGradesList[i] = malloc(sizeof(int) * SUBJECTS_NUMBER);
	}

	return newGradesList;

}

char **getSubjectsNames(const char *filename){

	FILE *file = fopen(filename, "r");

	int i;
	int subjectNameIndex = 0;
	int elementsToRead = 1;

	char **subjectsNames;
	char line[BUFFER_SUBJECT_SIZE];
	char subject[SUBJECT_NAME_SIZE];

	subjectsNames = malloc(sizeof(char*) * SUBJECTS_NUMBER);

	bool isEOF = false;

	i = 0;
	while(!isEOF){
		if(fgets(line, BUFFER_SUBJECT_SIZE , file) == NULL){
			isEOF = true;
		}else{

			fflush(stdin);

			//only read one element 
			strncpy(subject, line, elementsToRead);

			//null character
			subject[subjectNameIndex+1] = '\0';

			//subject name 
			subjectsNames[i] = malloc(sizeof(char) * SUBJECT_NAME_SIZE);

			//copy the name in the list 
			strcpy(subjectsNames[i], subject);

			i++;

		}
	}

	fclose(file);
	return subjectsNames; 

}

	

void displayProgramOptions(){
	printf("------- Program options ------- \n"
		"1. New student register \n"
		"2. Sort registers \n"
		"3. Exit \n"
		"Choose an option: ");
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


void displayFileInformation(char ***subjectsList, char **namesList, int **gradesList, int studentsNumber){

	int i;
	int j;

	for(i = 0; i < studentsNumber; i++){
		printf("\nName : %s\n", namesList[i]);
		for(j = 0; j < SUBJECTS_NUMBER; j++){
			printf("Subject %d : %s  - Grade : %d \n", j+1, subjectsList[i][j] , gradesList[i][j]);
		}
	}
	
}

void addRegisterFile(char *filename, char *studentName, int gradesList[], char **subjectsNames){
	
	FILE *file = fopen(filename,  "a");

	int i;

	char newLine = '\n';

	fprintf(file,"%c", newLine);
	fprintf(file, "%s" ,studentName);

	for(i = 0; i < SUBJECTS_NUMBER; i++){
		fprintf(file, " %s %d", subjectsNames[i], gradesList[i]);
	}

	// fprintf(file,newLine);

	fclose(file);


}

void printToFile(char **namesList, int **gradesList, char ***subjectsList, float *averagesList, int studentsNumber, int *positions, char *dstFilename){

	FILE *file = fopen(dstFilename,  "w");

	int i;
	int j;

	int studentIndex;

	char newLine = '\n';

	for(i = 0; i < studentsNumber; i++){

		studentIndex = positions[i];
		fprintf(file, "%d - ", i+1);
		fprintf(file, "%s" , namesList[studentIndex]);

		for(j = 0; j < SUBJECTS_NUMBER; j++){
			fprintf(file, " %s %d",subjectsList[studentIndex][j], gradesList[studentIndex][j]);
		}

		fprintf(file, " - Av: %f", averagesList[i]);
		fprintf(file,"%c", newLine);
	}

	

	fclose(file);

}
