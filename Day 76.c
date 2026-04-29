#include <stdio.h>
#include <stdlib.h>

// Structure for Adjacency List Node
struct Node {
    int dest;
    struct Node* next;
};

// DFS function to mark all nodes in a component
void dfs(int u, struct Node** adj, int* visited) {
    visited[u] = 1;
    struct Node* temp = adj[u];
    while (temp) {
        int v = temp->dest;
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize Adjacency List and Visited array
    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));
    int* visited = (int*)calloc(n + 1, sizeof(int));

    // Build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Add edge u -> v
        struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
        newNode1->dest = v;
        newNode1->next = adj[u];
        adj[u] = newNode1;

        // Add edge v -> u (Undirected)
        struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
        newNode2->dest = u;
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    int componentCount = 0;

    // Traverse all nodes
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // New unvisited node found = New component
            componentCount++;
            dfs(i, adj, visited);
        }
    }

    printf("%d\n", componentCount);

    // Cleanup memory (optional in competitive programming but good practice)
    for (int i = 1; i <= n; i++) {
        struct Node* curr = adj[i];
        while (curr) {
            struct Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(adj);
    free(visited);

    return 0;
}
