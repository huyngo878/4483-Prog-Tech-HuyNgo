#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<char>> grid;
std::vector<std::vector<bool>> visited;

int floodFill(int x, int y, int M, int N) {
    if (x < 0 || x >= M || y < 0 || y >= N || grid[x][y] != 'l' || visited[x][y]) {
        return 0;
    }

    visited[x][y] = true;
    return 1 + floodFill(x + 1, y, M, N) + floodFill(x - 1, y, M, N) +
           floodFill(x, y + 1, M, N) + floodFill(x, y - 1, M, N);
}

int main() {
    int M, N, mijidX, mijidY;
    
    while (std::cin >> M >> N) {
        grid.assign(M, std::vector<char>(N));
        visited.assign(M, std::vector<bool>(N, false));
        std::vector<int> regionSizes;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cin >> grid[i][j];
            }
        }
        
        std::cin >> mijidX >> mijidY;

        // First, mark Mijid's current region as visited to exclude it from the counts
        floodFill(mijidX, mijidY, M, N);
        
        // Then, process the grid to find other regions and their sizes
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 'l' && !visited[i][j]) {
                    int size = floodFill(i, j, M, N);
                    regionSizes.push_back(size);
                }
            }
        }
        
        // Find the largest region size
        int largestRegion = regionSizes.empty() ? 0 : *std::max_element(regionSizes.begin(), regionSizes.end());
        
        // Output the result
        std::cout << largestRegion << std::endl;
    }
    return 0;
}
