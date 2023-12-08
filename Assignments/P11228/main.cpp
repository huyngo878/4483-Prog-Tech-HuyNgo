#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};


struct Edge {
    int from, to;
    double cost;
    Edge(int from, int to, double cost) : from(from), to(to), cost(cost) {}

    // Operator overloading for sorting
    bool operator<(const Edge& e) const {
        return cost < e.cost;
    }
};

std::vector<int> parent;

int findParent(int index) {
    if (index == parent[index])
        return index;
    return parent[index] = findParent(parent[index]);
}

double distance(const Point& first, const Point& second) {
    int x = first.x - second.x;
    int y = first.y - second.y;
    return std::hypot(x, y);
}

int main() {
    int caseNum;
    std::cin >> caseNum;
    int caseCount = 1;
    while (caseNum-- > 0) {
        int cityNum;
        double threshold;
        std::cin >> cityNum >> threshold;

        std::vector<Point> cityList(cityNum);
        for (int i = 0; i < cityNum; i++) {
            int x, y;
            std::cin >> x >> y;
            cityList[i] = Point(x, y);
        }

        std::vector<Edge> edgeList;
        for (int i = 1; i < cityNum; i++) {
            for (int j = 0; j < i; j++) {
                edgeList.push_back(Edge(i, j, distance(cityList[i], cityList[j])));
            }
        }
        std::sort(edgeList.begin(), edgeList.end());

        parent.resize(cityNum);
        for (int i = 0; i < cityNum; i++) {
            parent[i] = i;
        }

        int stateNum = cityNum;
        double routeDistance = 0, railDistance = 0;
        for (Edge& e : edgeList) {
            int fromParent = findParent(e.from);
            int toParent = findParent(e.to);

            if (fromParent != toParent) {
                if (threshold >= e.cost) {
                    parent[fromParent] = toParent;
                    routeDistance += e.cost;
                    stateNum--;
                } else {
                    parenat[fromParent] = toParent;
                    railDistance += e.cost;
                }
            }
        }

        std::cout << "Case #" << caseCount++ << ": " << stateNum << " "
                  << static_cast<int>(std::round(routeDistance)) << " "
                  << static_cast<int>(std::round(railDistance)) << std::endl;
    }
    return 0;
}
