import numpy as np
import matplotlib.pyplot as plt

vector = np.array([4,1])
b = np.array([-2,3])
c = np.array([0,-5])

print (vector)
# print(a[0])  # x component
# print(a[1])  # y component
print (b)
print (c)

plt.quiver(0,0, vector[0], vector[1], color='r', angles="xy",
scale_units="xy",
scale=1)
plt.quiver(0,0, b[0], b[1], color='g', angles="xy",
scale_units="xy",
scale=1)

plt.quiver(0,0, c[0], c[1], color='b', angles="xy",
scale_units="xy",
scale=1)

# plt.xlim(-10, 10)
# plt.ylim(-10, 10)
# plt.axhline(0)
# plt.axvline(0)
# plt.grid()
# plt.gca().set_aspect("equal")
# plt.show()

matrix = np.array([
    [3, 1],
    [-4, 1]
])
print('matrix',matrix)
transformed_vector = matrix @ vector

print ('transformed_vector',transformed_vector)