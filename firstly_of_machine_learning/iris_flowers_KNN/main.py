from __future__ import print_function
import numpy as np
from sklearn import neighbors, datasets
from sklearn.model_selection import train_test_split  # for splitting data
from sklearn.metrics import accuracy_score  # for evaluating results


def myweight(distances):
    sigma2 = 0.4
    return np.exp(-distances ** 2 / sigma2)


np.random.seed(9)
iris = datasets.load_iris()
iris_X = iris.data
iris_y = iris.target
k = 1
while 1:
    sum = 0.0
    for i in range(0, 50):
        X_train, X_test, y_train, y_test = train_test_split(iris_X, iris_y, train_size=100)
        model = neighbors.KNeighborsClassifier(n_neighbors=k, p=2, weights=myweight)
        model.fit(X_train, y_train)
        y_predict = model.predict(X_test)
        acc = 1.0 * accuracy_score(y_predict, y_test)
        sum += acc
    print("percentage of predicting of %.0f is: %.2f %%" % (k, (sum/50) * 100))
    if k == 20:
        break
    k += 1
