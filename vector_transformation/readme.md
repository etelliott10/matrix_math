We will use two primary Python tools:
import numpy as np
import matplotlib.pyplot as plt

1. NumPy: Your Linear Algebra Tool
   NumPy stores vectors and matrices as arrays.
   Creating a vector
   A two-dimensional vector contains an x and y component:
   vector = np.array([3, 2])

Interpretation:

    |3|

v = | |
|2|
​
In NumPy:
print(vector[0]) # x component
print(vector[1]) # y component

Your first practice
Create these vectors and print their components:
a = (4, 1)
b = (-2, 3)
c = (0, -5)
Then answer:
Which vectors point right?

- a:4
- c:0

Which point left?

- b: -2
  Which point upward?
- a: 1
- b:3
  Which point downward?
- c:-5

2. Matplotlib: Displaying a Vector
   Matplotlib creates the coordinate plane.

   The main function you need is:
   plt.quiver()
   A vector begins at an origin and points toward an endpoint.
   Conceptually:
   plt.quiver(
   origin_x,
   origin_y,
   vector_x,
   vector_y
   )
   For a vector starting at (0, 0):
   vector = np.array([3, 2])

plt.quiver(
0,
0,
vector[0],
vector[1],
angles="xy",
scale_units="xy",
scale=1
)
The important settings are:
angles="xy"
scale_units="xy"
scale=1
Without them, Matplotlib may visually resize the arrow instead of respecting your coordinate values.

3. Setting Up the Coordinate Plane
   Your graph needs fixed boundaries so transformations are visually comparable.
   Useful functions:
   plt.xlim(-10, 10)
   plt.ylim(-10, 10)
   plt.axhline(0)
   plt.axvline(0)
   plt.grid()
   plt.gca().set_aspect("equal")
   plt.show()

   What each tool does
   Function Purpose
   plt.xlim() Sets horizontal boundaries
   plt.ylim() Sets vertical boundaries
   plt.axhline(0) Draws the x-axis
   plt.axvline(0) Draws the y-axis
   plt.grid() Displays grid lines
   set_aspect("equal") Keeps one x-unit equal to one y-unit
   plt.show() Opens the graph
   The equal aspect ratio is critical. Without it, a 90-degree angle may not look like a 90-degree angle.

4. Creating a Transformation Matrix
   A 2D transformation uses a 2 × 2 matrix:
   matrix = np.array([
   [a, b],
   [c, d]
   ])
   A vector is transformed using matrix-vector multiplication:
   v

new
​
=A
v

In NumPy, matrix multiplication uses @:
transformed*vector = matrix @ vector
Do not use:
matrix * vector
The \_ operator performs element-by-element multiplication. That is not the matrix multiplication you are trying to learn.
Matrix multiplication intuition
Suppose:
vector = np.array([x, y])
and:
matrix = np.array([
[a, b],
[c, d]
])
The transformed vector becomes:
new_x = a*x + b*y
new_y = c*x + d*y
Each row of the matrix determines one component of the result.
Practice before coding
For:
vector = (2, 3)

matrix =
[2 0]
[0 1]
Calculate the transformed vector by hand.
Then verify with:
result = matrix @ vector
You should always predict first, calculate second, and visualize third.

5. Visualizing Original and Transformed Vectors
   Your graph should eventually display two arrows:
   the original vector
   the transformed vector
   The process is:
   Create original vector
   ↓
   Create matrix
   ↓
   Multiply matrix @ vector
   ↓
   Draw original vector
   ↓
   Draw transformed vector
   You can call plt.quiver() more than once.
   For example, one call draws the original vector and another draws the transformed one.
   To distinguish them, investigate these arguments:
   color=
   label=
   Then add:
   plt.legend()
   Your task is to determine how label and legend work together.
   Milestone 2: Apply a General Matrix
   Create a program where you can change:
   matrix = np.array([
   [1, 0],
   [0, 1]
   ])
   The matrix above is the identity matrix. It should leave every vector unchanged.
   Test these matrices one at a time:
   Identity
   [1 0]
   [0 1]
   Double the x-component
   [2 0]
   [0 1]
   Double the y-component
   [1 0]
   [0 2]
   Swap x and y
   [0 1]
   [1 0]
   For every matrix:
   Predict the output.
   Calculate it manually.
   Run NumPy.
   Compare the visualization.

6. Scaling Transformations
   A scaling matrix has this structure:
   S=[
   s
   x
   ​

0
​

0
s
y
​

​
]
In Python, you need variables representing the scaling amounts:
scale_x = 2
scale_y = 3
Then construct the NumPy matrix yourself.
Think about what belongs in each location:
[ ? 0 ]
[ 0 ? ]
Scaling intuition
scale_x > 1: stretches horizontally
0 < scale_x < 1: shrinks horizontally
scale_x < 0: scales and reflects horizontally
scale_y > 1: stretches vertically
0 < scale_y < 1: shrinks vertically
scale_y < 0: scales and reflects vertically
Scaling experiment
Use:
vector = (2, 1)
Test these settings:
scale_x scale_y Predict
2 2 Uniform enlargement
0.5 0.5 Uniform shrinking
3 1 Horizontal stretch
1 4 Vertical stretch
-1 1 Horizontal reflection
Record the resulting vector each time. 7. Rotation Transformations
Rotation requires trigonometry.
Python's math module works with radians:
import math
Convert degrees to radians using:
angle_radians = math.radians(angle_degrees)
The rotation matrix contains:
cos(angle)
sin(angle)
-sin(angle)
Your task is to assemble those values into the correct 2 × 2 structure.
Useful tools:
math.cos(angle_radians)
math.sin(angle_radians)
Important floating-point behavior
Rotating (1, 0) by 90 degrees may produce something like:
(6.123e-17, 1.0)
The first value is effectively zero. Computers approximate trigonometric values using floating-point numbers.
You can clean displayed values with:
np.round(result, 5)
Do not change the underlying math just because a tiny numerical error appears.
Rotation experiments
Use the vector:
(3, 0)
Test:
Angle Expected direction
0° Right
45° Up and right
90° Up
180° Left
270° Down
360° Right again
For each one:
Predict the endpoint.
Build the matrix.
Multiply it by the vector.
Plot both vectors.
Check whether the magnitude changed.
A pure rotation should change direction but preserve length. 8. Useful NumPy Functions
Vector magnitude
Use:
np.linalg.norm(vector)
Test:
vector = np.array([3, 4])
Its magnitude should be 5.
For rotations, compare:
np.linalg.norm(original_vector)
np.linalg.norm(transformed_vector)
They should be approximately equal.
For scaling, they may differ.
Inspecting array shapes
Use:
print(vector.shape)
print(matrix.shape)
Expected:
vector shape: (2,)
matrix shape: (2, 2)
This develops the shape intuition you will need in machine learning.
Later, ML data may have shapes such as:
(1000, 20)
meaning:
1000 samples
20 features per sample
Checking values
Use:
print("Original:", vector)
print("Matrix:")
print(matrix)
print("Transformed:", transformed_vector)
Printing intermediate values is part of good numerical programming. Do not rely only on the graph. 9. Organize the Program into Functions
After the basic experiment works, divide responsibilities.
Potential functions include:
def create_scaling_matrix(...):
pass
def create_rotation_matrix(...):
pass
def transform_vector(...):
pass
def draw_vector(...):
pass
def configure_plot(...):
pass
Do not implement all of them simultaneously.
Recommended order:
Write everything in one file.
Confirm one vector displays.
Add one matrix transformation.
Extract drawing code into a function.
Extract scaling-matrix creation.
Extract rotation-matrix creation.
This prevents abstraction from hiding math you do not yet understand. 10. Suggested Application Flow
Your final program can eventually use a terminal menu:
Vector Transformation Visualizer

1. Scaling
2. Rotation
3. Exit

Choose a transformation:
For scaling, request:
Enter x scale:
Enter y scale:
For rotation:
Enter angle in degrees:
You will use:
input()
float()
Example concept:
value = float(input("Enter a value: "))
Add input validation only after the core math works. 11. Learning Checkpoints
Checkpoint A: Vectors
You are ready to proceed when you can explain:
what each vector component represents
why (3, -2) points right and downward
why vectors can begin at the origin
how magnitude differs from direction
Checkpoint B: Matrices
You are ready when you can explain:
why a transformation matrix is 2 × 2
why matrix @ vector produces another 2D vector
what each matrix row calculates
why \* is not appropriate here
Checkpoint C: Scaling
You are ready when you can predict:
how [2, 1] changes under horizontal scaling
what scaling by 0.5 does
what negative scaling does
why nonuniform scaling changes angles
Checkpoint D: Rotation
You are ready when you can explain:
why degrees must be converted to radians
why cosine and sine appear in the matrix
why rotation preserves magnitude
why floating-point answers may contain tiny errors
