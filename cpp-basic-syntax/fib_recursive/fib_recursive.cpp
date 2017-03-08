#include <iostream>
#include <map>

long long fib(long long n) {
    static std::map<long long, long long> saved_fibonaccis;

    if (n == 1 || n == 0)  {
        return n;
    } else if (saved_fibonaccis.find(n) != saved_fibonaccis.end()) {
        return saved_fibonaccis[n];
    }

    saved_fibonaccis[n] = fib(n-1) + fib(n-2);
    return saved_fibonaccis[n];
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << "The Nth fibonacci number is " << fib(n) << std::endl;
}