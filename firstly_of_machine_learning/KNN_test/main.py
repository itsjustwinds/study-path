from __future__ import print_function
import numpy as np
import matplotlib.pyplot as plt
from time import time


def distant_pp(x, z):
    val = z - x
    return np.sum(val * val)


def native(X,z):
    res=np.zeros((X.shape[0],1))
    for i in range(0,X.shape[0]):
        res=distant_pp(X[i],z)
    return res


def fast(X, z):
    X2 = np.sum(X * X, axis=1)
    z2 = np.sum(z * z)
    return X2 + z2 - 2 * np.dot(X, z.T)


X = np.array([[1, 2, 3, 4],
              [5, 6, 7, 8],
              [9, 10, 11, 12],
              [13, 14, 15, 16]])
z = np.array([11, 13, 14, 15])

print(native(X,z))
print()
print(fast(X,z))