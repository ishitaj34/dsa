/* Given sequence k = k1 <k2 < … < kn of n sorted keys, with a search probability pi for each key ki. Build the Binary search tree that has the 
least search cost given the access probability for each key? (Optimal Binary Search Tree) */

#include <iostream>
using namespace std;

#define max 10

class OBST {
   public:
      int p[max], q[max], w[10][10], c[10][10], r[10][10], i, j, k, n, m;  // w = weight, c = cost, r = root
      
      char idnt[7][10];
      
      void read() {
         cout << "\nEnter number of identifiers: ";
         cin >> n;
         
         cout << "\nEnter identifiers:" << endl;
         for(i = 1; i <= n; i++) {
            cin >> idnt[i];
         }
         
         cout << "\nEnter success probabilty for identifiers:" << endl;
         for(i = 1; i <= n; i++) {
            cin >> p[i];
         }
         
         cout << "\nEnter failure probabilty for identifiers:" << endl;
         for(i = 0; i <= n; i++) {
            cin >> q[i];
         }
         
         cout << "\n\n  Weight    Cost    Root\n";
         
         for(i = 0; i <= n; i++) {
            w[i][i] = q[i];
            c[i][i] = r[i][i] = 0;
            
            cout << "\n  " << w[i][i] << "    " << c[i][i] << "    " << r[i][i];
            cout << "----------------------------------------------------------";
          }
          
          for(i = 0; i < n; i++) {
            j = i + 1;
            
            w[i][j] = p[j] + q[i] + q[j];
            c[i][j] = q[i] + c[i][j-1] + c[j][j];
            r[i][j] = j;
            
            cout << "\n  " << w[i][j] << "    " << c[i][j] << "    " << r[i][j];
            cout << "----------------------------------------------------------";
          }
          
          for(m = 2; m <= n; m++) {
            for(i = 0; i <= n; i++) {
                j = i + m;
                
                w[i][j] = w[i][j-1] + p[i] + q[j];
                
                k = find(i, j);              
                
                c[i][j] = w[i][j] + c[i][k-1] + c[k][j];
                r[i][j] = k;

                cout << "\n  " << w[i][j] << "    " << c[i][j] << "    " << r[i][j];
                cout << "----------------------------------------------------------";
            }
          }
          
          cout << "\n\nOBST:\n";
          display(0, n);
        }
        
        int find(int i, int j) {
            int min = 2000, m, l;
            
            for(m = i+1; m <= j; m++) {
                if((c[i][m-1] + c[m][j]) < min) {
                    min = c[i][m-1] +c[m][j];
                    l = m;
                }
            }
            
            return l;
         }
         
         void display(int i, int j) {
            if(i<j) {
                cout << "\n" << idnt[r[i][j]];
            }
            else {
                return;
            }
            
            display(i, r[i][j]-1);
            display(r[i][j], j);
          }
};

int main() {
    OBST obj;
    
    obj.read();
    obj.display(0, obj.n);
}
