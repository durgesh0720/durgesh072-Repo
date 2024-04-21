#include "Library_Manage.cpp"
int main()
{
    librarian lb;
    string c="c+";
    student st;
    string author,title,isbn,name,id;
    cout<<"Enter title,author,isbn"<<endl;
    cin>>title>>author>>isbn;
    lb.Add_Book(title,author,isbn);
    lb.SEARCH_TITLE(c);
    // cout<<"Enter your name,title,id"<<endl;
    // cin>>name>>title>>id;
    // st.Book_issue(name,id,title);
    // st.Check_Transactions();
    return 0;
}