#ifndef IO_H
#define IO_H


// load the info in the created lists
void loadGrades(const char *fileName, int alumniNumber, int **gradesList);
void loadNames( const char *fileName, int alumniNumber, char **namesList);
void loadSubjectsNames( const char *fileName, int alumniNumber, char ***subjectsList);

//create new lists
char ***newSubjectsList(int studentsNumber);
char **newNamesList(int studentsNumber);
int **newGradesList(int studentsNumber);

//students number
int getStudentsNumber(const char *fileName);

//show all file information
void displayFileInformation(char ***subjectsList, char **namesList, int **gradesList, int studentsNumber);

//show program options
void displayProgramOptions();

//show sort options
void displaySortOptions();

//add new student register in the file 
void addRegisterFile(char *filename, char *studentName, int gradesList[], char **subjectsNames);

//get the subjects names
char **getSubjectsNames(const char *filename);

//print the students information in the destination file
void printToFile(char **namesList, int **gradesList, char ***subjectsList, float *averagesList, int studentsNumber, int *positions, char *dstFilename);

#endif // IO_H