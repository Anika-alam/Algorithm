#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
#include <list>
#include <utility>
using namespace std;

#define SIZE 102
#define INF 2147483647

bool visited[SIZE];
int D[SIZE];    // Distance array
int P[SIZE];    // Parent array
int L[SIZE];    // Component label array
vector<int> A[SIZE];    // Adjacency lists

int k;               //initial value for counting the component length
int level_counter;  //initial value for numbering the component as label
int n;
// Initialize the arrays with default values before graph traversals

void initialize_arrays(int n)
{
    for(int i = 0; i < n; ++i)
        visited[i] = false, D[i] = INF, P[i] = -1;
}


// Add the undirected edge (u, v) to the graph

void add_edge(int u, int v)
{
    // Your code
    A[u].push_back(v);
    A[v].push_back(u);

}


// Breadth-First Search from source vertex 's'

void BFS(int s)
{
    // Your code
    queue<int> Q;

    Q.push(s);
    D[s] = 0, P[s] = -1, visited[s] = true;

    while(Q.empty() == false)
    {
        int u = Q.front();
        Q.pop();
        L[u]=level_counter;  //label numbering
        for(int i = 0; i < A[u].size(); ++i)
        {
            int v = A[u][i];
            if(visited[v] == false)
            {
                k=k+1;
                Q.push(v);
                D[v] = D[u] + 1;
                P[v] = u;
                visited[v] = true;
            }
        }
    }

}


// Depth-First Search from vertex 'u'
bool flag=false;
void DFS(int u)
{
    // Your code

    visited[u] = true;
    for(int i = 0; i < A[u].size(); ++i)
    {
        int v = A[u][i];
        if(visited[v] == false)
        {
            P[v]=u;
            DFS(v);
        }
         else
        {
            if(P[u] != v)
                flag=true;
        }
    }
}


// Returns true or false accordingly to whether the vertex 'v' is reachable from the vertex 'u'
// through some path

bool is_reachable(int n, int u, int v)
{
    // Your code

    initialize_arrays(n);
    BFS(u);
    if(P[v]== -1 && v != u)
        return false;

    if(P[v]== P[u])
        return true;

    if(P[v]== u)
        return true;

    is_reachable(n,u,P[v]);


}
// Returns the shortest path distance from vertex 'u' to vertex 'v'.

int shortest_path(int n, int u, int v)
{
   // Your code
    initialize_arrays(n);
    BFS(u);

    return D[v];

}


// Prints the shortest path from vertex 'u' to vertex 'v'.

void print_path(int v)
{
    // Your code

    if(P[v]== -1)
    {
        printf("%d ",v);
         return;
    }
    print_path(P[v]);
    printf("%d ",v);

}


// Returns true or false according to whether the graph contains a cycle or not.
bool has_cycle(int n)
{
    // Your code
    initialize_arrays(n);
     for(int j=0; j < n; j++)
    {
        if(visited[j]==false)
        {
            DFS(j);
        }
    }
    return flag;
}


// Returns the count of the connected components at the graph.

int count_components(int n)
{
    // Your code
   initialize_arrays(n);
    int count=0;

    for(int j=0; j < n; j++)
    {
        if(visited[j]==false)
        {
            BFS(j);
            count++;
        }
    }

    return count;
}


// Prints the connected component sizes of the graph (in any order).

void component_sizes(int n)
{
    // Your code
    k=1;

    printf("component size are: ");
    initialize_arrays(n);
    for(int j=0; j < n; j++)
    {
        if(visited[j]==false)
        {
           BFS(j);
           printf(" %d",k);
           k=1;
        }
    }
    printf("\n\n");


}


// For each of the vertices, prints the component number of which it is part of.

void label_components(int n)
{
    // Your code
     printf("not done yet!!!");



}



int main()
{
    int n, opCode, u, v;

    printf("Enter vertex count = ");
    scanf("%d", &n);
    printf("\n");


    printf("\nOperation Codes:\n");
    printf("1: Add Edge\n");
    printf("2: Reachability\n");
    printf("3: Shortest Path\n");
    printf("4: Cycle Detection\n");
    printf("5: Count Connected Components\n");
    printf("6: Component Sizes\n");
    printf("7: Label Components\n");




    printf("Anything else: Exit\n");
    printf("\n");


    while(true)
    {
        printf("Enter a choice:\n");
        scanf("%d", &opCode);

        if(opCode == 1)
        {
            printf("Enter u and v\n");
            scanf("%d %d", &u, &v);
            add_edge(u, v);
        }
        else if(opCode == 2)
        {
            printf("Enter u and v\n");
            scanf("%d %d", &u, &v);

            if(is_reachable(n, u, v))
                printf("%d and %d are connected.\n", u, v);
            else
                printf("%d and %d are not connected.\n", u, v);
        }
        else if(opCode == 3)
        {
            printf("Enter u and v\n");
            scanf("%d %d", &u, &v);

            int d = shortest_path(n, u, v);

            if(d == INF)
                printf("There's no path between %d and %d.\n", u, v);
            else
            {
                printf("Shortest path distance: %d\n", d);
                printf("Shortest path: ");
                print_path(v);
                printf("\n");
            }
        }
        else if(opCode == 4)
            printf("%s\n", has_cycle(n) ? "The graph contains cycle(s)" :
                       "The graph do not contain any cycle.");

        else if(opCode == 5)
            printf("Number of connected components = %d\n", count_components(n));
        else if(opCode == 6)
            component_sizes(n);
        else if(opCode == 7)
            label_components(n);


        else
            break;
    }

    return 0;
}
