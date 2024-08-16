import numpy as np
import time
import csv

def MatrixMultiplicationInt(A, B):
    return np.dot(A, B)

def MatrixMultiplicationDouble(A, B):
    return np.dot(A, B)

def measureExecutionTime(matrixMultiplicationFunc, A, B):
    start_wall = time.time()
    start_cpu = time.process_time()
    
    _ = matrixMultiplicationFunc(A, B)  # Meat portion

    end_cpu = time.process_time()
    end_wall = time.time()
    
    wall_time = end_wall - start_wall
    cpu_time = end_cpu - start_cpu

    return wall_time, cpu_time

def computeAverageTime(matrixMultiplicationFunc, A, B, iterations):
    total_wall_time = 0.0
    total_cpu_time = 0.0
    for _ in range(iterations):
        wall_time, cpu_time = measureExecutionTime(matrixMultiplicationFunc, A, B)
        total_wall_time += wall_time
        total_cpu_time += cpu_time
    avg_wall_time = total_wall_time / iterations
    avg_cpu_time = total_cpu_time / iterations
    return avg_wall_time, avg_cpu_time

sizes = [64, 128, 256, 512, 1024]
iterations = 10

with open('bucket2.csv', 'w', newline='') as csvfile:
    csvwriter = csv.writer(csvfile)
    csvwriter.writerow(['Matrix_Size', 'Avg_Time_Int', 'Avg_CPU_Time_Int', 'Avg_Time_Double', 'Avg_CPU_Time_Double'])

    for N in sizes:
        A_int = np.ones((N, N), dtype=int)
        B_int = np.ones((N, N), dtype=int) * 2
        A_double = np.ones((N, N), dtype=float)
        B_double = np.ones((N, N), dtype=float) * 2

        avg_time_int, avg_cpu_time_int = computeAverageTime(MatrixMultiplicationInt, A_int, B_int, iterations)
        avg_time_double, avg_cpu_time_double = computeAverageTime(MatrixMultiplicationDouble, A_double, B_double, iterations)

        print(f"Matrix size: {N}x{N}")
        print(f"Integer matrix multiplication: {avg_time_int:.6f} seconds, CPU time: {avg_cpu_time_int:.6f} seconds")
        print(f"Double matrix multiplication: {avg_time_double:.6f} seconds, CPU time: {avg_cpu_time_double:.6f} seconds")
        print("----------------------------------------")

        csvwriter.writerow([N, avg_time_int, avg_cpu_time_int, avg_time_double, avg_cpu_time_double])

