import time
import numpy as np

# Function to multiply two matrices of integers
def MatrixMultiplicationInt(N):
    A = [[1 for _ in range(N)] for _ in range(N)]
    B = [[1 for _ in range(N)] for _ in range(N)]
    C = [[0 for _ in range(N)] for _ in range(N)]

    start_time = time.time()

    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]

    end_time = time.time()
    print(f"Time taken by integer multiplication: {end_time - start_time:.5f} seconds")

# Function to multiply two matrices of doubles
def MatrixMultiplicationDouble(N):
    A = [[1.0 for _ in range(N)] for _ in range(N)]
    B = [[1.0 for _ in range(N)] for _ in range(N)]
    C = [[0.0 for _ in range(N)] for _ in range(N)]

    start_time = time.time()

    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]

    end_time = time.time()
    print(f"Time taken by double multiplication: {end_time - start_time:.5f} seconds")

if __name__ == "__main__":
    sizes = [64, 128, 256, 512, 1024]
    for size in sizes:
        print(f"Matrix Size: {size}")
        MatrixMultiplicationInt(size)
        MatrixMultiplicationDouble(size)
        print("-----------------------")
