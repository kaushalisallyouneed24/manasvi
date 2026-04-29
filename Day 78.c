#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Adjacency list node
struct Node {
    int dest;
    int weight;
    struct Node* next;
};

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // Undirected graph: add both u->v and v->u
        struct Node* n1 = malloc(sizeof(struct Node));
        n1->dest = v; n1->weight = w; n1->next = adj[u]; adj[u] = n1;

        struct Node* n2 = malloc(sizeof(struct Node));
        n2->dest = u; n2->weight = w; n2->next = adj[v]; adj[v] = n2;
    }

    int* minWeight = (int*)malloc((n + 1) * sizeof(int));
    int* visited = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) minWeight[i] = INT_MAX;

    minWeight[1] = 0; // Start from node 1
    long long totalMSTWeight = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        int minVal = INT_MAX;

        // Pick the minimum weight unvisited node
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && minWeight[v] < minVal) {
                minVal = minWeight[v];
                u = v;
            }
        }

        if (u == -1) break; // Graph is disconnected

        visited[u] = 1;
        totalMSTWeight += minVal;

        // Update neighbors
        struct Node* curr = adj[u];
        while (curr) {
            int v = curr->dest;
            if (!visited[v] && curr->weight < minWeight[v]) {
                minWeight[v] = curr->weight;
            }
            curr = curr->next;
        }
    }

    printf("%lld\n", totalMSTWeight);

    return 0;
}
