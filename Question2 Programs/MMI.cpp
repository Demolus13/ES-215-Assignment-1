#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Function to multiply two matrices of integers
void MatrixMultiplicationInt(int N) {
    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 1));
    vector<vector<int>> C(N, vector<int>(N, 0));
    
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "Time taken by integer multiplication: " << time_taken << " seconds" << endl;
}

int main() {
    int N = 64;

    cout << "Matrix Size: " << N << endl;
    MatrixMultiplicationInt(N);
    cout << "-----------------------" << endl;

    return 0;
}
