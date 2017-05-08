#include <iostream>
#include <vector>
#include <iterator>

using std::string;

int main() {
    int num = 0;
    char buffer[5];

    while (fgets(buffer, 6, stdin)) {
        if (buffer[0] == '.') {
            break;
        }
        num ^= (int) strtol(buffer, NULL, 16);

    }
    printf("%05x", num);
    // Wouldn't be a C++ course if we didn't get down to the bare metal, would it Joro?
    // all the best
    // PS: If you're a random person copying this off of Github, at least give it a star, promsie I won't tell
    return 0;
}
