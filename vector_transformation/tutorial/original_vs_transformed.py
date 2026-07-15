import numpy as np
import matplotlib.pyplot as plt
import math


angle_degrees = 90
angle_radians = math.radians(angle_degrees)
print('angle_radians',angle_radians)
cos = math.cos(angle_radians)
sin = math.sin(angle_radians)
print(cos)
print(sin)

vector = np.array([1,1])
scale_x = 0.5
scale_y = 3
# matrix = np.array([[4,5],[1,-9]])
matrix = np.array([
    [scale_x, 0],
    [0, scale_y]
])

transformed_vector = matrix @ vector

print(vector)
print(transformed_vector)

plt.quiver(0,0, vector[0], vector[1], color='r', angles="xy", label='original vector',
scale_units="xy",
scale=1)

plt.quiver(0,0, transformed_vector[0], transformed_vector[1], color='g', angles="xy", label='transformed vector',
scale_units="xy",
scale=1)

plt.xlim(-5, 5)
plt.ylim(-5, 5)
plt.axhline(0)
plt.axvline(0)
plt.grid()
plt.gca().set_aspect("equal")
plt.legend()
plt.show()


def create_scaling_matrix():
  pass

def create_rotation_matrix():
  pass

def transform_vector(vector, matrix):
  return matrix @ vector
  
def draw_vector():
  pass
  
def configure_plot():
  pass