/* Represent a given graph using adjacency matrix/list to perform DFS and using list to perform BFS. Use the map of the area around the college 
as the graph. Identify the prominent landmarks as nodes and perform DFS and BFS on that. */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class graph {
	public:
		int matrix[10][10];
		int v, e;
		int v1, v2;
		
		void read() {
			for(int i = 1; i <= 10; i++) {
				for(int j = 1; j <= 10; j++) {
					matrix[i][j] = 0;
				}
			}
			
			cout << "\nEnter the number of vertices: ";
			cin >> v;
			
			cout << "\nEnter the number of edges: ";
			cin >> e;
			
			for(int i = 1; i <= e; i++) {
				cout << "\nEnter vertex 1: ";
				cin >> v1;
				
				cout << "Enter vertex 2: ";
				cin >> v2;
				
				add_edge(v1, v2);
			}
		}

		void add_edge(int v1, int v2) {
			matrix[v1][v2] = 1;
			matrix[v2][v1] = 1;
		}
		
		void display() {
			cout << "\n\n";
			for(int i = 1; i <= v; i++) {
				for(int j = 1; j <= v; j++) {
					cout << matrix[i][j] << " ";
				}
				cout << "\n" << endl;
			}
		}

		void dfs(int start) {
        	stack<int> stack;
			bool visited[10] = {false};

        	stack.push(start);
			visited[start] = true;

        	cout << "\nDFS traversal starting from node " << start << ": ";

        	while (!stack.empty()) {
            	int node = stack.top();
            	stack.pop();

            	cout << node << " ";

            	for(int i = 0; i < v; i++) {
                	if(matrix[node][i] && !visited[i]) {
                    	stack.push(i);
                    	visited[i] = true;
                	}
            	}
        	}
        	cout << endl;
    	}

		void bfs(int start) {
        	queue<int> queue;
			bool visited[10] = {false};

        	queue.push(start);
        	visited[start] = true;

        	cout << "\nBFS traversal starting from node " << start << ": ";

        	while (!queue.empty()) {
            	int node = queue.front();
            	queue.pop();
				
            	cout << node << " ";

            	for(int i = 0; i < v; i++) {
                	if(matrix[node][i] && !visited[i]) {
                    	queue.push(i);
                    	visited[i] = true;
                	}
            	}
        	}
       	 	cout << endl;
    	}
};

int main() {
	graph g;
	
	g.read();
	g.display();
	
	int startnode;
	cout << "\nEnter starting node for traversal: ";
	cin >> startnode;

	g.dfs(startnode);
	g.bfs(startnode);
}
