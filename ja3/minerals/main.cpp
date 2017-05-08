#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int commandCenterX, commandCenterY;

bool manhattanDistanceComp(std::tuple<int, int> a, std::tuple<int, int> b) {
    int firstX = std::get<0>(a);
    int firstY = std::get<1>(a);
    int firstDist = abs(commandCenterX-firstX) + abs(commandCenterY-firstY);
    int secondX = std::get<0>(b);
    int secondY = std::get<1>(b);
    int secondDist = abs(commandCenterX-secondX) + abs(commandCenterY-secondY);

    return firstDist < secondDist;
}

int main() {
    int neededMinerals;
    std::cin >> neededMinerals;
    std::cin >> commandCenterX >> commandCenterY;
    int mineralCount;
    std::cin >> mineralCount;
    std::vector<std::tuple<int, int>> minerals;
    for (int i = 0; i < mineralCount; ++i) {
        int mineralX, mineralY;
        std::cin >> mineralX >> mineralY;
        minerals.push_back(std::make_tuple(mineralX, mineralY));
    }
    std::sort(minerals.begin(), minerals.end(), manhattanDistanceComp);
    int distanceCovered = 0;
    for (int j = 0; j < neededMinerals; ++j) {
        int currX = std::get<0>(minerals[j]);
        int currY = std::get<1>(minerals[j]);
        distanceCovered += (abs(commandCenterX-currX) + abs(commandCenterY-currY)) * 2;
    }
    std::cout << distanceCovered << std::endl;
    return 0;
}