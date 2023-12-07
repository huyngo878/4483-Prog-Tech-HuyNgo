#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to reconstruct the path from source to destination
vector<string> reconstructPath(map<string, string>& parent, const string& source, const string& destination) {
    vector<string> path;
    string current = destination;

    // Backtrack from the destination to source using the parent map
    while (current != source) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(source);

    // Reverse the path to get the correct order from source to destination
    reverse(path.begin(), path.end());
    return path;
}

// Function to find the route between two cities using BFS
vector<string> findRoute(map<string, vector<string>>& graph, const string& source, const string& destination) {
    queue<string> q;
    map<string, string> parent;
    set<string> visited;

    // Start BFS from the source city
    q.push(source);
    visited.insert(source);
    parent[source] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        // If the destination is reached, reconstruct and return the path
        if (current == destination) {
            return reconstructPath(parent, source, destination);
        }

        // Traverse all adjacent cities
        for (const auto& neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
                parent[neighbor] = current; // Set the parent for backtracking
            }
        }
    }

    // Return an empty path if no route is found
    return {};
}

int main() {
    int n;
    string line;

    // Read input until the end of file or a zero is encountered
    while (getline(cin, line)) {
        stringstream ss(line);
        ss >> n;
        if (n == 0) break;

        map<string, vector<string>> graph;
        string city1, city2;

        // Construct the graph of cities and their connections
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            stringstream ss2(line);
            ss2 >> city1 >> city2;
            graph[city1].push_back(city2);
            graph[city2].push_back(city1);
        }

        string source, dest;
        getline(cin, line);
        stringstream ss3(line);
        ss3 >> source >> dest;

        // Find the route from source to destination
        vector<string> route = findRoute(graph, source, dest);

        // Print the route or indicate if no route is found
        if (route.empty()) {
            cout << "No route" << endl;
        } else {
            for (size_t i = 0; i < route.size() - 1; ++i) {
                cout << route[i] << " " << route[i + 1] << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
