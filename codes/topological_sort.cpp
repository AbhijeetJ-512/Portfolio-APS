#include <iostream>

using namespace std;

const int MAX_VERTICES = 10000;
const int MAX_EDGES = 100000;

int adj[MAX_VERTICES][MAX_VERTICES];
int inDegree[MAX_VERTICES];

void topologicalSort(int numVertices) {
  int result[MAX_VERTICES];
  int resultIndex = 0;
  bool visited[MAX_VERTICES] = {false};

  for (int i = 0; i < numVertices; ++i) {
    for (int j = 0; j < numVertices; ++j) {
      if (adj[i][j] == 1) {
        ++inDegree[j];
      }
    }
  }

  for (int i = 0; i < numVertices; ++i) {
    if (inDegree[i] == 0 && !visited[i]) {
      result[resultIndex++] = i;
      visited[i] = true;

      for (int j = 0; j < numVertices; ++j) {
        if (adj[i][j] == 1) {
          --inDegree[j];
        }
      }

      i = -1;
    }
  }
  // Print the topological order
  cout << "Topological Order of Jobs:" << endl;
  for (int i = 0; i < resultIndex; ++i) {
    cout << result[i] << " ";
  }
  cout << endl;
}

int main() {
  int numVertices = 6;
  int numEdges = 6;

  for (int i = 0; i < numVertices; ++i) {
    for (int j = 0; j < numVertices; ++j) {
      adj[i][j] = 0;
    }
  }

  adj[5][2] = 1;
  adj[5][0] = 1;
  adj[4][0] = 1;
  adj[4][1] = 1;
  adj[2][3] = 1;
  adj[3][1] = 1;

  for (int i = 0; i < numVertices; ++i) {
    inDegree[i] = 0;
  }

  topologicalSort(numVertices);

  return 0;
}
