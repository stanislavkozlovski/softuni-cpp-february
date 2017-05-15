#include <iostream>
#include <vector>

using std::cin;


int main() {
    int n, m;
    cin >> n >> m;
    std::vector<std::vector<int>> arrays;
    std::vector<long long int> weights;
    std::vector<long long int> solArr;

    // build arrays
    for (int i = 0; i < n; ++i) {
        auto new_arr = std::vector<int>();

        for (int j = 0; j < m; ++j) {
            int currNum;
            cin >> currNum;
            new_arr.push_back(currNum);
        }

        arrays.push_back(new_arr);
    }

    for (int k = 0; k < n; ++k) {
        long long int currWeight;
        cin >> currWeight;
        weights.push_back(currWeight);
    }

    for (int l = 0; l < m; ++l) {
        long long int currSum = 0;

        for (int i = 0; i < n; ++i) {
            currSum += weights[i] * arrays[i][l];
        }

        solArr.push_back(currSum);
    }


    for (int i1 = 0; i1 < m; ++i1) {
        std::cout << solArr[i1] << " ";
    }
    std::cout << std::endl;
    return 0;
}