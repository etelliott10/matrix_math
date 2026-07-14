import numpy as np

# Vector addition
# [3, 4] + [1, 2] = [4, 6]
a = np.array([3, 4])
b = np.array([1, 2])
print(a)
print(b)
# Output:[4 6]
print(a + b)

# Scalar multiplication
# 3 * [2, 4] = [6, 12]
v = np.array([2, 4])
# output: [ 6 12]
print(3 * v)

# Dot
# [2, 3] · [4, 5] = 2*4 + 3*5 = 23
a = np.array([2, 3])
b = np.array([4, 5])
dot = np.dot(a, b)
# output: 23
print(dot)

# Cosine Similarity in NumPy
# cosine_similarity(a, b) = (a · b) / (||a|| * ||b||)

a = np.array([3, 4])
b = np.array([6, 8])

cos_sim = np.dot(a, b) / (np.linalg.norm(a) * np.linalg.norm(b))
# output: 1.0
print(cos_sim)

# 4. Matrix-Vector Multiplication in NumPy
# Matrix
A = np.array([
    [2, 1],
    [0, 3]
])

# Vector
v = np.array([4, 5])
# first output  = 2*4 + 1*5 = 13
# second output = 0*4 + 3*5 = 15
result = A @ v
# Output: [13 15]
print('Matrix @ Vector:', result)


# 5. Matrix-Matrix Multiplication in NumPy
A = np.array([
    [1, 2],
    [3, 4]
])

B = np.array([
    [5, 6],
    [7, 8]
])
# output:
# [[19 22]
#  [43 50]]
print(A @ B)
# A @ B   # matrix multiplication
# A * B   # element-by-element multiplication

# 6. Transpose in NumPy
A = np.array([
    [1, 2, 3],
    [4, 5, 6]
])

print(A.shape)
print(A.T)
print(A.T.shape)

# 7. Small Neural Network Math
# output = input @ weights + bias
# z = x @ W + b
# | Symbol     | Meaning                 |
# | ---------- | ----------------------- |
# | `x`        | input vector            |
# | `W`        | weight matrix           |
# | `b`        | bias vector             |
# | `z`        | raw output              |
# | activation | function applied to `z` |
x = np.array([1.0, 2.0, 3.0])
W = np.array([
    [0.2, 0.8],
    [0.5, 0.1],
    [0.9, 0.3]
])
b = np.array([0.1, -0.2])

z = x @ W + b

print(z)

# 8. Activation Functions
# ReLU
# if value < 0, make it 0
# if value >= 0, keep it
# ReLU(x) = max(0, x)
def relu(x):
    return np.maximum(0, x)

z = np.array([4.0, -1.5, 0.2])

a = relu(z)

print(a)

# Sigmoid
# squashes values between 0 and 1
# sigmoid(x) = 1 / (1 + e^(-x))
# useful for binary probability-style outputs
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

z = np.array([-2, 0, 2])
# [0.119 0.5   0.881]
print(sigmoid(z))


# 9. Tiny Neural Network: One Hidden Layer
# x @ W1 + b1 = hidden layer raw values
# ReLU = hidden layer activated values
# a1 @ W2 + b2 = final output

x = np.array([1.0, 2.0])

W1 = np.array([
    [0.5, -0.2, 0.1],
    [0.3,  0.8, 0.7]
])

b1 = np.array([0.1, 0.0, -0.1])

W2 = np.array([
    [0.4],
    [0.6],
    [0.2]
])

b2 = np.array([0.05])

z1 = x @ W1 + b1
a1 = relu(z1)

z2 = a1 @ W2 + b2

print("z1:", z1)
print("a1:", a1)
print("z2:", z2)

# 10. Batch Inputs
# In real AI, you usually process many examples at once