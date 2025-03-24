import cv2
from ultralytics import YOLO
import time

def main():
    # print('from main()')
    model  = YOLO("./models/yolo11m-pose.pt")
    model.to('cuda')
    capture = cv2.VideoCapture(0)

    while True:
        start_time = int(time.time()* 1000)
        success, image = capture.read()

        if success:
            results = model(image, device='cuda')

            ###// default drawing
            # annotated_frame = results[0].plot()
            # cv2.imshow('YOLOv11 DETECTION', annotated_frame)

            ##// manual drawoing
            keypoints = results[0].keypoints
            # confidence = keypoints.conf
            xy = keypoints.xy
            # print("Confidence --> ", confidence)
            # print(xy.shape)

            ##// Draw key points manually
            for person_idx in range(xy.shape[0]):
                print("Person ID -->", person_idx)

                point_x, point_y = [], []
                for pid, pxy in enumerate(xy[person_idx]):
                    px = int(pxy[0])
                    py = int(pxy[1])
                    if px != 0 and py != 0:
                        point_x.append(px)
                        point_y.append(py)
                        cv2.circle(image, (px, py), 5, (0, 255, 255))

        fps = int (1000 / (int(time.time() * 1000) - start_time))
        cv2.putText(image, 'FPS: ' + str(fps), (20, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 255), 2)
        cv2.imshow('YOLOv11 DETECTION', image)
        if cv2.waitKey(1) == ord('q'):
            break

    capture.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()