#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &adj, int node, vector<int> &visited,
         stack<int> &st) {
  for (auto neighbor : adj[node]) {
    if (visited[neighbor] == 0) {
      visited[neighbor] = 1;
      dfs(adj, neighbor, visited, st);
    }
  }
  st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &adj) {
  int n = adj.size();
  vector<int> visited(n + 1, 0);
  stack<int> st;

  for (int i = 1; i < n; i++) {
    if (visited[i] == 0) {
      visited[i] = 1;
      dfs(adj, i, visited, st);
    }
  }

  vector<int> ans;
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
}

int main() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1, vector<int>());

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
}