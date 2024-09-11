import ctypes
import numpy as np
import matplotlib.pyplot as plt

# Load the shared library
lib = ctypes.CDLL('./libparallelogram.so')

# Define the function prototypes
lib.main.argtypes = []
lib.main.restype = None

# Call the main function from the C code
lib.main()

# Coordinates of A(-2, 1), D(1, 2), and C(4, b)
# Since b is assumed to be 1 in C code
A = np.array([-2, 1])
D = np.array([1, 2])
C = np.array([4, 1])  # Example value for b

# Calculate B using the formula B = A + C - D
B = A + C - D

# Create a larger figure
plt.figure(figsize=(10, 12))  # Adjust the width and height as needed

# Plot the points and the parallelogram
plt.plot([A[0], B[0]], [A[1], B[1]], 'ro-', label='AB')
plt.plot([A[0], D[0]], [A[1], D[1]], 'bo-', label='AD')
plt.plot([D[0], C[0]], [D[1], C[1]], 'go-', label='DC')
plt.plot([C[0], B[0]], [C[1], B[1]], 'yo-', label='CB')

# Scatter plot of the points
plt.scatter([A[0], B[0], C[0], D[0]], [A[1], B[1], C[1], D[1]], color='black')

# Annotate each point with its coordinates
plt.annotate(f'A ({A[0]:.1f}, {A[1]:.1f})', (A[0], A[1]), textcoords="offset points", xytext=(-10,10), ha='center', fontsize=12, color='black')
plt.annotate(f'B ({B[0]:.1f}, {B[1]:.1f})', (B[0], B[1]), textcoords="offset points", xytext=(10,-10), ha='center', fontsize=12, color='black')
plt.annotate(f'C ({C[0]:.1f}, {C[1]:.1f})', (C[0], C[1]), textcoords="offset points", xytext=(10,10), ha='center', fontsize=12, color='black')
plt.annotate(f'D ({D[0]:.1f}, {D[1]:.1f})', (D[0], D[1]), textcoords="offset points", xytext=(-10,-10), ha='center', fontsize=12, color='black')

# Add a legend, labels, and a title
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Parallelogram with Points A, B, C, and D')
plt.grid(True)
plt.gca().set_aspect('equal', adjustable='box')
plt.legend()
plt.show()

