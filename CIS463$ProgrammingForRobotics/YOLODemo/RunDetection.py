from ultralytics import YOLO
import cv2
import math
import time


def main():
    capture = cv2.VideoCapture(0)
    model_path = 'models/yolo11m.pt'

    detector = YOLO(model_path)
    detector.to('cuda')

    class_names = ["person", "bicycle", "car", "motorbike", "aeroplane", "bus", "train", "truck", "boat",
                  "traffic light", "fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat",
                  "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella",
                  "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard", "sports ball", "kite", "baseball bat",
                  "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle", "wine glass", "cup",
                  "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange", "broccoli",
                  "carrot", "hot dog", "pizza", "donut", "cake", "chair", "sofa", "pottedplant", "bed",
                  "diningtable", "toilet", "tvmonitor", "laptop", "mouse", "remote", "keyboard", "cell phone",
                  "microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors",
                  "teddy bear", "hair drier", "toothbrush"
                  ]

    while True:
        start_time = int(time.time() * 1000)
        success, image = capture.read()

        if success:
            results = detector(image, device='cuda')
            for result in results:
                # print(result)
                for box in result.boxes:
                    confidence = math.ceil((box.conf[0] * 100)) / 100
                    if (confidence > 0.7):
                        x1, y1, x2, y2 = int(box.xyxy[0][0]), int(box.xyxy[0][1]), int(box.xyxy[0][2]), int(box.xyxy[0][3])
                        cv2.rectangle(image, (x1, y1),  (x2, y2), (255, 255, 255), 1)
                        class_id = int(box.cls[0])
                        cv2.putText(image, class_names[class_id], (x1, y1), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255 , 0), 2)

        fps = int(1 / (int(time.time() * 1000) - start_time) * 1000)
        cv2.putText(image, 'FPS:' + str(fps), (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255 , 255), 2)
        cv2.imshow('DETECTION MODEL', image)

        if cv2.waitKey(1) == ord('q'):
            break

    capture.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()