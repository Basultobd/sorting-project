#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//header file
#include "IO.h"

//constants 
#define BUFFER_SIZE 90
#define SUBJECT_NAME_SIZE 3
#define SUBJECTS_NUMBER 10
#define DELIMITER_SIZE 2

char **getNamesList(const char *filename, int studentsNumber){

	FILE *file = fopen(filename, "r");

	if(file == NULL){
		return NULL;
	}

	int nameElementsCounter = 0;
	int maxNameSize = 20;
	int nameElementsNumber = 2;

	char **namesList;
	char *token;
	char userName[20];
	char readLine[BUFFER_SIZE];

	const char delimiter[DELIMITER_SIZE] = ";";

	bool isEOF = false;
	bool isUsernameComplete = false;

	namesList = malloc(sizeof(char*) * studentsNumber);	

	int i;
	for (i = 0; i < studentsNumber; i++){
		namesList[i] = malloc(sizeof(char) * maxNameSize);
	}

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
	return namesList;

}

int **getGradesList(const char *filename, int studentsNumber){

	FILE *file = fopen(filename, "r");

	if(file == NULL){
		return NULL;
	}

	int **gradesList;
	int NumberGradesRead = 0;
	int registerElementRead = 0;
	int nameElementsRead = 0;
	int j;

	char readLine[BUFFER_SIZE];
	char *token;

	const char delimiter[DELIMITER_SIZE] = ";";

	bool isEOF = false;
	bool isGradesListNotComplete = false;
	bool areAllNameElementsAvoided = false;

	gradesList = malloc(sizeof(int*) * studentsNumber);

	int i;
	for(i = 0; i < studentsNumber; i++){
		gradesList[i] = malloc(sizeof(int) * SUBJECTS_NUMBER);
	}

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
	return gradesList;
}

char ***getSubjectsList(const char *filename, int studentsNumber){

	FILE *file = fopen(filename, "r");

	if(file == NULL){
		return NULL;
	}

	int i; 
	int j; 
	int NumberSubjectsRead = 0;
	int registerElementRead = 0;
	int nameElementsRead = 0;

	char ***subjectsList;
	char readLine[BUFFER_SIZE];
	char *token;

	const char delimiter[DELIMITER_SIZE] = ";";

	bool isEOF = false;
	bool isSubjectsListNotComplete = false;
	bool areAllNameElementsAvoided = false;

	subjectsList = malloc(sizeof(char**) * studentsNumber);

	for(i = 0; i < studentsNumber; i++){
		subjectsList[i] = malloc(sizeof(char*) * SUBJECTS_NUMBER);
		for(j = 0; j < SUBJECTS_NUMBER; j++){
			subjectsList[i][j] = malloc(sizeof(char) * SUBJECT_NAME_SIZE);
		}
	}

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
	return subjectsList;
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

void printFileInformation(char ***subjectsList, char **namesList, int **gradesList, int studentsNumber){

	int i;
	int j;

	for(i = 0; i < studentsNumber; i++){
		printf("\nName : %s\n", namesList[i]);
		for(j = 0; j < SUBJECTS_NUMBER; j++){
			printf("Subject %d : %s  - Grade : %d \n", j+1, subjectsList[i][j] , gradesList[i][j]);
		}
	}
	
}
