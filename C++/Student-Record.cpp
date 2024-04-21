#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
struct node
{
    node* prev;
    info* store;
    node* next;
};
struct info
{
   string name;
   string rollno;
   string username;
   string password;
   string course;
};
class student_Record
{
    private:
        node* start;
    protected:
        void DELETE_FIRST();
    public:
        student_Record();
        void INSERT_DATA(string&,string&,string&,string&,string&);
        node* SEARCH_STUDENT(string&);
        void INSERT_AFTER_STUDENT(string&,string&,string&,string&,string&,node*);
        void DELETE_STUDENT(node*);
        ~student_Record();
        void SORT();
};
void student_Record :: SORT()
{
    node* t=start;
}
student_Record :: ~student_Record()
{
    while(start)
        DELETE_FIRST();
}
void student_Record :: DELETE_STUDENT(node* TEMP)
{
    node* t;
    if(TEMP)
    {
        TEMP->prev->next=TEMP->next;
        if(TEMP->next)
            TEMP->next->prev=TEMP->prev;
    }
}
void student_Record :: DELETE_FIRST()
{
    node* t;
    if(start)
    {
        t=start;
        start=t->next;
        start->prev=NULL;
        delete t->store;
        delete t;
    }
    t=NULL;
}
void student_Record :: INSERT_AFTER_STUDENT(string &NAME,string &ROLL,string &USERNAME,string &PASSWORD,string &COURSE,node* TEMP)
{
    node* N=new node;
    info* n=new info;
    n->name=NAME;
    n->rollno=ROLL;
    n->username=USERNAME;
    n->password=PASSWORD;
    n->course=COURSE;
    N->store=n;
    // SWAP pointer 
    N->next=TEMP->next;
    if(TEMP->next)
        TEMP->next->prev=N;
    TEMP->next=N;
    N->prev=TEMP;
}
node* student_Record :: SEARCH_STUDENT(string& ROLL)
{
    node* t=start;
    if(start)
    {
        while(t)
        {
            if(t->store->rollno==ROLL)
                return t;
            t=t->next;
        }
    }
    return NULL;
}
void student_Record :: INSERT_DATA(string &NAME,string &ROLL,string &USERNAME,string &PASSWORD,string &COURSE)
{
   info *n=new info;
   node *N=new node;
   n->name=NAME;
   n->rollno=ROLL;
   n->username=USERNAME;
   n->password=PASSWORD;
   n->course=COURSE;
   // insert information info. in node
   N->store=n;
   N->prev=NULL;
   N->next=NULL;
   if(start)
    {    
        N->next=start;
        start->prev=N;
    }
    start=N;
}
student_Record :: student_Record()          // Explicit Constructor
{
    start=NULL;
}