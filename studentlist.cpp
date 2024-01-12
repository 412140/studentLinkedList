#include "studentlist.h"
#include "node.h"
#include "student.h"
#include <iostream>
#include <iomanip>
using namespace std;
//basically completely rewrote it all, had the recursion down but separated everything into its own file

StudentList::StudentList() 
{
  head = nullptr;
}

StudentList::~StudentList() 
{
  while (head) {
    Node* temp = head;
    head = head->getNext();
    delete temp;
  }
}
void StudentList::addStu()
{
  char fName[30];
  char lName[40];
  int studentId;
  float gpa;

  cout << "Enter first name: ";
  cin >> fName;

  cout << "Enter last name: ";
  cin >> lName;

  cout << "Enter student ID: ";
  cin >> studentId;

  cout << "Enter GPA: ";
  cin >> gpa;

  addStu(head, fName, lName, studentId, gpa);
}

void StudentList::addStu(Node* currentNode, char* fName, char* lName, int studentId, float gpa) 
{
  if (!currentNode || currentNode->getStudent()->getStudentId() > studentId) 
  {
    Node* newStudentNode = new Node(new Student(fName, lName, studentId, gpa));
    newStudentNode->setNext(currentNode);
    currentNode = newStudentNode;
    head = newStudentNode;  // Update head when adding at the beginning
  } else {
    addStu(currentNode->getNext(), fName, lName, studentId, gpa);
  }
}

void StudentList::printStu() 
{
  printStu(head);
}

void StudentList::printStu(Node* currentNode) 
{
  if (currentNode) 
  {
    cout << currentNode->getStudent()->getFirstName() << " "
         << currentNode->getStudent()->getLastName() << ", "
         << currentNode->getStudent()->getStudentId() << ", "
         << fixed << setprecision(2) << currentNode->getStudent()->getGPA() << endl;
    printStu(currentNode->getNext());
  }
}

void StudentList::delStu() 
{
  int studentIdToDelete;
  cout << "Enter student ID to remove: ";
  cin >> studentIdToDelete;
  delStu(studentIdToDelete, head, nullptr_t());
}

void StudentList::delStu(int studentId, Node* currentNode, Node* prevNode) 
{
  if (currentNode) 
  {
    if (currentNode->getStudent()->getStudentId() == studentId) 
    {
      if (prevNode) 
      {
        prevNode->setNext(currentNode->getNext());
      } else {
        head = currentNode->getNext();
      }
      delete currentNode;
    } else {
      delStu(studentId, currentNode->getNext(), currentNode);
    }
  } else {
    cout << "Entry not found." << endl;
  }
}

float StudentList::calcAvg() 
{
  int totalStudents = 0;
  float totalGPA = 0.0;
  float average = calcAvg(head, totalStudents, totalGPA);

  if (totalStudents == 0) 
  {
    cout << "No students found." << endl;
    return 0.0;
  } 
  else 
  {
    cout << "Average GPA: " << fixed << setprecision(2) << average << endl;
    return average;
  }
}

float StudentList::calcAvg(Node* currentNode, int& totalStudents, float& totalGPA) 
{
  if (currentNode) 
  {
    totalGPA += currentNode->getStudent()->getGPA();
    totalStudents++;
    calcAvg(currentNode->getNext(), totalStudents, totalGPA);
  }

  return (totalStudents == 0) ? 0.0 : totalGPA / totalStudents;
}
//cleanup
void StudentList::quit() 
{
  Node* temp = head;
  while (temp) 
  {
    Node* nextNode = temp->getNext();
    delete temp;
    temp = nextNode;
  }
}
