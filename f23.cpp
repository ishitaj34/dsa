/* Department maintains a student information. The file contains roll number, name, division, and address. Allow user to add delete information 
of student. Display information of particular student. If record of student does not exist an appropriate message is displayed. If it is, then 
the system displays the student details. Use sequential file to maintain the data. */

#include <iostream>
#include <fstream>

using namespace std;

typedef struct student {
    int rollno;
    char name[50];
    char div;
    char add[50];
} student;

class Database {
    public:
        string filename = "student_data.dat";

        Database() {
            fstream fileobj(filename); // 'fileobj' object opens 'filename' file

            if(fileobj.fail()) {
                fileobj.open(filename, ios :: out);
                cout << "\nNew file created." << endl;
            }
            else {
                cout << "\nFile already exists." << endl;
            }

            fileobj.close();
        }

        void add();
        void del();
        void display();
        void search();
};

void Database :: add() {
    student s;

    cout << "\nEnter roll no. of the student: ";
    cin >> s.rollno;

    cout << "\nEnter the name of the student: ";
    cin.ignore();
    cin.getline(s.name, 50);

    cout << "\nEnter division: ";
    cin >> s.div;

    cout << "\nEnter the address: ";
    cin.ignore();
    cin.getline(s.add, 100);

    ofstream file(filename, ios :: out | ios :: binary | ios :: app);
    file.write((char*) &s, sizeof(student)) << flush;

    if(file.fail()) {
        cout << "\nFailed to add record." << endl;
    }
    else {
        cout << "\nRecord added successfully." << endl;
    }
    file.close();
}

void Database :: del() {
    student s;

    int roll;
    bool status = false;

    cout << "\nEnter roll no. to be deleted: ";
    cin >> roll;

    // opens the database file for reading in binary mode
    ifstream readfile;
    readfile.open(filename, ios :: in | ios :: binary);

    // opens a temporary file for writing to store records other than the one to be deleted
    ofstream writefile;
    writefile.open("~" + filename, ios :: out | ios :: binary);
    writefile.clear();

    while(readfile.read((char*) &s, sizeof(student))) {
        if(s.rollno == roll) {
            status = true;
        }
        else {
            writefile.write((char*) &s, sizeof(student)) << flush;
        }
    }
    readfile.close();
    writefile.close();

    if(status){
        readfile.open("~" + filename, ios :: in | ios :: binary);

        writefile.open(filename, ios :: out | ios :: binary);
        writefile.clear();

        // copies contents of the temporary file into the database file
        writefile << readfile.rdbuf();

        readfile.close();
        writefile.close();

        cout << "\nRecord deleted." << endl;
    }
    else {
        cout << "\nRecord not found." << endl;
    }
}

void Database :: display() {
    student s;

    int count = 0;

    ifstream file;
    file.open(filename, ios :: in | ios :: binary);

    while(file.read((char*) &s, sizeof(student))) {
        count++;

        cout << count << ". ";
        cout << s.rollno << " | ";
        cout << s.name << " | ";
        cout << s.div << " | ";
        cout << s.add << endl;
    }

    if(count == 0) {
        cout << "\nNo records found." << endl;
    }
    file.close();
}

void  Database :: search() {
    student s;

    int roll;
    bool status = false;

    cout << "\nEnter roll number to be searched: ";
    cin >> roll;

    ifstream readfile;
    readfile.open(filename, ios :: in | ios :: binary);

    while(readfile.read((char*) &s, sizeof(student))) {
        if(s.rollno == roll){
            status = true;
            break;
        }
    }
    readfile.close();

    if(status) {

        cout << "\nFile record with details: " << endl;
        cout << "Roll no.: " << s.rollno << endl;
        cout << "Name: " << s.name << endl;
        cout << "Div: " << s.div << endl;
        cout << "Address: " << s.add << endl;
    }
    else {
        cout << "\nNo record found." << endl;
    }
}


int main() {
    Database obj;

    int a, ch;
    char ans;

    cout << "\n\n*** MENU ***\n";
    cout << "1. Add record" << endl;
    cout << "2. Delete record" << endl;
    cout << "3. Search record" << endl;
    cout << "4. Display all records" << endl;

    a = 1;
    while(a == 1) {
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                obj.add();
                break;

            case 2:
                obj.del();
                break;

            case 3:
                obj.search();
                break;

            case 4:
                obj.display();
                break;

            default:
                cout << "\nInvalid choice." << endl;
                break;
        }

        cout << "\nWould you like to choose again? (y/n): ";
        cin >> ans;

        if(ans == 'y') {
            a = 1;
        }
        else {
            a = 0;
            cout << "\nThank you!\n";
        }
    }
}
