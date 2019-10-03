from __future__ import print_function
import numpy as np
from sklearn import neighbors, datasets
from sklearn.model_selection import train_test_split  # for splitting data
from sklearn.metrics import accuracy_score  # for evaluating results


def num_to_string(num):
    res = ""
    num = int(num)
    while num:
        res = str(num % 10 + int('0')) + res
        num = int(num / 10)
    return res


def filestring_to_num(s):
    res = 0
    for i in s:
        if (i == '\n'):
            break
        if (int(i) >= int('0')) and (int(i) <= int('9')):
            res = res * 10 + int(i) - int('0')
    return res


def convert(Str):
    f = open("student/student-" + Str + ".csv", 'r')
    content = None
    if f.mode == 'r':
        content = f.readlines()
    f.close()

    f = open("student/" + Str + "-data.txt", 'w')
    f.write(num_to_string(395) + "\n")
    f.write(num_to_string(33) + "\n")
    first = 1
    for line in content:
        if first == 1:
            first = 0
            continue
        now = 0
        for i in range(0, 33):
            val = ""
            while 1:
                if line[now] == '"':
                    now += 1
                    continue
                if line[now] == ';':
                    now += 1
                    break
                val = val + line[now]
                now += 1
                if now == len(line):
                    break
            if i == 32:
                f.write(val)
                continue
            f.write(val + "\n")
    f.close()


def myweight(distances):
    sigma2 = 0.4
    return np.exp(-distances ** 2 / sigma2)


def get_best_K(X, y):
    k = 1
    best = 0
    val_best = 0.0
    while 1:
        sum = 0.0
        for i in range(0, 50):
            X_train, X_test, y_train, y_test = train_test_split(X, y, train_size=330)
            model = neighbors.KNeighborsClassifier(n_neighbors=k, p=2, weights=myweight)
            model.fit(X_train, y_train)
            y_predict = model.predict(X_test)
            acc = 1.0 * accuracy_score(y_predict, y_test)
            sum += acc
        print("percentage of predicting of %.0f is: %.2f %%" % (k, (sum / 50) * 100))
        if (sum / 50) * 100 > val_best:
            val_best = (sum / 50) * 100
            best = k
        if k == 330:
            break
        k += 1
    return best


def main():  # 395 students
    # convert("mat")
    # convert("por")
    np.random.seed(131)
    f = open("student/mat-data.txt", 'r')
    line = f.readline()
    n = int(line)
    line = f.readline()
    m = int(line)
    X = np.zeros((n, m - 1))
    y = np.array([])
    for i in range(0, n):
        for j in range(0, 33):
            line = f.readline()
            if j == 6:
                X[i][j] = int(line)
                continue
            if j == 7:
                X[i][j] = int(line)
                continue
            if j == 8:
                if line == "teacher\n":
                    X[i][j] = 1
                continue
            if j == 9:
                if line == "teacher\n":
                    X[i][j] = 1
                continue
            if j == 10:
                if line == "course\n":
                    X[i][j] = 1
            if j == 13:
                X[i][j] = filestring_to_num(line)
            if j == 14:
                X[i][j] = filestring_to_num(line)
            if j == 15:
                if line == "yes\n":
                    X[i][j] = 1
            if j == 16:
                if line == "yes\n":
                    X[i][j] = 1
            if j == 17:
                if line == "yes\n":
                    X[i][j] = 1
            if j == 18:
                if line == "yes\n":
                    X[i][j] = 1
            if j == 19:
                if line == "yes\n":
                    X[i][j] = 1
            if j == 20:
                if line == "yes\n":
                    X[i][j] = 1
            if j == 21:
                if line == "yes\n":
                    X[i][j] = 1
            if j == 22:
                if line == "yes\n":
                    X[i][j] = 1
            if j == 23:
                X[i][j] = filestring_to_num(line)
            if j == 24:
                X[i][j] = filestring_to_num(line)
            if j == 25:
                X[i][j] = filestring_to_num(line)
            if j == 26:
                X[i][j] = filestring_to_num(line)
            if j == 27:
                X[i][j] = filestring_to_num(line)
            if j == 28:
                X[i][j] = filestring_to_num(line)
            if j == 29:
                X[i][j] = filestring_to_num(line)
            if j == 30:
                X[i][j] = filestring_to_num(line)
            if j == 31:
                X[i][j] = filestring_to_num(line)
            if j == 32:
                y = np.append(y, [filestring_to_num(line)])
    #res=get_best_K(X,y)
    res=310
    X_train, X_test, y_train, y_test = train_test_split(X, y, train_size=330)
    model = neighbors.KNeighborsClassifier(n_neighbors=310, p=2, weights=myweight)
    model.fit(X_train, y_train)
    print(model.predict(X))
    f.close()


if __name__ == "__main__":
    main()

#wrong !