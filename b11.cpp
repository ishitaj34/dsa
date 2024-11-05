/* Dictionary stores keywords & its meanings. Provide facility for adding new keywords, 
deleting keywords, updating values of any entry. Provide facility to display whole data sorted in 
ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. 
Use Binary Search Tree for implementation. */

#include <iostream>

using namespace std;

class node {
	public:
		string k, v;
		node *left, *right;
		
		node() {
			left = NULL;
			k = " ";
			v = " ";
			right = NULL;
		}
};

class BST {
	public:
		node *temp, *root;
		
		BST() {
			root = NULL;
		}
		
		node* create(string key, string value) {
			temp = new node;
			
			if(temp == NULL) {
				cout << "\nMemory allocation failed." << endl;
				return 0;
			}
			else {
				temp->left = NULL;
				temp->k = key;
				temp->v = value;
				temp->right = NULL;
				
				return temp;
			}
		}
		
		void insert() {
			int n;
			string key, value;
			node *t, *p;
			
			t = new node;
			p = new node;
			
			cout << "\nEnter the number of elements to be inserted: ";
			cin >> n;
			
			for(int i = 0; i < n; i++) {
				cout << "\nEnter a word: ";
				cin >> key;
			
				cout << "Enter the meaning: ";
				cin >> value;
			
				if(root == NULL) {
					root = create(key, value);
					cout << "\nRoot created." << endl;
				}
				else {
					t = root;
					p = root;
					
					while(t != NULL) {
						p = t;
						if(t->k == key) {
							cout << "\nKey already exists." << endl;
							return;
						}
						else if(t->k < key) {
							t = t->right;
						}
						else {
							t = t->left;
						}
					}
					
					t = create(key, value);
					cout << "\nKey created." << endl;
					
					if(p->k < key) {
						p->right = t;
					}
					else {
						p->left = t;
					}
				}
			}
		}
		
		void ascending(node *t) {
			if(t == NULL) {
				return;
			}
			
			ascending(t->left);
			
			cout << "\n" << t->k << "\t" << t->v << endl;
			
			ascending(t->right);
		}
			
		void descending(node *t) {
			if(t == NULL) {
				return;
			}

			descending(t->right);
			
			cout << "\n" << t->k << "\t" << t->v << endl;
			
			descending(t->left);
		}
		
		void search() {
			string el;
			int flag;
			node *t;
			
			cout << "\nEnter the element to be updated: ";
			cin >> el;
			
			flag = 0;
			t = root;
			
			if(t == NULL) {
				cout << "\nTree does not exist. Updation not possible." << endl;
				return;
			}
			
			while(t != NULL) {
				if(t->k == el) {
					flag = 1;
					break;
				}
				else if(t->k < el) {
					t = t->right;
				}
				else {
					t = t->left;
				}
			}
			
			if(flag == 1) {
				cout << "\nGiven key exists in the tree." << endl;
				
				string new_val;
				cout << "\nEnter the updated meaning of the element: ";
				cin >> new_val;
				
				t->v = new_val;
				
				cout << "\nKey updated." << endl;
			}
			else {
				cout << "\nGiven key does not exist in the tree. Updation not possible." << endl;
			}
		}

        node* findMin(node* t) {
            while (t->left != NULL) {
                t = t->left;
            }
            return t;
        }

        node* del(node* t, string key) {
            t = root;

            if(t == NULL) {
                return t;
            }

            if(key < t->k) {
                t->left = del(t->left, key);
            }
            else if(key > t->k) {
                t->right = del(t->right, key);
            }
            else { 
                // node with only one child or no child
                if(t->left == NULL) {
                    node* temp = t->right;
                    delete t;
                    return temp;
                }
                else if(t->right == NULL) {
                    node* temp = t->left;
                    delete t;
                    return temp;
                }

                // node with two children, get the inorder successor (smallest in the right subtree)
                node* temp = findMin(t->right);

                // copy the inorder successor's content to this node
                t->k = temp->k;
                t->v = temp->v;

                // del the inorder successor
                t->right = del(t->right, temp->k);
            }
            return t;
        }

        void deleteKey(string key) {
            root = del(root, key);
        }
};

int main() {
	int ch, a;
	BST obj;
	
	cout << "\n\n***MENU***" << endl;
	cout << "1. Insert new elements in the dictionary" << endl;
	cout << "2. Sort dictionary elements" << endl;
	cout << "3. Search and update an element in the dictionary" << endl;
	cout << "4. Delete an element from the dictionary" << endl;
	
	a = 1;
	while(a == 1) {
		cout << "\nEnter your choice: ";
		cin >> ch;
		
		switch(ch) {
			case 1:
				obj.insert();
				break;

			case 2:
				int c;
				
				cout << "\nPress 1 to sort dictionary in ascending order and press 2 to sort dictionary in descending order: ";
				cin >> c;
				
				if(c == 1) {
					obj.ascending(obj.root);
				}
				else if(c == 2) {
					obj.descending(obj.root);
				}
				else {
					cout << "\nInavlid choice" << endl;
				}
				break;

			case 3:
				obj.search();
                break;

			case 4:
                {
                string del_key;

                cout << "\nEnter the key to be deleted: ";
                cin >> del_key;

                obj.deleteKey(del_key);
				break;
                }

			default:
				cout << "\nInvalid choice." << endl;
				break;
		}
		
		char ans;
		cout << "\nWould you like to choose again? (y/n): ";
		cin >> ans;
		
		if(ans == 'y') {
			a = 1;
		}
		else {
			a = 0;
			cout << "\nThank you!" << "\n";
		}
	}
}
