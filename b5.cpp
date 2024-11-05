/* A book consists of chapters, chapters consist of sections and sections consist of subsections.
Construct a tree and print the nodes. */

#include <iostream>
#include <queue>

using namespace std;

class node {
    public:
        string s;
        node *left, *right;

        node() {
            s = " ";
            left = NULL;
            right = NULL;
        }
};

class tree {
    public:
        node *head, *temp;
        node *t1, *t2, *t3, *t4, *t5, *t6;

        queue<node*> q;

        tree() {
            head = NULL;
        }

        node* create(string str);
        void insertBook();
        void insertChap();
        void insertSec();
        void display();
};

node* tree :: create(string str) {
    temp = new node;

    if(temp == NULL) {
        cout << "\nMemory allocation failed." << endl;
        return 0;
    }
    else {
        temp->s = str;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
}

void tree :: insertBook() {
    string book;

    cout << "\nEnter the name of the book: ";
    cin >> book;

    temp = create(book);

    if(head == NULL) {
        head = temp;
        q.push(temp);
    }
    else {
        cout << "\nBook already exists. Root of tree cannot be created." << endl;
    }
}

void tree :: insertChap() {
    string chap;

    for(int i = 0; i < 2; i++) {
        chap = " ";
        cout << "\nEnter the name of the chapter: ";
        cin >> chap;

        if(head == NULL) {
            cout << "\nBook title missing. Chapters cannot be added." << endl;
        }
        else if(i == 0) {
            t1 = create(chap);

            head->left = t1;
            q.push(t1);
        }
        else {
            t2 = create(chap);

            head->right = t2;
            q.push(t2);
        }
    }
}

void tree :: insertSec() {
    string sec;

    for(int i = 0; i < 4; i++) {
        sec = " ";
        cout << "\nEnter the name of the section: ";
        cin >> sec;

        if(head == NULL) {
            cout << "\nBook title missing. Chapters cannot be added." << endl;
        }
        else {
            if(t1 != NULL) {
                if(i == 0) {
                    t3 = create(sec);

                    t1->left = t3;
                    q.push(t3);
                }

                if(i == 1) {
                    t4 = create(sec);

                    t1->right = t4;
                    q.push(t4);
                }
            }
            else {
                cout << "\nChapter 1 missing. Sections cannot be added." << endl;
            }

            if(t2 != NULL) {
                if(i == 2) {
                    t5 = create(sec);

                    t2->left = t5;
                    q.push(t5);
                }

                if(i == 3) {
                    t6 = create(sec);

                    t2->right = t6;
                    q.push(t6);
                }
            }
            else {
                cout << "\nChapter 2 missing. Sections cannot be added." << endl;
            }
        }
    }
}

void tree :: display() {
    queue<node*> level;

    level.push(head);

    cout << "\nLevel-wise display of tree nodes: \n";

    while(!level.empty()) {
        int size = level.size();

        for(int i = 0; i < size; i++) {
            node* current = level.front();
            level.pop();

            cout << current->s << " ";

            if(current->left != NULL) {
                level.push(current->left);
            }
            if(current->right != NULL) {
                level.push(current->right);
            }
        }
        cout << "\n"; 
    }
}


int main() {
    tree obj;
    int a, ch;
    char ans;

    cout << "\n\nMenu:\n" << endl;
    cout << "1. Insert book" << endl;
    cout << "2. Insert chapters" << endl;
    cout << "3. Insert sections" << endl;
    cout << "4. Display tree" << endl;
    cout << "\n" << endl;

    a = 1;
    while(a == 1) {
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                obj.insertBook();
                break;
            case 2:
                obj.insertChap();
                break;
            case 3:
                obj.insertSec();
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
            cout << "\nThank you!\n" << endl;
        }
    }
}
