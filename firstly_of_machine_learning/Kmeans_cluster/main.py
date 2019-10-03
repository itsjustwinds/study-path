from __future__ import print_function
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

np.random.seed(131)


def kmeans_display(X, label, num):
    plt.subplot(1, 2, num)
    if num==1:
        plt.title('Before')
    else:
        plt.title('After')
    K = np.amax(label) + 1
    X0 = X[label == 0, :]
    X1 = X[label == 1, :]
    X2 = X[label == 2, :]

    plt.scatter(X0[:, 0], X0[:, 1], c='red', s=11, marker='s')
    plt.scatter(X1[:, 0], X1[:, 1], c='blue', s=11, marker='^')
    plt.scatter(X2[:, 0], X2[:, 1], c='green', s=11, marker='o')


if __name__ == '__main__':
    means = [[2, 2], [8, 3], [3, 6]]
    cov = [[1, 0], [0, 1]]
    N = 500
    X0 = np.random.multivariate_normal(means[0], cov, N)
    X1 = np.random.multivariate_normal(means[1], cov, N)
    X2 = np.random.multivariate_normal(means[2], cov, N)
    X = np.concatenate((X0, X1, X2), axis=0)
    K = 3
    origin_label = np.asarray([0] * N + [1] * N + [2] * N)
    kmeans_display(X, origin_label,1)

    kmeans = KMeans(n_clusters=K, random_state=0).fit(X)
    print('Centers found by scikit-learn:')
    print(kmeans.cluster_centers_)
    pred_label = kmeans.predict(X)
    kmeans_display(X, pred_label,2)
    plt.suptitle('K-Means cluster')
    plt.show()
