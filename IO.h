#ifndef IO_H
#define IO_H

void loadGrades(const char *fileName, int alumniNumber, int **gradesList);
void loadNames( const char *fileName, int alumniNumber, char **namesList);
void loadSubjectsNames( const char *fileName, int alumniNumber, char ***subjectsList);

char ***newSubjectsList(int studentsNumber);
char **newNamesList(int studentsNumber);
int **newGradesList(int studentsNumber);
int getStudentsNumber(const char *fileName);
void displayFileInformation(char ***subjectsList, char **namesList, int **gradesList, int studentsNumber);

void displayProgramOptions();

#endif // IO_H