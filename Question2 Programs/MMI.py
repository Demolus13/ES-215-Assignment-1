import time

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

if __name__ == "__main__":
    N = 64
    print(f"Matrix Size: {N}")
    MatrixMultiplicationInt(N)
    print("-----------------------")
