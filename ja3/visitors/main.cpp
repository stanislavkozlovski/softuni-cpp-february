#include <iostream>
#include <map>
#include <unordered_set>
#include <sstream>
#include <algorithm>

using std::string;


class User {
public:
    string id;
    string name;
    int age;

    User(string id, string name, int age) : id(id), name(name), age(age) {}
};


int main() {
    std::unordered_set<string> usersById;
    std::map<string, int> usersCountByName;
    std::map<int, int> usersCountByAge;
    string input;
    getline(std::cin, input);

    while (input != "end") {
        std::stringstream ss;
        ss << input;

        if (input.substr(0, 5) == "entry") {
            // add a new user
            string _, id, name, age;
            ss >> _ >> id >> name >> age;


            auto it = usersById.find(id);
            if (it == usersById.end()) {  // We've found a new unique user
                usersById.insert(id);
                usersCountByName[name]++;
                usersCountByAge[std::stoi(age)]++;
            }
        } else if (input.substr(0, 3) == "age") {
            string _, start, end;
            ss >> _ >> start >> end;

            int count = 0;

            // Get the number of unique users in the age group
            auto startIt = usersCountByAge.lower_bound(std::stoi(start));
            auto endIt = usersCountByAge.upper_bound(std::stoi(end)-1);
            for (auto i = startIt; i != endIt; ++i) {
                count += i->second;
            }

            std::cout << count << std::endl;
        } else if (input.substr(0, 4) == "name") {
            string _, name;
            ss >> _ >> name;

            auto nameCount = usersCountByName.find(name);
            if (nameCount == usersCountByName.end()) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << nameCount->second << std::endl;
            }

        }
        getline(std::cin, input);
    }
    return 0;
}