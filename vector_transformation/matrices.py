import numpy as np
import matplotlib.pyplot as plt
import math

def create_scaling_matrix(scale_x, scale_y):
  matrix = np.array([
    [scale_x, 0],
    [0, scale_y]
  ])
  return matrix

def create_rotation_matrix(angle_degrees):
  angle_radians = math.radians(angle_degrees)
  cos = math.cos(angle_radians)
  sin = math.sin(angle_radians)
  matrix = np.array([
    [cos, -sin],
    [sin, cos]
  ])
  return np.round(matrix, 5)

def transform_vector(vector, matrix):
  return matrix @ vector
  
def draw_vector(original_vector, ov_color, ov_label, transformed_vector, tv_color, tv_label):
  configure_plot(original_vector, ov_color, ov_label)
  configure_plot(transformed_vector, tv_color, tv_label)
  plt.xlim(-5, 5)
  plt.ylim(-5, 5)
  plt.axhline(0)
  plt.axvline(0)
  plt.grid()
  plt.gca().set_aspect("equal")
  plt.legend()
  plt.show()
  
def configure_plot(vector, color, label):
  plt.quiver(0,0, vector[0], vector[1], 
    color=color, angles="xy", label=label,
    scale_units="xy",
    scale=1
  )
  
def compare_rotation(original_vector, transformed_vector):
  np.linalg.norm(original_vector)
  np.linalg.norm(transformed_vector)

def print_vector_shape(vector):
  print(vector.shape)

def print_matrix_shape(matrix):
  print(matrix.shape)
  
def create_vector(vector_x, vector_y):
  return np.array([vector_x, vector_y])
  
def create_matrix():
  pass