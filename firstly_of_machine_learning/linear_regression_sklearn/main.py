from __future__ import print_function
import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets, linear_model

Idata = np.array([[-3, -2, -1, 0, 1, 2, 3]])
X = np.zeros((3, 7))
for i in range(7):
    X[0][i] = Idata[0][i] ** 2
    X[1][i] = Idata[0][i]
    X[2][i] = np.sin(Idata[0][i])
X = X.T
y = np.array([7.5, 3, 0.5, 1, 3, 6, 14])

regr = linear_model.LinearRegression()
regr.fit(X, y)
w3 = regr.coef_[0]
w2 = regr.coef_[1]
w1 = regr.coef_[2]
w0 = regr.intercept_

plt.title('f(x)=(%.2fx^2) + (%.2fx) + (%.2fsin(x))+(%.2f)' % (w3, w2, w1, w0))
plt.xlabel('X')
plt.ylabel('Y')
line = []
tmp = -5
while tmp <= 5:
    line.append(tmp)
    tmp = tmp + 0.01
plt.scatter(line, [w3 * x * x + w2 * x + w1 * np.sin(x) + w0 for x in line], c='green', s=1)
plt.scatter(Idata, y, s=10, c='red')
plt.show()
