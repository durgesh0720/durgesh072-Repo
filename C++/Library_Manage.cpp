#include<iostream>
#include<stdio.h>
using namespace std;
struct book         // Define structure for book details
{
    string title;
    string author;
    string ISBN;
    bool availability;
    book *next;
};
struct transaction                      // that list contain information of transaction
{
    string name;
    string id;
    string ISBN;
    transaction* next;
};
class Library                  
{
    private:
        book* Head;
    protected:                                          // That methods can use only by inherit in Librarian class
        void AddBook(string,string,string);          
        void RemoveBook(string,string,string);
        book* search_title(string);
        book* search_isbn(string);
    public:
        ~Library();
        Library();
        void SEARCH_TITLE(string);
        void SEARCH_AUTHOR(string);
        void SEARCH_ISBN(string);
};
Library::~Library() 
{
    while (Head) 
        RemoveBook(Head->title, Head->author, Head->ISBN);
}

book* Library :: search_isbn(string ISBN)
{
    book* t;
    if(Head)
    {
        t=Head;
        while(t)
        {
            if(t->ISBN==ISBN)
                return t;
            t=t->next;
        }
    }
    return NULL;
}
book* Library :: search_title(string TITLE)              // SEARCH book by TITLE and return book of node address
{
    book* t;
    if(Head)
    {
        t=Head;
        while(t)
        {
            if(t->title==TITLE)
                return t;
            t=t->next;
        }
    }
    return NULL;
}
void Library::RemoveBook(string TITLE, string AUTHOR, string ISBN) 
{
    book* t = Head;
    book* prev = NULL;
    while (t) 
    {
        if (t->title == TITLE && t->author == AUTHOR && t->ISBN == ISBN) 
        {
            if(prev) 
                prev->next = t->next;
            else 
                Head = t->next;
            delete t;
            return;
        }
        prev = t;
        t = t->next;
    }
    cout << "Book not found!" << endl;
}
void Library :: SEARCH_ISBN(string ISBN)                                // book search by ISBN
{
    book* t;
    int i=0;
    if(Head)
    {
        t=Head;
        while(t)
        {
            if(t->ISBN==ISBN)
            {   i++;
                cout<<i<<" : Book Founded!  As per given: "<<ISBN<<endl;                  // All books with that name will be printed
                cout<<"Book title:  "<<t->title<<endl;
                cout<<"Book author: "<<t->author<<endl;
                cout<<"Book ISBN:   "<<t->ISBN<<endl;
                if(t->availability)
                    cout<<"Book status: Available"<<endl;
                else
                    cout<<"Book status: Not Available"<<endl;
            }
            t=t->next;
        }
        if(i==0)
            cout<<"Books not founded!\n";
    }
}

void Library :: SEARCH_AUTHOR(string AUTHOR)                              // Search book by AUTHOR name
{
    book* t;
    int i=0;
    if(Head)
    {
        t=Head;
        while(t)
        {
            if(t->author==AUTHOR)
            {   i++;
                cout<<i<<" : Book Founded!  As per given: "<<AUTHOR<<endl;                  // All books with that name will be printed
                cout<<"Book title:  "<<t->title<<endl;
                cout<<"Book author: "<<t->author<<endl;
                cout<<"Book ISBN:   "<<t->ISBN<<endl;
                if(t->availability)
                    cout<<"Book status: Available"<<endl;
                else
                    cout<<"Book status: Not Available"<<endl;
            }
            t=t->next;
        }
        if(i==0)
            cout<<"Books not founded!\n";
    }
}

void Library :: SEARCH_TITLE(string TITLE)                           // Search book by title
{
    book* t;
    int i=0;
    if(Head)
    {
        t=Head;
        while(t)
        {
            if(t->title==TITLE)
            {   i++;
                cout<<i<<" : Book Founded!\n";                  // All books with that name will be printed
                cout<<"Book title:  "<<t->title<<endl;
                cout<<"Book author: "<<t->author<<endl;
                cout<<"Book ISBN:   "<<t->ISBN<<endl;
                if(t->availability)
                    cout<<"Book status: Available"<<endl;
                else
                    cout<<"Book status: Not Available"<<endl;
            }
            t=t->next;
        }
        if(i==0)
            cout<<"Books not founded!\n";
    }
}

void Library :: AddBook(string TITLE,string AUTHOR,string ISBN)
{
    book* n= new book;
    n->title=TITLE;
    n->author=AUTHOR;
    n->ISBN=ISBN;
    n->availability=true;
    n->next=Head;
    Head=n;
}

Library :: Library()
{
    Head=NULL;
}

class librarian : public Library        // Librarian class methods for Add books and remove books
{
    private:
        transaction* start;
    protected:
        void Book_Checkout(string,string,string);
        void return_book(string,string,string);
        void check_transaction();
    public:
        librarian();
        void Add_Book(string,string,string);
        void Remove_Book(string,string,string);
        ~librarian();
};
librarian::~librarian() 
{
    while (start) 
    {
        transaction* t = start;
        start = t->next;
        delete t;
    }
}
void librarian::check_transaction() 
{
    transaction* t = start;
    while (t) 
    {
        SEARCH_ISBN(t->ISBN);
        t = t->next;
    }
}
void librarian :: return_book(string NAME,string ID,string ISBN)             // Return book methods
{
    transaction *t,*r;
    book* temp;
    if(start)
    {
        t=start;
        if(t->ISBN==ISBN)
        {
            temp=search_isbn(ISBN);
            temp->availability=true;
            cout<<"Book returned successfully!"<<endl; 
            r=t;
        }
        else
        {
            while(t->next)
            {
                if(t->next->ISBN==ISBN)
                {
                    temp=search_isbn(ISBN);
                    temp->availability=true;
                    cout<<"Book returned successfully!"<<endl; 
                    t->next=t->next->next;
                    r=t->next;
                }
                t=t->next;
            }
            delete r;               // delete book history from student database
        }
    }
    else
        cout<<"No transactions!"<<endl;
}
void librarian :: Book_Checkout(string NAME,string ID,string TITLE)       
{
    book* t;
    t=search_title(TITLE);
    if(t!=NULL)
    {
        if(t->availability)
        {
            transaction* n=new transaction;
            n->name=NAME;
            n->id=ID;
            n->ISBN=t->ISBN;
            n->next=start;
            start=n;
            cout<<"Book issued!"<<endl;
            t->availability=false;
        }
        else
            cout<<"Book is not available\n";
    }
    else
        cout<<"Book not found!\n";
}
void librarian :: Remove_Book(string TITLE,string AUTHOR,string ISBN)
{
    RemoveBook(TITLE,AUTHOR,ISBN);
}

void librarian :: Add_Book(string TITLE,string AUTHOR,string ISBN)
{
    AddBook(TITLE,AUTHOR,ISBN);
}

librarian :: librarian():start(NULL)
{       }

class student : protected librarian                        // Student class to give access of library
{
    public:
        student();
        void Book_issue(string,string,string);
        void Return_Book(string,string,string);
        void Check_Transactions();
};
void student :: Check_Transactions()
{
    check_transaction();
}
void student :: Return_Book(string NAME,string ID,string ISBN)
{
    return_book(NAME,ID,ISBN);
}
void student :: Book_issue(string NAME,string ID,string TITLE)
{
    Book_Checkout(NAME,ID,TITLE);
}
student :: student():librarian()
{   }
