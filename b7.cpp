/* Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse it using 
post order traversal and then delete the entire tree. */

#include <iostream>
#include <stack>

using namespace std;

class node {
	public:
		char c;
		node *left, *right;
		
		node() {
			c = ' ';
			left = NULL;
			right = NULL;
		}
};

class ExpressionTree {
	public:
		node *temp, *root;
		
		ExpressionTree() {
			root = NULL;
		}
	
		node* create(char ch) {
			temp = new node;
			
			if(temp == NULL) {
				cout << "\nMemory allocation failed." << endl;
                return 0;
			}
			else {
				temp->left = NULL;
				temp->c = ch;
				temp->right = NULL;

                return temp;
			}
		}
		
		node* create_tree(string exp) {
			node *t1, *t2;
			
			stack<node*> op;
			
			for(int i = exp.size() - 1; i >= 0; i--) {
				 char t = exp[i];
				 
				 if(isalnum(t)) {
				 	op.push(create(t));
				 }
				 
				 if(t == '+' || t == '-' || t == '*' || t == '/') {
				 	temp = create(t);
				 	
				 	t1 = op.top();
				 	temp->left = t1;
				 	op.pop();
				 	
				 	t2 = op.top();
				 	temp->right = t2;
				 	op.pop();
				 	
				 	op.push(temp);
				 }
			}
			
			return op.top();
		}
		
		void postorder(node* root) {
			node *p;
			
			stack<node*> s;
			
			if(root == NULL) {
				cout << "\nExpression tree does not exist." << endl;
				return;
			}
			
			s.push(root);
			
			while(!s.empty()) {
				p = s.top();
				s.pop();
				
				if(p->left) {
					s.push(p->left);
				}
				if(p->right) {
					s.push(p->right);
				}

                cout << p->c << " ";
			}
		}

        void delete_tree(node* root) {
            if(root == NULL) { 
                return;
            }

            delete_tree(root->left);
            delete_tree(root->right);
            delete root;
        }
};


int main() {
	ExpressionTree obj;
	
	string exp;
	cout << "\nEnter a prefix expression: ";
	cin >> exp;
	
	node* root = obj.create_tree(exp);

	cout << "\nPost Order Traversal: ";
    obj.postorder(root);
    cout << endl;
    cout << "\n";

    obj.delete_tree(root);

    return 0;
}
