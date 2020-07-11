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

// Driver Code
int main()
{
    // vector<vector<bool>> bpGraph = vector<vector<bool>>(M, vector<bool>(N, 0));
    bool bpGraph[M][N] = {false};
    // string input = "FFFFBBBB";
    // string input = "FFFUULLL";
    string input = "FFFUULLB";
    for (size_t i = 0; i < input.size(); i++)
    {
        auto marked_corners = corners_with_face(input[i]);
        for (size_t j = 0; j < marked_corners.size(); j++)
        {
            bpGraph[i][j] = marked_corners[j];
        }
    }
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

    int max_bpm = maxBPM(bpGraph, matchR);
    cout << "Maximum number of applicants that can get job is " << max_bpm << endl;

    // Check if the maximum correspond to a perfect matching
    if (max_bpm == 8)
    {
        for (size_t i = 0; i < max_bpm; i++)
        {
            cout << input[matchR[i]] << " : ";
            printArr(CORNER_CUBELETS[i], 3);
        }
    }

    return 0;
}
