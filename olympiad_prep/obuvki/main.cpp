#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;


int main() {
    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; ++i) {
        int skiierCount, shoeCount;
        cin >> skiierCount >> shoeCount;

        // read skiiers
        int skiiers[skiierCount];
        for (int j = 0; j < skiierCount; ++j) {
            cin >> skiiers[j];
        }

        // read shoes
        int shoes[shoeCount];
        for (int k = 0; k < shoeCount; ++k) {
            cin >> shoes[k];
        }
        // sort both
        std::sort(skiiers, skiiers + skiierCount);
        std::sort(shoes, shoes + shoeCount);

        int validShoes = 0;
        int skiierIdx = 0;
        int shoeIdx = 0;
        while (shoeIdx < shoeCount && skiierIdx < skiierCount) {
            int currShoe = shoes[shoeIdx];
            int currSkiier = skiiers[skiierIdx];

            if (currShoe >= currSkiier) {
                // valid match
                shoeIdx++;
                skiierIdx++;
                validShoes++;
            } else {
                // shoe is less than the skiier
                shoeIdx++;
            }
        }

        cout << validShoes << std::endl;
    }
    return 0;
}