#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "node.h"
using namespace std;
class StudentList {
public:
  StudentList();
  ~StudentList();
  void addStu();
  void addStu(Node*&);
  void printStu();
  void printStu(Node*);
  void delStu();
  void delStu(int, Node*, Node*);
  float calcAvg();
  float calcAvg(Node*, int&, float&);
  void quit();
private:
  Node* head;
};

#endif
