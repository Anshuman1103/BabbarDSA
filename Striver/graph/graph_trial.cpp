#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> unweighedGraph() {
  cout << "Enter the graph" << endl;
  int n, m;
  cout << "Enter numbers of node" << endl;
  cin >> n;
  cout << "Enter numbers of edges" << endl;
  cin >> m;
  vector<vector<int>> graph(n + 1);

  cout << "Enter the edges " << endl;
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

void graphBFS(vector<vector<int>> &graph, int startNode) {
  vector<int> visitedArray(graph.size(), 0);
  queue<int> q;
  q.push(startNode);
  visitedArray[startNode] = 1;
  while (!q.empty()) {
    int temp = q.front();
    cout << temp << " ";

    for (auto node : graph[temp]) {
      if (visitedArray[node] == 0) {
        visitedArray[node] = 1;
        q.push(node);
      }
    }
    q.pop();
  }
}

void DFS(vector<vector<int>> &graph, int &startNode, vector<int> &visitedArray,
         vector<int> &ans) {
  if (visitedArray[startNode] == 0) {
    visitedArray[startNode] = 1;
    ans.push_back(startNode);
    for (auto node : graph[startNode]) {
      DFS(graph, node, visitedArray, ans);
    }
  }
  return;
}

void graphDFS(vector<vector<int>> &graph, int startNode) {
  int n = graph.size();
  vector<int> visitedArray(n + 1, 0);
  vector<int> ans;
  DFS(graph, startNode, visitedArray, ans);
}

int main() {
  vector<vector<int>> graph = unweighedGraph();
  graphBFS(graph, 3);
  return 0;
}