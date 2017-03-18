#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>


class Log {
    public:
        std::vector<Log*> connections;  // All Logs that are connected to this one
        int Ax, Ay, Bx, By, number;
        Log(int topX, int topY, int botX, int botY, int num);
        void AddConnection(Log* conn);
        bool connectsWith(Log* otherLog);
};

struct LogHasher
{
  std::size_t operator()(const Log& l) const
  {
    using std::size_t;
    using std::hash;
    using std::string;

     // Compute individual hash values for first, second and third
            // http://stackoverflow.com/a/1646913/126995
    size_t res = 17;
    res = res * 31 + hash<int>()( l.Ax );
    res = res * 31 + hash<int>()( l.Ay );
    res = res * 31 + hash<int>()( l.Bx );
    res = res * 31 + hash<int>()( l.By );
    res = res * 31 + hash<int>()( l.number );
    
    return res;
  }
};

Log* CreateLog(int number);
void BuildConnections(std::unordered_map<int, Log*> logs, Log* log);
std::vector<int> GetComponentLogs(Log* startLog, std::unordered_set<int> &visited);
bool** BuildMatrix(std::unordered_map<int, Log*> logs, int logCount);
bool** FillMatrix(bool** matrix, std::vector<int> component);

Log::Log(int topX, int topY, int botX, int botY, int num) {
    Ax = topX;
    Ay = topY;
    Bx = botX;
    By = botY;
    number = num;
}

void Log::AddConnection(Log* conn) {
    connections.push_back(conn);
}

bool Log::connectsWith(Log* otherLog) {
    /* See if this log connects with another log */
    return Ax <= otherLog->Bx && Bx >= otherLog->Ax && Ay >= otherLog->By && By <= otherLog->Ay;
}


// bool testOverlaps();
int main() {
    // std::cout << testOverlaps() << std::endl;
    
    int logCount, queryCount;
    std::unordered_map<int, Log*> logs;  // key: Log Number value: Log Object
    std::cin >> logCount >> queryCount;
    
    for (int logNum = 1; logNum < logCount+1; logNum++) {
        Log* newLog = CreateLog(logNum);
        BuildConnections(logs, newLog);
        logs[logNum] = newLog;
    }

    // After we're done reading all the logs, turn their connections into a matrix
    bool** matrix = BuildMatrix(logs, logCount);

    logs.clear();  // Free the memory of the Log objects since they're not needed anymore'
    // Take the user input
    for (int i = 0; i < queryCount; i++) {
        int row, col;
        std::cin >> row >> col;
        std::cout << (matrix[row][col] ? "YES" : "NO") << std::endl;
    }
    return 0;
}

bool** BuildMatrix(std::unordered_map<int, Log*> logs, int logCount) {
    bool** matrix = new bool*[logCount+1];
    std::unordered_set<int> visited;

    for (int i = 0; i < logCount+1; i++) {
        bool* row = new bool[logCount+1];
        for (int j = 0; j < logCount+1; j++) {
            row[j] = false;
        }
        matrix[i] = row;
    }

    // Get the components of all Logs and fill the matrix's connections'
    for (int i = 1; i < logCount+1; i++) {
        if (visited.find(i) != visited.end())
            continue;
        matrix[i][i] = true;
        
        std::unordered_map<int,Log*>::const_iterator got = logs.find(i);
        if ( got == logs.end() )
            continue;
        Log* log = got->second;

        std::vector<int> componentLogs = GetComponentLogs(log, visited);
        matrix = FillMatrix(matrix, componentLogs);
    }

    return matrix;
}

bool** FillMatrix(bool** matrix, std::vector<int> component) {
    /* Adds the connections of a component to the matrix representation of a graph */
    for (int i = 0; i < component.size(); i++) {
        int logIdx = component[i];
        for (int j = i; j < component.size(); j++) {
            int logIdx2 = component[j];
            matrix[logIdx][logIdx2] = true;
            matrix[logIdx2][logIdx] = true;
        }
    }

    return matrix;
}

std::vector<int> GetComponentLogs(Log* startLog, std::unordered_set<int> &visited) {
    /* 
    Runs a BFS from the Log to get the components
    Returns a vector of the logs that are in a given component 
    */
    std::vector<int> componentLogs;
    std::deque<Log*> logsToVisit; // the stack
    logsToVisit.push_back(startLog);
    visited.insert(startLog->number);
    componentLogs.push_back(startLog->number);
    while (!logsToVisit.empty()) {
        Log* currentLog = logsToVisit.front();
        logsToVisit.pop_front();
        for (int i = 0; i < currentLog->connections.size(); i++) {
            Log* otherLog = currentLog->connections[i];
            if (visited.find(otherLog->number) == visited.end()) {
                logsToVisit.push_back(otherLog);
                visited.insert(otherLog->number);
                componentLogs.push_back(otherLog->number);
            }
        }
    }

    return componentLogs;
}

void BuildConnections(std::unordered_map<int, Log*> logs, Log* log) {
    /* 
    Go through each log saved and see if it connects to the we Log we're about to add.
    If they do, simply make the connection
    */
    std::vector<std::pair<const int, Log*>> keyValuePairs(logs.begin(), logs.end());
    for (int i = 0; i < keyValuePairs.size(); i++) {
        Log* otherLog = keyValuePairs[i].second;

        if (otherLog->connectsWith(log)) {
            log->AddConnection(otherLog);
            otherLog->AddConnection(log);
        }
    }
}

Log* CreateLog(int number) {
    int topX, topY, botX, botY;
    std::cin >> topX >> topY >> botX >> botY;
    Log* log = new Log(topX, topY, botX, botY, number);

    return log;
}

// bool testOverlaps() {
//     Log* log1 = new Log(0, 50, 30, 40, 1);
//     Log* log2 = new Log(30, 50, 60, 40, 1);
//     Log* log3 = new Log(40, 40, 60, 1, 1);
//     Log* nonConnectingLog = new Log(-20, -20, -20, -20, 1);
//     return (log1->connectsWith(log2) && log2->connectsWith(log3) && log3->connectsWith(log2) && log2->connectsWith(log1)
//      && !log1->connectsWith(nonConnectingLog) && !log2->connectsWith(nonConnectingLog) && !log3->connectsWith(nonConnectingLog));
// }