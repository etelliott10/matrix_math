import numpy as np
import matplotlib.pyplot as plt
from matrices import create_scaling_matrix, create_rotation_matrix, transform_vector, draw_vector, configure_plot, compare_rotation, print_vector_shape, print_matrix_shape, create_vector



def main():
  
  print('Vector Transformation Visualizer\n')
  print('1. Create Scaling Matrix')
  print('2. Create Rotation Matrix')
  print('3. Transform Vector')
  print('4. Draw Vector')
  print('5. Compare Rotation')
  print('6. Print Vector Shape')
  print('7. Print Matrix Shape')
  print('8. Exit')
  print('9. Exit')
  
  
  value = float(input("Enter a value: "))
  if (value == 1):
    scale_x = float(input("Enter a scale x value: "))
    scale_y = float(input("Enter a scale_y value: "))
    
    scale_matrix = create_scaling_matrix(scale_x, scale_y)
    print('Scale Matrix: ', scale_matrix)
  elif (value == 2):
    angle_degrees = float(input("Enter a angle degrees value: "))
    rotated_matrix = create_rotation_matrix(angle_degrees)
    print('Rotation Matrix: ', rotated_matrix)
  elif (value == 3):
    angle_degrees = float(input("Enter a angle degrees value: "))
    rotated_matrix = create_rotation_matrix(angle_degrees)
    print('Rotation Matrix: ', rotated_matrix)
  elif (value == 4):
    vector_x = float(input("Enter a vector x value: "))
    vector_y = float(input("Enter a vector y value: "))
    vector = create_vector(vector_x, vector_y)
    print('Vector: ', vector)
    print("1. Add Row to Matrix")
    print("2. Add Column to Matrix")
    print("3.Finished with Matrix")
    choice = float(input("Enter a choice: "))
   
    # while (choice):
      # scale_x = float(input("Enter a scale x value: ")
    
    
    # draw_vector(vector)

  elif (value == 5):
    angle_degrees = float(input("Enter a angle degrees value: "))
    rotated_matrix = create_rotation_matrix(angle_degrees)
    print('Rotation Matrix: ', rotated_matrix)
  elif (value == 6):
    angle_degrees = float(input("Enter a angle degrees value: "))
    rotated_matrix = create_rotation_matrix(angle_degrees)
    print('Rotation Matrix: ', rotated_matrix)
  elif (value == 7):
    angle_degrees = float(input("Enter a angle degrees value: "))
    rotated_matrix = create_rotation_matrix(angle_degrees)
    print('Rotation Matrix: ', rotated_matrix)
  elif (value == 8):
    angle_degrees = float(input("Enter a angle degrees value: "))
    rotated_matrix = create_rotation_matrix(angle_degrees)
    print('Rotation Matrix: ', rotated_matrix)
  
  elif (value == 9):
    exit()
  else:
    print('Invalid value')
    main()
