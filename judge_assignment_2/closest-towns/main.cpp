#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <tuple>

using std::tuple;

class Vector2D {
public:
    double x;
    double y;
    std::string name;
    Vector2D() :
        x(0),
        y(0), name("") {
    }

    Vector2D(double x, double y, std::string name) :
        x(x),
        y(y), name(name) {
    }

    double getLength() const {
        return sqrt(getLengthSq());
    }

    double getLengthSq() const {
        return this->x * this->x + this->y * this->y;
    }
};

std::vector<Vector2D> readCities(int cityCount);
bool compareByX(const Vector2D& first, const Vector2D& second);
bool compareByY(const Vector2D& first, const Vector2D& second);
double getDistance(Vector2D v1, Vector2D v2);
tuple<Vector2D, Vector2D, double> findClosestDistBruteforce(std::vector<Vector2D> cities, int start, int end);
tuple<Vector2D, Vector2D, double> findClosestDist(std::vector<Vector2D>& cities, int start, int end);
tuple<Vector2D, Vector2D, double> findClosestDistMiddlePoints(std::vector<Vector2D> midPoints, double bestDist, tuple<Vector2D, Vector2D, double> bestPair);
tuple<Vector2D, Vector2D, double> getMinTwoPairs(const tuple<Vector2D, Vector2D, double>& firstPair, const tuple<Vector2D, Vector2D, double>& secondPair);
tuple<Vector2D, Vector2D, double> smartSolution(std::vector<Vector2D> cities);
tuple<Vector2D, Vector2D, double> stupidSolution(std::vector<Vector2D> cities);
double dblAbs(double a);

int main() {
    int inputLines;
    std::cin >> inputLines;
    std::vector<Vector2D> cities = readCities(inputLines);

//    tuple<Vector2D, Vector2D, double> closestCities = smartSolution(cities);
    tuple<Vector2D, Vector2D, double> closestCities = stupidSolution(cities);
    std::cout << std::get<0>(closestCities).name << "-" << std::get<1>(closestCities).name << std::endl;
    return 0;
}

tuple<Vector2D, Vector2D, double> stupidSolution(std::vector<Vector2D> cities) {
    double minDist = std::numeric_limits<double>::max();
    tuple<Vector2D, Vector2D, double> bestPair;

    for (int i = 0; i < cities.size(); ++i) {
        Vector2D firstCity = cities[i];
        for (int j = i+1; j < cities.size(); ++j) {
            Vector2D secondCity = cities[j];

            double citiesDist = getDistance(firstCity, secondCity);
            if (citiesDist < minDist) {
                minDist = citiesDist;
                bestPair = std::make_tuple(firstCity, secondCity, citiesDist);
            }
        }
    }

    return bestPair;
}
tuple<Vector2D, Vector2D, double> smartSolution(std::vector<Vector2D> cities) {
    // sort array according to X

    std::sort(cities.begin(), cities.end(), compareByX);
    tuple<Vector2D, Vector2D, double> closestCities = findClosestDist(cities, 0, cities.size());
    return closestCities;
};
tuple<Vector2D, Vector2D, double> findClosestDist(std::vector<Vector2D>& cities, int start, int end) {
    if (end-start <= 3) {
        // base case
        return findClosestDistBruteforce(cities, start, end);
    }

    int midPoint = start + ((end-start) / 2);
    tuple<Vector2D, Vector2D, double> leftPair = findClosestDist(cities, start, midPoint);
    tuple<Vector2D, Vector2D, double> rightPair = findClosestDist(cities, midPoint, end);
    tuple<Vector2D, Vector2D, double> bestPair = getMinTwoPairs(leftPair, rightPair);

    std::vector<Vector2D> middlePoints;
    Vector2D midCity = cities[midPoint];
    double bestPairDist = std::get<2>(bestPair);
    // find all the points whose X is closer than bestPair's X is to the middle vertical line
    for (int i = start; i < end; ++i) {
        if (dblAbs(midCity.x - cities[i].x) < bestPairDist) {
            middlePoints.push_back(cities[i]);
        }
    }

    tuple<Vector2D, Vector2D, double> closestMidPair = findClosestDistMiddlePoints(middlePoints, bestPairDist, bestPair);

    return getMinTwoPairs(bestPair, closestMidPair);
}

tuple<Vector2D, Vector2D, double> findClosestDistMiddlePoints(std::vector<Vector2D> midPoints, double bestDist, tuple<Vector2D, Vector2D, double> bestPair) {
    // sort by Y
    std::sort(midPoints.begin(), midPoints.end(), compareByY);

    for (int i = 0; i < midPoints.size(); ++i) {
        for (int j = i+1; j < midPoints.size() && (midPoints[j].y - midPoints[i].y) < bestDist; ++j) {
            // this loop is proven to iterate a max number of 6 times
            double currDist = getDistance(midPoints[j], midPoints[i]);
            if (currDist < bestDist) {
                bestDist = currDist;
                bestPair = std::make_tuple(midPoints[j], midPoints[i], currDist);
            }
        }
    }

    return bestPair;
}

tuple<Vector2D, Vector2D, double> findClosestDistBruteforce(std::vector<Vector2D> cities, int start, int end) {
    /* Finds the closest distance between a small number of cities */
    double minDist = std::numeric_limits<double>::max();
    tuple<Vector2D, Vector2D, double> bestPair;

    for (int i = start; i < end; ++i) {
        for (int j = i+1; j < end; ++j) {
            double citiesDist = getDistance(cities[i], cities[j]);
            if (citiesDist < minDist) {
                minDist = citiesDist;
                bestPair = std::make_tuple(cities[i], cities[j], minDist);
            }
        }
    }

    return bestPair;
}

tuple<Vector2D, Vector2D, double> getMinTwoPairs(const tuple<Vector2D, Vector2D, double>& firstPair, const tuple<Vector2D, Vector2D, double>& secondPair) {
    if (std::get<2>(firstPair) >= std::get<2>(secondPair)) {
        // always prefer the first pair :0
        return firstPair;
    }
    return secondPair;
}

double getDistance(Vector2D v1, Vector2D v2) {
    return sqrt((v1.x - v2.x) * (v1.x - v2.x)
              + (v1.y - v2.y) * (v1.y - v2.y));
}

bool compareByX(const Vector2D& first, const Vector2D& second) {
    return first.x < second.x;
}

bool compareByY(const Vector2D& first, const Vector2D& second) {
    return first.y < second.y;
}

std::vector<Vector2D> readCities(int cityCount) {
    std::vector<Vector2D> cities;

    for (int i = 0; i < cityCount; ++i) {
        std::string cityName;
        double x, y;
        std::cin >> cityName >> x >> y;
        cities.push_back(Vector2D(x, y, cityName));
    }

    return cities;
}

double dblAbs(double a) {
    if (a < 0) {
        a *= -1;
    }
    return a;
}