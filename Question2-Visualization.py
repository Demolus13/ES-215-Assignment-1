import pandas as pd
import matplotlib.pyplot as plt

# Load data from CSV
bucket1 = pd.read_csv('bucket1.csv')
bucket2 = pd.read_csv('bucket2.csv')

# Plotting
sizes = data['Matrix_Size']

plt.figure(figsize=(12, 8))

plt.subplot(2, 1, 1)
plt.plot(sizes, data['Avg_Time_Int'], label='Avg Time Int', marker='o')
plt.plot(sizes, data['Avg_CPU_Time_Int'], label='Avg CPU Time Int', marker='o')
plt.plot(sizes, data['Avg_System_Time_Int'], label='Avg System Time Int', marker='o')
plt.title('Integer Matrix Multiplication')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.legend()

plt.subplot(2, 1, 2)
plt.plot(sizes, data['Avg_Time_Double'], label='Avg Time Double', marker='o')
plt.plot(sizes, data['Avg_CPU_Time_Double'], label='Avg CPU Time Double', marker='o')
plt.plot(sizes, data['Avg_System_Time_Double'], label='Avg System Time Double', marker='o')
plt.title('Double Matrix Multiplication')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.legend()

plt.tight_layout()
plt.show()
