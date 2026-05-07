#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*
8 8
1 2
1 6
2 3
2 4
6 7
6 8
4 5
7 5
*/

vector<vector<int>> unweighedGraph() {
  cout << "Enter the graph" << endl;
  int n, m;
  // cout << "Enter numbers of node" << endl;
  cin >> n;
  // cout << "Enter numbers of edges" << endl;
  cin >> m;
  vector<vector<int>> graph(n + 1);

  // cout << "Enter the edges " << endl;
  for (int i = 0; i < m; i++) {
    int p, q;
    cin >> p >> q;
    graph[p].push_back(q);
    graph[q].push_back(p);
  }

  cout << "Graph is :" << endl;
  for (int i = 1; i <= m; i++) {
    cout << i << " : ";
    for (auto edge : graph[i]) {
      cout << edge << " ";
    }
    cout << endl;
  }
  return graph;
}

// Space complexity = O(3N) -> visited array + queue + result array
// Time complexity = o(N + 2E)
void graphBFS(vector<vector<int>> &graph, int startNode) {
  int size = graph.size();
  vector<int> visited(size, 0); // visited array
  queue<int> q;
  q.push(startNode);
  visited[startNode] = 1;
  cout << "Printing BFS : " << endl;
  while (!q.empty()) { //-> N
    int curr = q.front();
    cout << curr << " ";
    for (auto node : graph[curr]) { // -> 2E
      if (!visited[node]) {
        q.push(node);
        visited[node] = 1;
      }
    }
    q.pop();
  }
}

void dfs(vector<vector<int>> &graph, int startNode, vector<int> &visitedArray,
         vector<int> &result) {
  if (!visitedArray[startNode]) {
    visitedArray[startNode] = 1;
    result.push_back(startNode);
    for (auto node : graph[startNode]) {
      dfs(graph, node, visitedArray, result);
    }
  }
}

void graphDFS(vector<vector<int>> graph, int startNode) {
  vector<int> visitedArray(graph.size() + 1, 0);
  vector<int> result;

  dfs(graph, startNode, visitedArray, result);

  cout << "Printing DFS :" << endl;
  for (auto node : result) {
    cout << node << " ";
  }
}

int main() {
  vector<vector<int>> graph = unweighedGraph();
  graphBFS(graph, 6);
  cout << endl;
  graphDFS(graph, 6);
  return 0;
}