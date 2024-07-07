#include <iostream>

using namespace std;

const int MAX_VERTICES = 10000;
const int MAX_EDGES = 100000;

int adj[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

int stack[MAX_VERTICES];
int top = -1;

void push(int value) { stack[++top] = value; }

int pop() { return stack[top--]; }

bool isEmpty() { return top == -1; }

// Function Depth-First Search (DFS)
void dfs(int v, int numVertices) {
  push(v);
  visited[v] = true;

  while (!isEmpty()) {
    int current = pop();
    cout << "Processing commit " << current << endl;
    // Traverse all adjacent vertices
    for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
      if (adj[current][neighbor] == 1 && !visited[neighbor]) {
        visited[neighbor] = true;
        push(neighbor);
      }
    }
  }
}

int main() {

  int numVertices = 5;
  int numEdges = 4;

  for (int i = 0; i < numVertices; ++i) {
    for (int j = 0; j < numVertices; ++j) {
      adj[i][j] = 0;
    }
  }
  adj[0][1] = 1;
  adj[0][2] = 1;
  adj[1][3] = 1;
  adj[2][3] = 1;
  adj[3][4] = 1;

  fill(visited, visited + MAX_VERTICES, false);

  for (int i = 0; i < numVertices; ++i) {
    if (!visited[i]) {
      dfs(i, numVertices);
    }
  }
  return 0;
}
