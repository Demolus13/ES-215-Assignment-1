#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;

// Function to multiply two integer matrices
void MatrixMultiplicationInt(vector<vector<int>> &A, vector<vector<int>> &B) {
    int N = A.size(), M = B[0].size(), K = B.size();
    vector<vector<int>> C(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < K; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to multiply two double matrices
void MatrixMultiplicationDouble(vector<vector<double>> &A, vector<vector<double>> &B) {
    int N = A.size(), M = B[0].size(), K = B.size();
    vector<vector<double>> C(N, vector<double>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < K; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

template <typename T>
double measureExecutionTime(void (*matrixMultiplicationFunc)(vector<vector<T>>&, vector<vector<T>>&), vector<vector<T>> &A, vector<vector<T>> &B, double &total_cpu_time) {
    auto start = chrono::high_resolution_clock::now();
    clock_t cpu_start = clock();

    matrixMultiplicationFunc(A, B); // Meat portion

    clock_t cpu_end = clock();
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> wall_clock_duration = end - start;
    double time_taken = wall_clock_duration.count(); // in seconds

    total_cpu_time = double(cpu_end - cpu_start) / CLOCKS_PER_SEC;

    return time_taken;
}

template <typename T>
double computeAverageTime(void (*matrixMultiplicationFunc)(vector<vector<T>>&, vector<vector<T>>&), vector<vector<T>> &A, vector<vector<T>> &B, int iterations, double &avg_cpu_time) {
    double total_time = 0.0, total_cpu_time = 0.0;
    for (int i = 0; i < iterations; ++i) {
        double cpu_time;
        total_time += measureExecutionTime(matrixMultiplicationFunc, A, B, cpu_time);
        total_cpu_time += cpu_time;
    }
    avg_cpu_time = total_cpu_time / iterations;
    return total_time / iterations;
}

int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};
    int iterations = 10;

    ofstream data_file("bucket1.csv");
    data_file << "Matrix_Size,Avg_Time_Int,Avg_CPU_Time_Int,Avg_Time_Double,Avg_CPU_Time_Double\n";

    for (int N : sizes) {
        vector<vector<int>> A_int(N, vector<int>(N, 1));
        vector<vector<int>> B_int(N, vector<int>(N, 2));
        vector<vector<double>> A_double(N, vector<double>(N, 1.0));
        vector<vector<double>> B_double(N, vector<double>(N, 2.0));

        double avg_cpu_time_int, avg_cpu_time_double;
        double avgTimeInt = computeAverageTime(MatrixMultiplicationInt, A_int, B_int, iterations, avg_cpu_time_int);
        double avgTimeDouble = computeAverageTime(MatrixMultiplicationDouble, A_double, B_double, iterations, avg_cpu_time_double);

        cout << "Matrix size: " << N << "x" << N << endl;
        cout << "Integer matrix multiplication: " << avgTimeInt << " seconds, CPU time: " << avg_cpu_time_int << " seconds" << endl;
        cout << "Double matrix multiplication: " << avgTimeDouble << " seconds, CPU time: " << avg_cpu_time_double << " seconds" << endl;
        cout << "----------------------------------------" << endl;

        data_file << N << "," << avgTimeInt << "," << avg_cpu_time_int << "," << avgTimeDouble << "," << avg_cpu_time_double << "\n";
    }

    data_file.close();
    return 0;
}
