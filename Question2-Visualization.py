import matplotlib.pyplot as plt

# Example data
sizes = [64, 128, 256, 512, 1024]
cpp_int_real = [0.0059607, 0.0282816, 0.216383, 1.81806, 12.9467]
cpp_double_real = [0.00601292, 0.0304396, 0.218415, .97491, 13.5741]
python_int_real = [0.03905, 0.30659, 2.46428, 16.80643, 116.30515]
python_double_real = [0.03884, 0.30690, 2.46059, 16.36700, 111.27206]

# Plot real times
plt.figure(figsize=(12, 6))

plt.plot(sizes, cpp_int_real, marker='o', label='C++ Integer Real Time')
plt.plot(sizes, cpp_double_real, marker='o', label='C++ Double Real Time')
plt.plot(sizes, python_int_real, marker='o', label='Python Integer Real Time')
plt.plot(sizes, python_double_real, marker='o', label='Python Double Real Time')

plt.xlabel('Matrix Size (N)')
plt.ylabel('Real Time (s)')
plt.title('Matrix Multiplication Real Time Comparison')
plt.legend()
plt.grid(True)
plt.show()
