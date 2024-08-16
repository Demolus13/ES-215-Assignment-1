import matplotlib.pyplot as plt
import numpy as np

# Data for C++ Integer Multiplication (MMI.cpp)
cpp_int_matrix_sizes = [64, 128, 256, 512, 1024]
cpp_int_program_time = [0.006, 0.033, 0.222, 1.780, 14.022]
cpp_int_sys_time = [0.003, 0.000, 0.000, 0.009, 0.012]

# Data for C++ Double Multiplication (MMD.cpp)
cpp_double_program_time = [0.009, 0.029, 0.226, 1.907, 15.391]
cpp_double_sys_time = [0.000, 0.004, 0.000, 0.012, 0.004]

# Data for Python Integer Multiplication (MMI.py)
python_int_matrix_sizes = [64, 128, 256, 512, 1024]
python_int_program_time = [0.064, 0.327, 2.465, 18.081, 119.690]
python_int_sys_time = [0.000, 0.008, 0.005, 0.036, 0.200]

# Data for Python Double Multiplication (MMD.py)
python_double_program_time = [0.061, 0.331, 2.489, 17.287, 113.620]
python_double_sys_time = [0.004, 0.004, 0.012, 0.016, 0.200]

# Plotting
plt.figure(figsize=(10, 8))

# C++ Integer Multiplication
plt.plot(cpp_int_matrix_sizes, cpp_int_program_time, 'o-', label='C++ Integer Program Time')
plt.plot(cpp_int_matrix_sizes, cpp_int_sys_time, 'o-', label='C++ Integer System Time')

# C++ Double Multiplication
plt.plot(cpp_int_matrix_sizes, cpp_double_program_time, 'o-', label='C++ Double Program Time')
plt.plot(cpp_int_matrix_sizes, cpp_double_sys_time, 'o-', label='C++ Double System Time')

# Python Integer Multiplication
plt.plot(python_int_matrix_sizes, python_int_program_time, 'o-', label='Python Integer Program Time')
plt.plot(python_int_matrix_sizes, python_int_sys_time, 'o-', label='Python Integer System Time')

# Python Double Multiplication
plt.plot(python_int_matrix_sizes, python_double_program_time, 'o-', label='Python Double Program Time')
plt.plot(python_int_matrix_sizes, python_double_sys_time, 'o-', label='Python Double System Time')

plt.title('Comparison of Program, and System Times for C++ and Python')
plt.xlabel('Matrix Size')
plt.ylabel('Time (seconds)')
plt.legend(loc='upper left')
plt.grid(True)

plt.show()
