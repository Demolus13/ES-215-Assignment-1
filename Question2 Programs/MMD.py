import time

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
    N = 1024
    print(f"Matrix Size: {N}")
    MatrixMultiplicationDouble(N)
    print("-----------------------")
