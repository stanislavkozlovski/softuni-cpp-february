#include<string>
#include<iostream>
#include<exception>
#include<vector>
#include <map>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <sstream>
#include <limits>
#include <fstream>

using std::stringstream;
using std::string;
using std::exception;
using std::vector;
using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;



/* STRING TRIM HELPER */
// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

struct MyException : public std::exception
{
   std::string s;
   MyException(std::string ss) : s(ss) {}
   ~MyException() throw () {} // Updated
   const char* what() const throw() { return s.c_str(); }
};

enum AstronomicalObjectType {
    Star, 
    RockyPlanet, 
    GasGiant, 
    Unknown
};
class AstronomicalObject {
    private:
        AstronomicalObjectType type;
        double mass;
        double radius;
        string nickname;
        string name;
        // SolarSystem* 

        friend std::ostream& operator<<(std::ostream &strm, const AstronomicalObject &a);
    public:
        AstronomicalObject(string nickname, string name, double radius, double mass, AstronomicalObjectType type) :
            nickname(nickname), name(name), radius(radius), mass(mass), type(type) {}


        void changeType(AstronomicalObjectType newType) {
            if (this->type != Unknown) {
                throw MyException("You cannot change the type of an astronomical object if it is known!");
            }
            this->type = newType;
        }

        void changeName(string newName) {
            this->name = newName;
        }

        string getName() const {
            return this->name;
        }

        string getNickname() const {
            return this->nickname;
        }

        double getRadius() const {
            return this->radius;
        }

        double getMass() const {
            return this->mass;
        }

        AstronomicalObjectType getType() const {
            return this->type;
        }
};
std::ostream& operator<<(std::ostream &strm, const AstronomicalObject &a) {
    strm << a.name << " ";
    if (a.nickname != "")
        strm << "(" << a.nickname << ") ";
    return strm << "{ mass: " << a.mass << ", radius: " << a.radius << " }";
}

class SolarSystem {
    private:
        string name;
        bool hasStar;
    public:
        vector<AstronomicalObject*> members;
    
        SolarSystem(string name) : name(name) { this->hasStar = false; }

        void changeName(string name) {
            string oldName = this->name;
            this->name = name;
            // Rename all the members
            for (int i = 0; i < members.size(); i++) {
                AstronomicalObject* asObject = members[i];
                asObject->changeName(
                    asObject->getName().replace(0, oldName.size(), this->name)
                );
            }
        }

        void addMember(AstronomicalObject* newMember) {
            if (newMember->getType() == Star) {
                this->hasStar = true;
            }
            this->members.push_back(newMember);
        }

        int getMemberCount() const {
            return this->members.size();
        }
        string getName() const {
            return this->name;
        }
        bool hasAStar() const {
            return this->hasStar;
        }
};

void printSolarSystems(map<string, SolarSystem*> &universe) {
    for(map<string, SolarSystem*>::const_iterator it = universe.begin(); it != universe.end(); ++it ) {
        cout << it->first << endl;
    }
}

void createSolarSystem(map<string, SolarSystem*> &universe) {
    string name;
    cout << "Enter a name for your new Solar System!" << endl;
    cin >> name;
    // Check if the name is already taken
    map<string, SolarSystem*>::iterator find = universe.find(name);
    while (find != universe.end()) {
        cout << "There already exists a Solar System named " << name << "! Please enter a new name: " << endl;
        name = "";
        cin >> name;

        find = universe.find(name);
    }

    SolarSystem* newSystem = new SolarSystem(name);
    universe.insert(std::make_pair(name, newSystem));
    cout << "Created the Solar System " << name << endl;
}

AstronomicalObjectType chooseAstronomyObjectType() {
    /* Prompt the user to choose the type of astronomy object he wants*/
    int choice;
    cout << "Please choose the type of your astronomy object by entering its ID" << endl;
    cout << "1. Star" << endl;
    cout << "2. Rocky Planet" << endl;
    cout << "3. Gas Giant" << endl;
    cout << "4. Unknown" << endl;

    string trash;
    cin >> choice;
    std::getline(cin, trash);
    while (choice < 1 || choice > 4) {
        cout << "Invalid choice! Choose again: ";
        cout << "1. Star" << endl;
        cout << "2. Rocky Planet" << endl;
        cout << "3. Gas Giant" << endl;
        cout << "4. Unknown" << endl;
        cin.clear();
        std::getline(cin, trash);

        cin >> choice;
    }

    AstronomicalObjectType chosenType;
    switch (choice)
    {
        case 1:
            chosenType = Star;
            break;
        case 2:
            chosenType = RockyPlanet;
            break;
        case 3:
            chosenType = GasGiant;
            break;
        case 4:
            chosenType = Unknown;
            break;
        default:
            throw MyException("Invalid Astronomical Object Type!");
            break;
    }

    return chosenType;
}

SolarSystem* chooseSolarSystem(map<string, SolarSystem*> &universe) {
    string chosenSystem;
    cout << "Please choose a Solar System by entering its name:" << endl;
    printSolarSystems(universe);
    cin.ignore();
    std::getline(cin, chosenSystem);

    trim(chosenSystem);
    map<string, SolarSystem*>::iterator find = universe.find(chosenSystem);
    while (find == universe.end()) {
        cout << "The Solar System " << chosenSystem << " does not exist! Enter another one: " << endl;
        printSolarSystems(universe);
        std::getline(cin, chosenSystem);
        trim(chosenSystem);
        find = universe.find(chosenSystem);
    }

    return find->second;
}

void createAstronomyObject(map<string, SolarSystem*> &universe) {
    string toAddNickname, toAddObjectType;
    SolarSystem* chosenSystem = chooseSolarSystem(universe);
    cout << "Do you know your Object's type? (Y/N)" << endl;

    AstronomicalObjectType chosenType = Unknown;
    cin >> toAddObjectType;
    if (toAddObjectType == "Y") {
        chosenType = chooseAstronomyObjectType();
        while (chosenSystem->hasAStar() && chosenType == Star) {
            cout << chosenSystem->getName() << " already has a Star and you cannot add more. Please choose another type: ";
            AstronomicalObjectType chosenType = chooseAstronomyObjectType();
        }
    }

    cout << "Do you want to add a nickname to your object? (Y/N)" << endl;
    cin >> toAddNickname;
    string nickname = "";
    
    if (toAddNickname == "Y") {
        cout << "Enter a nickname: " << endl;
        cin >> nickname;
    }

    double radius;
    cout << "Enter the radius in meters of your object: " << endl;
    cin >> radius;

    double mass;
    cout << "Enter the mass of your object: " << endl;
    cin >> mass;

    // Construct the name of the object
    stringstream ss;
    ss << chosenSystem->getName() << "-";
    if (chosenType == Star) {
        ss << 1;
    } else {
        int objectNumber = chosenSystem->getMemberCount() + 2;
        
        ss << objectNumber;
    }

    string name = ss.str();
    AstronomicalObject* asObject = new AstronomicalObject(nickname, name, radius, mass, chosenType);
    chosenSystem->addMember(asObject);
    cout << "Created Astronomical Object " << *asObject << "!";
}

void saveResults(map<string, SolarSystem*> universe) {
    /* 
    Saves the results to a text file
    AstronomicalObject writing ->
        Name << Nickname(or placeholder) << radius << mass << type
    */
    ofstream file;
    file.open("universe.txt", std::ofstream::out | std::ofstream::trunc);

    for(map<string, SolarSystem*>::const_iterator it = universe.begin(); it != universe.end(); ++it ) {
        file << "Solar System" << "\n";
        file << it->first << "\n";
        // add the astronomy objects
        file << "Planets" << "\n";
        SolarSystem* solarSystem = it->second;
        for (int i = 0; i < solarSystem->members.size(); i++) {
            AstronomicalObject* asObject = solarSystem->members[i];

            file << asObject->getName() << " ";
            cout << "NICKAME IS '"  << asObject->getNickname() << "'" << endl;
            if(asObject->getNickname() == "") {
                file << "EMPTYNICKNAME" << " ";
            } else {
                file << asObject->getNickname() << " ";
            }

            file << asObject->getRadius() << " " << asObject->getMass() << " " << asObject->getType();
            file << "\n";
        }
    }


    file << "END" << "\n";

    file.close();
}

map<string, SolarSystem*> readResults() {
    /* Read the results from the text file and create the univese*/
    map<string, SolarSystem*> universe;
    ifstream file;
    string line;
    file.open("universe.txt");

    SolarSystem* lastSystem;
    bool readingPlanets = false;
    while(getline(file, line)) {
        if (line == "END") {
            break;
        }
        if (line == "Planets") {
            readingPlanets = true;
        } else if (line == "Solar System") {
            readingPlanets = false;
        }

        if (readingPlanets) {
            string planetName, planetNickname;
            double planetRadius, planetMass;
            int planetType;
            stringstream ss;
            ss << line;
            ss >> planetName >> planetNickname >> planetRadius >> planetMass >> planetType;
            if (planetNickname == "EMPTYNICKNAME")
                planetNickname = "";
            AstronomicalObject* asObject = new AstronomicalObject(planetNickname, planetName, planetRadius, planetMass, static_cast<AstronomicalObjectType>(planetType));
            lastSystem->addMember(asObject);
        } else {
            // reading a new System
            string name = line;
            SolarSystem* solarSystem = new SolarSystem(name);
            universe.insert(std::make_pair(name, solarSystem));
            lastSystem = solarSystem;
        }
    }

    return universe;
}

int main() {
    map<string, SolarSystem*> universe = readResults();
    string command;
    cout << "Hello and welcome to the Solar System Simulator. Please choose an action: (enter 'END' to stop the program and save the results)" << endl; 
    cout << "1. Create a Solar System" << endl;
    cout << "2. Create an Astronomical Object" << endl;
    cout << "3. Rename a Solar System" << endl;
    cin >> command;
    while (command != "END") {
        while (command != "1" && command != "2" && command != "3") {
            command.clear();
            cout << "Invalid command!" << endl;
            cin >> command;
        }

        if (command == "1") {
            createSolarSystem(universe);
        } else if (command == "2") {
            createAstronomyObject(universe);
        } else if (command == "3") {
            SolarSystem* solarSystem = chooseSolarSystem(universe);
            string newName;
            cout << "Enter the new name of your Solar System" << endl;
            getline(cin, newName);

            // Check if the name is already taken
            map<string, SolarSystem*>::iterator find = universe.find(newName);
            while (find != universe.end()) {
                cout << "There already exists a Solar System named " << newName << "! Please enter a new name: " << endl;
                newName = "";
                getline(cin, newName);

                find = universe.find(newName);
            }

            string oldName = solarSystem->getName();
            solarSystem->changeName(newName);
            // Remove the old pair from universe and add the new one
            universe.erase(oldName);
            universe.insert(std::make_pair(newName, solarSystem));
        }

        cout << endl << endl << endl;
        cout << "1. Create a Solar System" << endl;
        cout << "2. Create an Astronomical Object" << endl;
        cout << "3. Rename a Solar System" << endl;

        command.clear();
        cin >> command;
    }

    saveResults(universe);
    return 0;
}