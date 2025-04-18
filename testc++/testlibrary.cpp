#include <iostream>
#include <string>
using namespace std;
class LibraryItem {
protected:
    string title;
    string author;
    string dueDate;

public:
    string getTitle() const {
        return title;
    }
    string getAuthor() const {
        return author; 
    }
    string getDueDate() const {
        return dueDate; 
    }

    void setTitle(string newTitle) {
        title = newTitle; 
    }
    void setAuthor(string newAuthor) {
        author = newAuthor;
    }
    void setDueDate(string newDueDate) {
        dueDate = newDueDate; 
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    string ISBN;
public:
    Book(string title, string author, string dueDate, string isbn) {
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
        ISBN = isbn;
    }

    void checkOut() override {
        cout << "Book " << title << " checked out\n";
    }

    void returnItem() override {
        cout << "Book " << title << " returned\n";
    }

    void displayDetails() const override {
        cout <<"Book Title: "<<title<<", Author: "<<author<<", Due: "<<dueDate<<", ISBN: "<<ISBN<<endl;
    }
};

class DVD : public LibraryItem {
private:
    int duration; 
public:
    DVD(string title, string author, string dueDate, int duration) {
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
        this->duration = duration;
    }

    void checkOut() override {
        cout<<"DVD "<<title<<" checked out.\n";
    }

    void returnItem() override {
        cout<<"DVD "<<title<<" returned.\n";
    }

    void displayDetails() const override {
        cout<<"DVD Title: "<<title<<", Director: " <<author<< ", Due: "<<dueDate<<", Duration: "<<duration<<" mins\n";
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string title, string author, string dueDate, int issueNumber) {
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
        this->issueNumber = issueNumber;
    }

    void checkOut() override {
        cout<<"Magazine "<<title<<" checked out.\n";
    }

    void returnItem() override {
        cout<<"Magazine "<< title<<" returned.\n";
    }

    void displayDetails() const override {
        cout<<"Magazine Title: "<<title<<", Editor: "<<author<<", Due: " <<dueDate<<", Issue: "<<issueNumber<<endl;
    }
};

int main() {
    const int max_item = 100;
    LibraryItem* libraryItems[max_item];
    int itemCount = 0;
    int choice;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        try {
            string title, author, dueDate;
            switch (choice) {
                case 1: {
                    string isbn;
                    cout << "Enter title: "; getline(cin, title);
                    cout << "Enter author: "; getline(cin, author);
                    cout << "Enter due date: "; getline(cin, dueDate);
                    cout << "Enter ISBN: "; getline(cin, isbn);
                    if (isbn.length() <= 4){ 
                        throw runtime_error("Invalid ISBN.");
                    }
                    libraryItems[itemCount++] = new Book(title, author, dueDate, isbn);
                    break;
                }

                case 2: {
                    int duration;
                    cout << "Enter title: "; getline(cin, title);
                    cout << "Enter director: "; getline(cin, author);
                    cout << "Enter due date: "; getline(cin, dueDate);
                    cout << "Enter duration (minutes): "; cin >> duration;
                    libraryItems[itemCount++] = new DVD(title, author, dueDate, duration);
                    break;
                }

                case 3: {
                    int issue;
                    cout << "Enter title: "; getline(cin, title);
                    cout << "Enter editor: "; getline(cin, author);
                    cout << "Enter due date: "; getline(cin, dueDate);
                    cout << "Enter issue number: "; cin >> issue;
                    if (issue <= 0) {
                        throw runtime_error("Invalid issue number.");
                    }
                    libraryItems[itemCount++] = new Magazine(title, author, dueDate, issue);
                    break;
                }

                case 4:
                    for (int i = 0; i < itemCount; ++i)
                        libraryItems[i]->displayDetails();
                    break;

                case 5:
                    for (int i = 0; i < itemCount; ++i) {
                        cout << i << ": ";
                        libraryItems[i]->displayDetails();
                    }
                    cout << "Enter item number to check out: ";
                    int outIndex;
                    cin >> outIndex;
                    if (outIndex < 0 || outIndex >= itemCount) {
                        throw runtime_error("Invalid item index.");
                    }
                    libraryItems[outIndex]->checkOut();
                    break;

                case 6:
                    for (int i = 0; i < itemCount; ++i) {
                        cout << i << ": ";
                        libraryItems[i]->displayDetails();
                    }
                    cout<<"Enter item number to return: ";
                    int returnIndex;
                    cin >> returnIndex;
                    if (returnIndex < 0 || returnIndex >= itemCount) {
                        throw runtime_error("Invalid item index.");
                    }
                    libraryItems[returnIndex]->returnItem();
                    break;

                case 7:
                    for (int i = 0; i < itemCount; ++i)
                        delete libraryItems[i];
                    cout<<"Exiting... \n";
                    break;

                default:
                    cout<<"Invalid choice.\n";
            }
        } catch (exception& e) {
            cout<<"Error: "<<e.what()<<endl;
        }

    } while (choice != 7);

    return 0;
}