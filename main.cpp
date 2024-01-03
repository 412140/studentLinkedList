//#include <vector>
#include "node.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
/*
ghazi abbas
fall semester C++ second part of linked lists/student list project
galbraith

sources:

*/
//fxn proto types
void addStu(Node* &head);
void delStu(Node* &head, int studentId);
void printStu(const Node* head);
float calcAvg(const Node* head, int &count, float &total);

struct Student //struct 
{
  char fName[30];
  char lName[40];
  int stId;
  float gpa;
};




int main()
{
  Node* head = NULL; // linked list head
  char cmd[20];
  int stId;


  while(true)
  {
    cout << "ennter command: quit, add, print, delete, avg";
    cin >> cmd;
    if(strcmp(cmd, "quit")==0)
    {

      while (head != NULL) 
      {
        Node* temp = head;
        head = head->getNext();
        delete temp;
      }

      break; //got it :) cleaning up allocated memory.
    } else if(strcmp(cmd, "add")==0) {
      
      addStu(head);
      
    } else if(strcmp(cmd, "print")==0) {
      printStu(head);
    
    }  else if(strcmp(cmd, "delete")==0) {
      cout << "enter student ID NUMBER to delete";
      cin >> stId;
      delStu(head, stId);
    
    
    } else if(strcmp(cmd,"avg")==0) {

      int count = 0;
      float total = 0.0;

      float average = calcAvg(head, count, total);
      cout << "GPA Average: " << fixed << setprecision(2) << average << endl;
    } else { cout << "unidentified command word (or my code doesnt work ) Try again." <<endl;}
      
  }
  return 0;
} 
  


//Mr Galbraith teaching us how to fxn prototype and write functions without code erroring

  void addStu(Node* &head)
  {
    Student* newStudent = new Student();
    cout << "Enter first name: ";
    cin >> newStudent->fName;
    cout << "Enter last name: ";
    cin >> newStudent->lName;
    cout << "Enter student ID: ";
    cin >> newStudent->stId;
    cout << "Enter GPA: ";
    cin >> newStudent->gpa;
    //ez stuff out of the way..
    /*
    Inserting the new student node into LL, sorting by stId
    */
     if (head == nullptr || newStudent->stId < head->getStudent()->stId) 
     {
        Node* newNode = new Node(newStudent);
        newNode->setNext(head);
        head = newNode;
    } else {
        Node* current = head;
        while (current->getNext() != nullptr && newStudent->stId > current->getNext()->getStudent()->stId) 
        {
            current = current->getNext();
        }
        Node* newNode = new Node(newStudent);
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }
  }

void delStu(Node*& head, int studentId)
{
  if (head == nullptr) //in case 
    {
        cout << "List already clear" << endl;
        return;
    }

    if (head->getStudent()->studentId == studentId) 
    {
        Node* temp = head;
        head = head->getNext();
        delete temp;
        cout << "Entry with ID " << studentId << " was removed." << endl;
        return;
    }

    Node* current = head;
    while (current->getNext() != nullptr && current->getNext()->getStudent()->studentId != studentId) 
    {
        current = current->getNext();
    }

    if (current->getNext() == nullptr) 
    {
        cout << "Student with ID " << studentId << " not found." << endl;
        return;
    }

    Node* temp = current->getNext();
    current->setNext(temp->getNext());
    delete temp;
    cout << "Student with ID " << studentId << " deleted." << endl;
}


void printStu(const Node* head)
{
 if (head == NULL) 
 {
        cout << "No students to pritn" << endl;
    } else {
        cout << "Student List:" << endl;
        while (head != NULL) 
        {
            cout << head->getStudent()->firstName << " " << head->getStudent()->lastName << ", "
                 << head->getStudent()->stId << ", " << fixed << setprecision(2)
                 << head->getStudent()->gpa << endl;
            head = head->getNext();
        }
    }
  
  
}

float calcAvg(const Node* head, int& count, float& total)
{
  if (head == nullptr) 
  {
    int count = 0;
    int total = 0.0;
    return 0.0;
  }

    count++;
    total += head->getStudent()->gpa;
    return calcAvg(head->getNext(), count, total) + head->getStudent()->gpa;

}