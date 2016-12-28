#ifndef SORT_H
#define SORTFUNCTIONS_H
#define MAX_LENGTH 10

// sort functions
void insertionSort( int **arrayToSort, int studentIndex, char ***subjectsList );
void bubbleSortLeft( int **gradesList, int studentIndex, char ***subjectsList);
void bubbleSortRight( int **gradesList, int studentIndex, char ***subjectsList );
void selectionSort( int **arrayToSort, int studentIndex, char ***subjectsList );
void shellSort( int **gradesList, int studentIndex, char ***subjectsList );

//the first three parametres are the requiered for the sort 
void mergeSort(int **gradesList, int lowPosition, int highPosition, int studentIndex, char ***subjectsList, char ***auxStringSubjectList);
//the first four parametres are the requiered for the sort 
void merge( int **gradesList, int lowPosition, int midPosition, int highPosition, int studentIndex, char ***subjectsList, char ***auxStringSubjectList);

//the first three parametres are the requiered for the sort 
void quicksort( int **gradesList, int firstPosition, int lastPosition, int studentIndex, char ***subjectsList);
void fastRecursive(int **gradesList, int firstPosition, int endPosition, int studentIndex, char ***subjectsList);

//sort the grades with the selected method
void sortGrades( int sortMethodSelected, int **gradesList, int studentsNumber, char ***subjectsList );

// get the positions agree with the, rename 
int *getSortedPositions(float *averagesList, int studentsNumber);

// calculate the student averages
float *calculateAverages(int **gradesList, int studentsNumber);

//it will be renamed, sort the averages
void sort(float *averagesList, int *positions, int studentsNumber);
#endif // SORT_H