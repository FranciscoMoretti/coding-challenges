// A C++ program to find maximal
// Bipartite matching.
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int __i__, __j__;
#define printArr(a, l)                  \
    for (__i__ = 0; __i__ < l; __i__++) \
    {                                   \
        cout << a[__i__] << " ";        \
    }                                   \
    cout << endl

// M is number of applicants
// and N is number of jobs
#define M 8
#define N 8

// -------------------------------------------------------------------

// C++ Implementation of Kosaraju's algorithm to print all SCCs
class Graph
{
    int V;                                      // No. of vertices
    list<int> *adj;                             // An array of adjacency lists
    vector<vector<int>> m_connected_components; // connected components

    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing
    // time
    void fillOrder(int v, bool visited[], stack<int> &Stack);

    // A recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[], vector<int> &conected_component);

    bool isCyclicUtil(int v, bool visited[], bool *rs); // used by isCyclic()

public:
    Graph(int V);
    void addEdge(int v, int w);

    pair<int, int> getEdge();

    // The main function that finds and prints strongly connected
    // components
    vector<vector<int>> printSCCs();

    // Print graph edges
    void printGraph();

    bool isReachable(int s, int d);

    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();

    int edge_count = 0;
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[], vector<int> &connected_component)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    connected_component.push_back(v);

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited, connected_component);
}

// A BFS based function to check whether d is reachable from s.
bool Graph::isReachable(int s, int d)
{
    // Base case
    if (s == d)
        return true;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> stack;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    stack.push_back(s);

    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while (!stack.empty())
    {
        // Dequeue a vertex from queue and print it
        s = stack.back();
        stack.pop_back();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then
            // return true
            if (*i == d)
            {
                cout << "cycle: " << d << " " << s;

                for (auto &&v : stack)
                {
                    cout << " " << v;
                }
                cout << endl;
                return true;
            }

            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                stack.push_back(*i);
            }
        }
    }

    // If BFS is complete without visiting d
    return false;
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    edge_count++;
}

pair<int, int> Graph::getEdge()
{
    if (edge_count > 0)
    {
        int i = 0;
        while (adj[i].size() == 0)
        {
            i++;
        }
        return pair<int, int>(i, adj[i].front());
    }
    else
    {
        return pair<int, int>(-1, -1);
    }
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            fillOrder(*i, visited, Stack);

    // All vertices reachable from v are processed by now, push v
    Stack.push(v);
}

// The main function that finds and prints all strongly connected
// components
vector<vector<int>> Graph::printSCCs()
{
    stack<int> Stack;

    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Fill vertices in stack according to their finishing times
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            fillOrder(i, visited, Stack);

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // reset the components
    vector<vector<int>> m_connected_components = {};

    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            vector<int> connected_component = vector<int>();
            gr.DFSUtil(v, visited, connected_component);
            m_connected_components.push_back(connected_component);
            cout << endl;
        }
    }
    return m_connected_components;
}

void Graph::printGraph()
{
    for (size_t i = 0; i < this->V; i++)
    {
        cout << "From V : " << i << " to:";
        for (auto &&edge : adj[i])
        {
            cout << " " << edge;
        }
        cout << endl;
    }
}

// -------------------------------------------------------------------

// Ford fulkerson find maximum bipartite matching

// A DFS based recursive function
// that returns true if a matching
// for vertex u is possible
bool bpm(bool bpGraph[M][N], int u,
         bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in
        // job v and v is not visited
        if (bpGraph[u][v] && !seen[v])
        {
            // Mark v as visited
            seen[v] = true;

            // If job 'v' is not assigned to an
            // applicant OR previously assigned
            // applicant for job v (which is matchR[v])
            // has an alternate job available.
            // Since v is marked as visited in
            // the above line, matchR[v] in the following
            // recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v],
                                     seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number
// of matching from M to N
int maxBPM(bool bpGraph[M][N], int matchR[])
{
    // An array to keep track of the
    // applicants assigned to jobs.
    // The value of matchR[i] is the
    // applicant number assigned to job i,
    // the value -1 indicates nobody is
    // assigned.

    // Count of jobs assigned to applicants
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen
        // for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}

const vector<vector<char>> CORNER_CUBELETS = {
    {'U', 'F', 'R'},
    {'U', 'L', 'F'},
    {'U', 'B', 'L'},
    {'U', 'R', 'B'},
    {'D', 'R', 'F'},
    {'D', 'F', 'L'},
    {'D', 'L', 'B'},
    {'D', 'B', 'R'}};

vector<bool> corners_with_face(char face)
{
    vector<bool> corners_have_face(CORNER_CUBELETS.size(), false);
    for (size_t i = 0; i < CORNER_CUBELETS.size(); i++)
    {
        auto const &cc = CORNER_CUBELETS[i];
        if (std::find(cc.begin(), cc.end(), face) != cc.end())
        {
            corners_have_face[i] = true;
        }
    }
    return corners_have_face;
}

void enum_perfect_matching_iter(Graph &graph, vector<int> matching)
{
    // Step 1: If G has no edge, stop.
    if (graph.edge_count == 0)
    {
        return;
    }
    // Step 2: Choose an edge e
    pair<int, int> edge = graph.getEdge();
    // Step 3: Find a cycle containing e by a depth-first search algorithm.
    bool is_cycle = graph.isReachable(edge.second, edge.first);

    // auto cycle = ;
    // Step 4: Find a perfect matching M' by exchanging edges along the cycle.Output M'
    // auto matching_prime = matching.replace(rotate(cycle));
    // TODO: output matching_prime
}

int enum_perfect_matchings(bool bpGraph[M][N])
{
    int matchR[N];
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
    // Let us create a bpGraph
    // shown in the above example
    // bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0, 0, 0},
    //                       {1, 0, 0, 1, 0, 0, 0, 0},
    //                       {0, 0, 1, 0, 0, 0, 0, 0},
    //                       {0, 0, 1, 1, 0, 0, 0, 0},
    //                       {0, 0, 0, 0, 0, 0, 0, 0},
    //                       {0, 0, 0, 0, 0, 0, 0, 0},
    //                       {0, 0, 0, 0, 0, 0, 0, 0},
    //                       {0, 0, 0, 0, 0, 0, 0, 1}};

    // STEP 1: Find a perfect matching M of G and output M. If M is not found, stop.
    int max_bpm = maxBPM(bpGraph, matchR);
    cout << "Maximum number of applicants that can get job is " << max_bpm << endl;

    // Check if the maximum correspond to a perfect matching
    if (max_bpm < 8)
    {
        // No perfect matching!
        return -1;
    }
    else
    {
        for (size_t i = 0; i < max_bpm; i++)
        {
            cout << matchR[i] << " : ";
            printArr(CORNER_CUBELETS[i], 3);
        }
    }

    vector<int> matchRinv(8, -1);
    vector<int> matchRvec;
    for (size_t i = 0; i < matchRinv.size(); i++)
    {
        matchRinv[matchR[i]] = i;
        matchRvec.push_back(matchR[i]);
    }

    // STEP 2: Trim unnecessary edges from G by a strongly connected component
    // decomposition algorithm with D(G, M)
    Graph g(16);
    // Create D(G, M)
    for (size_t i = 0; i < CORNER_CUBELETS.size(); i++)
    {
        for (size_t j = 0; j < CORNER_CUBELETS.size(); j++)
        {
            if (bpGraph[i][j])
            {
                if (j == matchRinv[i])
                {
                    g.addEdge(j, i + 8);
                }
                else
                {
                    g.addEdge(i + 8, j);
                }
            }
        }
    }
    cout << "graph adjacency list: " << endl;
    g.printGraph();

    vector<vector<int>> connected_components = g.printSCCs();

    cout << "connected_components result: " << endl;
    for (auto &&i : connected_components)
    {
        cout << "comp: ";
        for (auto &&j : i)
        {
            cout << " " << j;
        }
        cout << endl;
    }

    // Reduced graph
    Graph g_trimmed(16);
    // Create D(G, M)
    for (auto &&cc : connected_components)
    {
        if (cc.size() < 2)
        {
            continue;
        }
        for (size_t i = 0; i < CORNER_CUBELETS.size(); i++)
        {
            if (std::find(cc.begin(), cc.end(), i + 8) == cc.end())
            {
                continue;
            }
            for (size_t j = 0; j < CORNER_CUBELETS.size(); j++)
            {
                if (bpGraph[i][j] && (std::find(cc.begin(), cc.end(), j) != cc.end()))
                {
                    if (j == matchRinv[i])
                    {
                        g_trimmed.addEdge(j, i + 8);
                    }
                    else
                    {
                        g_trimmed.addEdge(i + 8, j);
                    }
                }
            }
        }
    }

    cout << "graph adjacency list: " << endl;
    g_trimmed.printGraph();

    enum_perfect_matching_iter(g_trimmed, matchRvec);

    return 0;
}

// Driver Code
int main()
{
    // vector<vector<bool>> bpGraph = vector<vector<bool>>(M, vector<bool>(N, 0));
    bool bpGraph[M][N] = {false};
    // string input = "FFFFBBBB";
    // string input = "FFFUULLL";
    // string input = "FFFUULLB";
    string input = "FLUUFFLB";
    for (size_t i = 0; i < input.size(); i++)
    {
        auto marked_corners = corners_with_face(input[i]);
        for (size_t j = 0; j < marked_corners.size(); j++)
        {
            bpGraph[i][j] = marked_corners[j];
        }
    }

    enum_perfect_matchings(bpGraph);

    return 0;
}
