import cv2
import glob

if __name__=='__main__':
    filenames=glob.glob('bef/*.jpg')
    filenames.sort()
    face_cascade = cv2.CascadeClassifier('cvdata/haarcascade_frontalface_default.xml')
    for PATH in filenames:
        img=cv2.imread(PATH)
        gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
        faces=face_cascade.detectMultiScale(
            gray,
            scaleFactor=1.1,
            minNeighbors=5,
            minSize=(30, 30),
            flags=cv2.CASCADE_SCALE_IMAGE
        )
        if (len(faces)==0) :
            print("file "+PATH+" do not have faces")
            continue
        largest=faces[0]
        cnt=0
        for (x,y,w,h) in faces:
            (x1,y1,w1,h1)=largest
            if (w*h>w1*h1):
                largest=faces[cnt]
            cv2.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), 2)
            cnt+=1
    
        (x1,y1,w1,h1)=largest
        new_img=img[y1:y1+h1,x1:x1+w1:]
        #new_img=cv2.resize(new_img,(500,500))
        newname='new/'+PATH[:-4].strip('bef/')+"_new.jpg"
        print(newname)
        cv2.imwrite(newname,new_img)
        cv2.imwrite(PATH,img)
    pass