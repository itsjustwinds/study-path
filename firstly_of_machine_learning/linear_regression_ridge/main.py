from __future__ import print_function
import numpy as np
import matplotlib.pyplot as plt

x = np.array([[147, 150, 153, 155, 158, 160, 163, 165, 168, 173, 175, 178, 180, 183]]).T
y = np.array([49, 50, 51, 52, 54, 56, 58, 59, 60, 63, 64, 66, 67, 68])

one = np.ones((x.shape[0], 1))
X = np.concatenate((one, x), axis=1).T
A = np.dot(X, X.T)
tmp = np.array([[0.00000001, 0], [0, 0.00000001]])
A = A + tmp

w = np.dot(np.linalg.pinv(A), np.dot(X, y))
plt.scatter(x, y, s=10, c='red')
plt.title("Weight by height")
plt.xlabel("Height")
plt.ylabel("Weight")
plt.plot(x, w[0] + w[1] * x, c="green", label='f(x)')
plt.legend()
plt.show()
