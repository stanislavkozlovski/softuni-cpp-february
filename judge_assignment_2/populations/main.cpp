#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using std::map;

class City {
public:
    std::string name;
    std::string country;
    long long unsigned int population;

    City(std::string name, std::string country, long long unsigned int pop): name(name), country(country), population(pop) {}

};

map<long long unsigned int, City> readCities() {
    map<long long unsigned int, City> sortedCities;
    std::string line;
    std::ifstream myfile ("./test.txt");

    getline (myfile,line);  // empty line

    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            std::stringstream ss;
            std::string name, country;
            long long unsigned int population;
            ss << line;
            ss >> name >> country >> population;
            std::cout << name << " " << country << " " << population;
            sortedCities.insert(std::make_pair(population, City(name, country, population)));
        }
        myfile.close();
    }

    return sortedCities;
}
int main() {
    long long unsigned int low, high, m;
    long long unsigned int validCities = 0;
    std::cin >> low >> high >> m;
    std::cout << "Hello, Worlad!" << std::endl;
    map<long long unsigned int, City> sortedCities = readCities();
    for (std::map<long long unsigned int, City>::iterator it=sortedCities.begin(); it!=sortedCities.end(); ++it) {
        int currentCities = 0;
        long long unsigned int startRange = low * it->first;
        long long unsigned int endRange = high * it->first;
        std::cout << startRange << "---" << endRange << '\n';

        for(std::map<long long unsigned int, City>::iterator secondIt=sortedCities.lower_bound(startRange); secondIt!=sortedCities.end(); ++secondIt) {
            if (secondIt->first >= startRange && secondIt->first <= endRange && currentCities <= m) {
                currentCities++;
            } else {
                break;
            }
        }

        if (currentCities >= m) {
            validCities++;
        }
    }
    std::cout << "Answer is " << validCities;
    return 0;
}
