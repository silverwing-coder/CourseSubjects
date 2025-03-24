import cv2
from ultralytics import YOLO
import math
import time

def main():
    # print('from main()')
    model  = YOLO("./models/yolo11m.pt")
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
    capture = cv2.VideoCapture(0)

    while True:
        success, image = capture.read()

        if success:
            start_time = int(round(time.time() * 1000))
            results = model(image, stream=True)
            # results = model.predict(image, stream=True)

            for r in results:
                # print(len(r))
                boxes = r.boxes
                for box in boxes:
                    confidence = math.ceil((box.conf[0] * 100)) / 100
                    if confidence > 0.7:
                        x1, y1, x2, y2 = box.xyxy[0]
                        x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)

                        cv2.rectangle(image, (x1, y1), (x2, y2), (0, 255, 2555), 2)
                        print('Confidence--> ', confidence)
                        cls = int(box.cls[0])
                        print('Class name --> ', class_names[cls])

                        origin = [x1, y1]
                        font = cv2.FONT_HERSHEY_SIMPLEX
                        font_scale = 1
                        font_color = (255, 255, 255)
                        thickness = 1
                        cv2.putText(image, class_names[cls], origin, font, font_scale, font_color, thickness)

            fps = int ((1 / (int(round(time.time() * 1000)) - start_time)) * 1000)
            cv2.putText(image, "FPS:" + str(fps), (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
            cv2.imshow('YOLOv11 DETECTION', image)

        if cv2.waitKey(1) == ord('q'):
            break

    capture.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()