import numpy as np
import matplotlib.pyplot as plt

def calculate_pi(num_points):
    points_inside_circle = 0
    x_inside = []
    y_inside = []
    x_outside = []
    y_outside = []
    
    for _ in range(num_points):
        x = np.random.uniform(-1, 1)
        y = np.random.uniform(-1, 1)
        
        if x**2 + y**2 <= 1:
            points_inside_circle += 1
            x_inside.append(x)
            y_inside.append(y)
        else:
            x_outside.append(x)
            y_outside.append(y)
    
    pi_approximation = 4 * points_inside_circle / num_points
    
    # Hit dan miss untuk Monte Carlo
    hits = points_inside_circle
    misses = num_points - points_inside_circle
    
    # Integral menggunakan Metode Trapesium
    integral_trapezoid = calculate_integral_trapezoid(x_inside, y_inside)
    
    return pi_approximation, hits, misses, integral_trapezoid, x_inside, y_inside, x_outside, y_outside

def calculate_integral_trapezoid(x_values, y_values):
    integral = 0.0
    for i in range(1, len(x_values)):
        integral += (y_values[i-1] + y_values[i]) * (x_values[i] - x_values[i-1]) / 2.0
    return integral

num_points = int(input("Masukkan jumlah titik yang akan digunakan: "))
pi_approximation, hits, misses, integral_trapezoid, x_inside, y_inside, x_outside, y_outside = calculate_pi(num_points)

# Plot titik-titik yang berada di dalam lingkaran (warna biru) dan di luar lingkaran (warna merah)
plt.figure(figsize=(6, 6))
plt.scatter(x_inside, y_inside, color='blue', s=5, label='Dalam lingkaran')
plt.scatter(x_outside, y_outside, color='red', s=5, label='Di luar lingkaran')

# Plot lingkaran
circle = plt.Circle((0, 0), 1, color='black', fill=False, linestyle='--', linewidth=2)
plt.gca().add_patch(circle)

plt.axis('equal')
plt.title('Metode Monte Carlo untuk Menghitung Pi')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()
plt.grid(True)
plt.show()

print("Nilai hampiran pi dengan", num_points, "titik:", pi_approximation)
print("Hit:", hits)
print("Miss:", misses)
print("Integral Metode Trapesium:", integral_trapezoid)
