import torch
import cv2
import sys
import pathlib
pathlib.PosixPath = pathlib.WindowsPath

model_path = r'best.pt'
model = torch.hub.load('ultralytics/yolov5', 'custom',
                       path=model_path)
model.conf = 0.8  # Confidence threshold (0-1)
model.iou = 0.2

def detect(image):
    frame = image
    frame = cv2.resize(frame, (1280, 720))
    detections = model(frame[..., ::-1])
    results = detections.pandas().xyxy[0].to_dict(orient="records")

    if len(results) > 0:
        print(results)
        print('\n')

    for result in results:
        cs = result['name']
        con = round((result['confidence'])*100, 2)
        x1 = int(result['xmin'])
        y1 = int(result['ymin'])
        x2 = int(result['xmax'])
        y2 = int(result['ymax'])
		
        cv2.putText(frame, f"{cs} {con}%", (x1, y1-5),
                    cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 2)
        cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 255), 2)
        
        print(f'Oil Spill Detected!')
        print(f'Confidence: {con}%')
        
    cv2.imshow('Output', frame)

    if cv2.waitKey(1) == 32:
        cv2.destroyAllWindows()
        sys.exit()


if __name__ == "__main__":
    # vid_location = r'/media/ragib314/Ragib/Computer Vision/Oil Spill Detection/Test.mp4'
    webcam = cv2.VideoCapture('vid1.mp4')
    while True:
        ret, im = webcam.read()
        if ret:
            detect(im)
