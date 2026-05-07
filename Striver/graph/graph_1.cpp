#include <iostream>
#include <vector>

using namespace std;

/**
 * REPRESENTATION 1: ADJACENCY MATRIX
 * 
 * An Adjacency Matrix is a 2D array of size (N+1) x (N+1), where N is the number of nodes.
 * If there is an edge between node 'u' and 'v', we store 1 (or the weight) at adj[u][v].
 * 
 * Pros: Easy to understand, constant time to check if an edge exists.
 * Cons: Uses a lot of space (O(N^2)). Not good for large number of nodes.
 */

void adjacencyMatrixUndirected() {
    cout << "\n--- Adjacency Matrix (Undirected, Unweighted) ---\n";
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // We use n+1 size so we can use 1-based indexing (nodes 1 to n)
    // We initialize the entire matrix to 0 in one line
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        // Since it's UNDIRECTED, if there's an edge u-v, 
        // it means we can go from u to v AND from v to u.
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Printing the matrix
    cout << "The Adjacency Matrix is:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void adjacencyMatrixDirectedWeighted() {
    cout << "\n--- Adjacency Matrix (Directed, Weighted) ---\n";
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Initialize a (n+1) x (n+1) matrix with all values as 0
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    cout << "Enter " << m << " edges with weights (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        // Since it's DIRECTED, it only goes from u to v.
        // We store the WEIGHT instead of 1.
        adj[u][v] = w;
    }

    cout << "The Matrix (each value is the weight):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << adj[i][j] << " ";
        cout << endl;
    }
}


/**
 * REPRESENTATION 2: ADJACENCY LIST
 * 
 * An Adjacency List is an array of vectors. Each index 'i' in the array 
 * represents a node, and the vector at that index contains its neighbors.
 * 
 * Pros: Space efficient (O(N + 2E) for undirected, O(N + E) for directed).
 * Cons: Takes more time to check if a specific edge exists compared to Matrix.
 */

void adjacencyListUndirected() {
    cout << "\n--- Adjacency List (Undirected, Unweighted) ---\n";
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Creating an array of vectors: vector<int> adj[n+1]
    // Or better: a vector of vectors
    vector<vector<int>> adj(n + 1);

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        // For undirected, add u to v's list AND v to u's list
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Printing the List
    cout << "The Adjacency List structure:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

void adjacencyListDirectedWeighted() {
    cout << "\n--- Adjacency List (Directed, Weighted) ---\n";
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // To store weights, we use pairs: vector<pair<node, weight>>
    vector<vector<pair<int, int>>> adj(n + 1);

    cout << "Enter " << m << " edges with weights (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        // Directed: only u -> v. We store {neighbor, weight}
        adj[u].push_back({v, w});
    }

    // Printing
    cout << "The Adjacency List (Node -> {Neighbor, Weight}):\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (auto it : adj[i]) {
            cout << "{" << it.first << ", " << it.second << "} ";
        }
        cout << "\n";
    }
}

void adjacencyListUndirectedWeighted() {
    cout << "\n--- Adjacency List (Undirected, Weighted) ---\n";
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    cout << "Enter " << m << " edges with weights (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        // Undirected: add both ways with weights
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "The Adjacency List (Node -> {Neighbor, Weight}):\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (auto it : adj[i]) {
            cout << "{" << it.first << ", " << it.second << "} ";
        }
        cout << "\n";
    }
}

void adjacencyListDirected() {
    cout << "\n--- Adjacency List (Directed, Unweighted) ---\n";
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        // Directed: only u -> v
        adj[u].push_back(v);
    }

    cout << "The Adjacency List structure:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    cout << "Graph Basics for Beginners\n";
    cout << "1. Adjacency Matrix (Undirected)\n";
    cout << "2. Adjacency Matrix (Directed Weighted)\n";
    cout << "3. Adjacency List (Undirected Unweighted)\n";
    cout << "4. Adjacency List (Undirected Weighted)\n";
    cout << "5. Adjacency List (Directed Unweighted)\n";
    cout << "6. Adjacency List (Directed Weighted)\n";
    cout << "7. Exit\n";
    
    while(true) {
        cout << "\nSelect an option (1-7): ";
        cin >> choice;
        
        if(choice == 1) adjacencyMatrixUndirected();
        else if(choice == 2) adjacencyMatrixDirectedWeighted();
        else if(choice == 3) adjacencyListUndirected();
        else if(choice == 4) adjacencyListUndirectedWeighted();
        else if(choice == 5) adjacencyListDirected();
        else if(choice == 6) adjacencyListDirectedWeighted();
        else break;
    }

    return 0;
}