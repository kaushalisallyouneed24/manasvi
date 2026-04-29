#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

int visited_count = 0;

void dfs(int u, struct Node** adj, int* visited) {
    visited[u] = 1;
    visited_count++;
    
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->dest]) {
            dfs(temp->dest, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Edge case: A graph with no nodes (or 1 node)
    if (n <= 1) {
        printf("CONNECTED\n");
        return 0;
    }

    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));
    int* visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Undirected graph: add both u->v and v->u
        struct Node* node1 = malloc(sizeof(struct Node));
        node1->dest = v;
        node1->next = adj[u];
        adj[u] = node1;

        struct Node* node2 = malloc(sizeof(struct Node));
        node2->dest = u;
        node2->next = adj[v];
        adj[v] = node2;
    }

    // Start DFS from node 1
    dfs(1, adj, visited);

    if (visited_count == n) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    // Cleanup omitted for brevity
    return 0;
}
