#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 100 // Define the maximum number of buildings

using namespace std;

int dist[MAXN][MAXN]; // Distance matrix
int dp[1 << 20][20];  // DP table for memoization
int n, r, s, d;       // Variables for buildings, roads, start, and destination

// BFS to compute shortest paths from 'start' to all other buildings
void bfs(int start, vector<int> graph[]) {
  queue<int> q;
  q.push(start);
  dist[start][start] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    // Explore all neighbors of 'node'
    for (int neighbor : graph[node]) {
      // If this neighbor hasn't been visited from 'start'
      if (dist[start][neighbor] == -1) {
        dist[start][neighbor] = dist[start][node] + 1;
        q.push(neighbor);
      }
    }
  }
}

// Dynamic programming to find the minimum time
int solve(int mask, int current) {
  // If all buildings have been visited
  if (mask == (1 << n) - 1)
    return (current == d) ? 0 : MAXN;

  // Check if the state has already been computed
  if (dp[mask][current] != -1)
    return dp[mask][current];

  int answer = MAXN;
  // Try next building to visit
  for (int i = 0; i < n; i++) {
    // If building 'i' hasn't been visited yet
    if (!(mask & (1 << i)) && dist[current][i] != -1)
      answer = min(answer, solve(mask | (1 << i), i) + dist[current][i]);
  }

  return dp[mask][current] = answer;
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cin >> n >> r;
    vector<int> graph[MAXN]; // Graph representation
    memset(dist, -1, sizeof(dist)); // Initialize distances to -1
    memset(dp, -1, sizeof(dp));     // Initialize DP table to -1

    // Read roads and construct the graph
    for (int i = 0; i < r; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    cin >> s >> d; // Read start and destination buildings

    // Compute shortest paths from each building
    for (int i = 0; i < n; i++)
      bfs(i, graph);

    // Output the minimum time for each case
    cout << "Case " << t << ": " << solve(1 << s, s) << endl;
  }

  return 0;
}
