#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

long long int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long int fibonacci(int n, vector<long long int>& memo) {
    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

// Question 1a
void fibonacciRecursive(int n, bool ifPrint = false) {
    for (int i = 0; i < 50; i++) {
        if (ifPrint)
            cout << fibonacci(i) << " ";
        else
            fibonacci(i);
    }
    if (ifPrint) cout << endl;
}

// Question 1b
void fibonacciLoop(int n, bool ifPrint = false) {
    long long int prev2 = 0, prev1 = 1;
    if (n >= 1 && ifPrint) cout << prev2 << " ";
    if (n >= 2 && ifPrint) cout << prev1 << " ";

    for (int i = 2; i < n; i++) {
        long long int next = prev2 + prev1;
        if (ifPrint) cout << next << " ";
        prev2 = prev1;
        prev1 = next;
    }
    if (ifPrint) cout << endl;
}

// Question 1c
void fibonacciRecursiveMemoization(int n, bool ifPrint = false) {
    vector<long long int> memo(n, -1);
    for (int i = 0; i < 50; i++) {
        if (ifPrint)
            cout << fibonacci(i, memo) << " ";
        else
            fibonacci(i, memo);
    }
    if (ifPrint) cout << endl;
}

// Question 1d
void fibonacciLoopMemoization(int n, bool ifPrint = false) {
    vector<long long int> memo(n);
    memo[0] = 0;
    if (n > 1)
        memo[1] = 1;

    for (int i = 2; i < n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    if (ifPrint) {
        for (int i = 0; i < n; i++) {
            cout << memo[i] << " ";
        }
        cout << endl;
    }
}

double measureExecutionTime(void (*fibonacciFunc)(int, bool), int n) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    fibonacciFunc(n, false);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    return time_taken;
}

double computeAverageTime(void (*fibonacciFunc)(int, bool), int n, int iterations) {
    double total_time = 0.0;
    for (int i = 0; i < iterations; i++) {
        total_time += measureExecutionTime(fibonacciFunc, n);
    }
    return total_time / iterations;
}

int main() {
    int n = 50;
    int iterations = 1;

    double fibonacciRecursiveTime = computeAverageTime(fibonacciRecursive, n, iterations);
    double fibonacciLoopTime = computeAverageTime(fibonacciLoop, n, iterations);
    double fibonacciRecursiveMemoizationTime = computeAverageTime(fibonacciRecursiveMemoization, n, iterations);
    double fibonacciLoopMemoizationTime = computeAverageTime(fibonacciLoopMemoization, n, iterations);

    cout << "Average time taken for recursive fibonacci: " << fibonacciRecursiveTime << " seconds" << endl;
    cout << "Average time taken for loop fibonacci: " << fibonacciLoopTime << " seconds" << endl;
    cout << "Average time taken for recursive fibonacci with memoization: " << fibonacciRecursiveMemoizationTime << " seconds" << endl;
    cout << "Average time taken for loop fibonacci with memoization: " << fibonacciLoopMemoizationTime << " seconds" << endl;

    // Calculate speedups
    double speedupLoop = fibonacciRecursiveTime / fibonacciLoopTime;
    double speedupRecursiveMemo = fibonacciRecursiveTime / fibonacciRecursiveMemoizationTime;
    double speedupLoopMemo = fibonacciRecursiveTime / fibonacciLoopMemoizationTime;

    cout << "\nSpeedups relative to recursive fibonacci:" << endl;
    cout << "Speedup of loop fibonacci: " << speedupLoop << "x" << endl;
    cout << "Speedup of recursive fibonacci with memoization: " << speedupRecursiveMemo << "x" << endl;
    cout << "Speedup of loop fibonacci with memoization: " << speedupLoopMemo << "x" << endl;

    return 0;
}