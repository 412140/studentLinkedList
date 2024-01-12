#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "node.h"
using namespace std;
class StudentList {
public:
  StudentList();
  ~StudentList();
  void addStu();
  void addStu(Node*, char*, char*, int, float);
  void printStu();
  void printStu(Node*);
  void delStu();
  void delStu(int, Node*, Node*);
  void quit();
  float calcAvg();
  float calcAvg(Node*, int&, float&);

private:
  Node* head;
};

#endif
