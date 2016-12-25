#ifndef IO_H
#define IO_H

int **loadGradesList(const char *fileName, int alumniNumber);
char **loadNamesList( const char *fileName, int alumniNumber);
char ***loadSubjectsList( const char *fileName, int alumniNumber);

char ***newSubjectsList(int studentsNumber);
char **newNamesList(int studentsNumber);
int **newGradesList(int studentsNumber);
int getStudentsNumber(const char *fileName);
void printFileInformation(char ***subjectsList, char **namesList, int **gradesList, int studentsNumber);

#endif // IO_H