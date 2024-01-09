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
  Node* newStudentNode = new Node(new Student());
  addStu(newStudentNode);
}

void StudentList::addStu(Node*& newNode) 
{
  if (!head || head->getStudent()->getStudentId() > newNode->getStudent()->getStudentId()) 
  {
    newNode->setNext(head);
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->getNext() && temp->getNext()->getStudent()->getStudentId() < newNode->getStudent()->getStudentId()) 
    {
      temp = temp->getNext();
    }
    newNode->setNext(temp->getNext());
    temp->setNext(newNode);
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

void StudentList::delStu(int studentId, Node*& currentNode, Node* prevNode) 
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
  return calcAvg(head, totalStudents, totalGPA);
}

float StudentList::calcAvg(Node* currentNode, int& totalStudents, float& totalGPA) 
{
  if (currentNode) 
  {
    totalGPA += currentNode->getStudent()->getGPA();
    totalStudents++;
    calcAvg(currentNode->getNext(), totalStudents, totalGPA);
  }
  if (totalStudents == 0) 
  {
    cout << "No students found." << endl;
    return 0.0;
  }
  return totalGPA / totalStudents;
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