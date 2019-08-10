# -*- coding: UTF-8 -*-

# cái dòng trên cùng để ghi được ký tự unicode

import cv2

if __name__ == "__main__":

	# đọc một tấm ảnh theo đường dẫn được cho
    img = cv2.imread('a.jpg')
    # ảnh là một ma trận 3 chiều <cao> x <rộng> x <số kênh màu>, ảnh màu có 3 kênh RGB, ảnh trắng đen có 1 kênh
    # print kích thước ảnh
    print img.shape

    # tạo đối tượng face_cascade để thực hiện việc phát hiện khuôn mặt
    # đây là đối tượng thuộc lớp CascadeClassifier (về sau học môn OOP sẽ rõ)
    face_cascade = cv2.CascadeClassifier('cvdata/haarcascade_frontalface_default.xml')

    # biến ảnh 3 kênh thành 1 kênh
    # đầu vào các hàm của thư viện OpenCV thường ảnh là 1 kênh
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # lưu ảnh ra ổ cứng để xem thử
    cv2.imwrite('gray.jpg', gray)

    # detect các khuôn mặt
    # faces là một mảng, mỗi phần tử là một cấu trúc (x, y, w, h)
    # x, y: tọa độ góc trái trên của khuôn mặt (gốc tọa độ là pixel 0,0)
    # w, h: kích thước
    faces = face_cascade.detectMultiScale(
        gray,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30),
        flags=cv2.CASCADE_SCALE_IMAGE
    )

    # in ra số lượng khuôn mặt
    print len(faces), ' found'

    # thực hiện xén từng khuôn mặt ra và lưu xuống ổ cứng với tên 0.jpg, 1.jpg, 2.jpg
    count = 0
    for (x,y,w,h) in faces:
        img_face = img[y:y+h, x:x+w, :]
        cv2.imwrite('%d.jpg'%(count), img_face)
        count += 1

    pass