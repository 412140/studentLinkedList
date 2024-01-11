#ifndef STUDENT_H
#define STUDENT_H
//#include "node.h"
using namespace std;

//initial sl was done with structs, this project uses a class

class Student {

public:
  Student();
  Student(const char*, const char*, int, float);
  ~Student();
  char* getFirstName();
  char* getLastName();
  int getStudentId();
  float getGPA();
  void setFirstName(const char*);
  void setLastName(const char*);
  void setStudentId(int);
  void setGPA(float);
private:
  char* firstName;
  char* lastName;
  int studentId;
  float gpa;
};

#endif
