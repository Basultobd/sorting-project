#ifndef SORT_H
#define SORTFUNCTIONS_H
#define MAX_LENGTH 10

// sort functions
void insertionSort( int **arrayToSort, int studentIndex, char ***subjectsList );
void bubbleSortLeft( int **gradesList, int studentIndex, char ***subjectsList);
void bubbleSortRight( int **gradesList, int studentIndex, char ***subjectsList );
void selectionSort( int **arrayToSort, int studentIndex, char ***subjectsList );
void shellSort( int **gradesList, int studentIndex, char ***subjectsList );

 
void mergeSort(int **gradesList, int lowPosition, int highPosition, int studentIndex, char ***subjectsList, char ***auxStringSubjectList);
void merge( int **gradesList, int lowPosition, int midPosition, int highPosition, int studentIndex, char ***subjectsList, char ***auxStringSubjectList);

//the first three parametres are the requiered for the sort 
void quicksort( int **gradesList, int firstPosition, int lastPosition, int studentIndex, char ***subjectsList);
void fastRecursive(int **gradesList, int firstPosition, int endPosition, int studentIndex, char ***subjectsList);

//print function
void printGradesList( int **arrayToSort, int i);

//display sort options 
void displaySortOptions();

//sort the grades with the selected method
void sortGrades( int sortMethodSelected, int **gradesList, int studentsNumber, char ***subjectsList );

#endif // SORT_H