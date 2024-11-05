/* Consider a scenario for hospitals to cater services to different kinds of patients as Serious (top priority), non-serious (Medium Priority), 
and General checkup (Least Priority). Implement priority queue to cater services to the patients. */

#include <iostream>
using namespace std;

class node {
    public:
        string n;
        int p;
        node *next;

        node() {
            n = " ";
            p = 0;
            next = NULL;
        }
};

class queue {
    public:
        node *head, *temp;

        queue() {
            head = NULL;
        }

        node* create(string name, int priority);
        void enqueue();
        void display();
};

node* queue :: create(string name, int priority) {
    temp = new node;

    if(temp == NULL) {
        cout << "\nMemory allocation failed." << endl;
        return 0;
    }
    else {
        temp->n = name;
        temp->p = priority;
        temp->next = NULL;

        return temp;
    }
}

void queue :: enqueue() {
    string name;
    int priority;
    node *t, *prev;

    cout << "\nEnter the name of the patient: ";
    cin >> name;

    cout << "\nFor patient priority, enter 1 for serious, 2 for non-serious, and 3 for general check up." << endl;
    cout << "Enter the priority of the patient: ";
    cin >> priority;

    temp = create(name, priority);

    if(head == NULL || priority < head->p) {
        temp->next = head;
        head = temp;
    }
    else {
        t = head;
        prev = NULL;

        while(t != NULL && t->p <= priority) {
            prev = t;
            t = t->next;
        }

        if(prev != NULL) { 
            temp->next = prev->next;
            prev->next = temp;
        } 
        else { 
            temp->next = head;
            head = temp;
        }
    }
}

void queue :: display() {
    if(head == NULL) {
        cout << "\nQueue is empty." << endl;
        return;
    }
    
    node *t;
    t = head;

    cout << "\nPatients in the queue:" << endl;
    while(t != NULL) {
        cout << "\nName: " << t->n << endl;
        cout << "Priority: " << t->p << endl;

        t = t->next;
    }
}

int main() {
    int a, ch;
    char ans;

    queue obj;

    cout << "\n\n*** MENU ***\n";
    cout << "1. Add patient information" << endl;
    cout << "2. Display" << endl;

    a = 1;
    while(a == 1) {
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                obj.enqueue();
                break;

            case 2:
                obj.display();
                break;

            default:
                cout << "\nInvalid choice" << endl;
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
