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

// Function to multiply two matrices of doubles
void MatrixMultiplicationDouble(int N) {
    vector<vector<double>> A(N, vector<double>(N, 1.0));
    vector<vector<double>> B(N, vector<double>(N, 1.0));
    vector<vector<double>> C(N, vector<double>(N, 0.0));
    
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
    cout << "Time taken by double multiplication: " << time_taken << " seconds" << endl;
}

int main() {
    int sizes[] = {64, 128, 256, 512, 1024};
    for(int i = 0; i < 5; ++i) {
        cout << "Matrix Size: " << sizes[i] << endl;
        MatrixMultiplicationInt(sizes[i]);
        MatrixMultiplicationDouble(sizes[i]);
        cout << "-----------------------" << endl;
    }
    return 0;
}
