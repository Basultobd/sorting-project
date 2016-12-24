#ifndef SORT_H
#define SORTFUNCTIONS_H
#define MAX_LENGTH 10

// sort functions
void insertionSort( int **arrayToSort, int studentIndex, char ***subjectsList );
void bubbleSortLeft( int **gradesList, int studentIndex, char ***subjectsList);
void bubbleSortRight( int **gradesList, int studentIndex, char ***subjectsList );
void selectionSort( int **arrayToSort, int studentIndex, char ***subjectsList );
void shellSort( int **gradesList, int studentIndex, char ***subjectsList );



void mergeSort(int arrayToSort[MAX_LENGTH], int lowPosition, int highPosition );
void merge( int arrayToSort[ MAX_LENGTH ], int lowPosition, int midPosition, int highPosition);
void quicksort( int arrayToSort[MAX_LENGTH], int firstPosition, int lastPosition);
void fastRecursive(int arrayToSort[MAX_LENGTH], int firstPosition, int endPosition);

// //print function
// void printGradesList( int **arrayToSort, int i);

//display sort options 
void displaySortOptions();

//sort the grades with the selected method
void sortGrades( int sortMethodSelected, int **gradesList, int studentsNumber, char ***subjectsList );

#endif // SORT_H