#ifndef IO_H
#define IO_H

int **getGradesList(const char *fileName, int alumniNumber);
char **getNamesList( const char *fileName, int alumniNumber);
char ***getSubjectsList( const char *fileName, int alumniNumber);
int getStudentsNumber(const char *fileName);
void printFileInformation(char ***subjectsList, char **namesList, int **gradesList, int studentsNumber, int subjectsNumber);

#endif // IO_H