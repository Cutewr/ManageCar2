import time

import hyperlpr3 as lpr3
import sys
import cv2
import numpy as np

if __name__ == "__main__":
    # 读取通过标准输入传递的图像数据
    begin=time.time()
    image_data = sys.stdin.buffer.read()

    # 将图像数据转换为 NumPy 数组
    nparr = np.frombuffer(image_data, np.uint8)

    # 解码 JPEG 图像
    frame = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
    catcher = lpr3.LicensePlateCatcher()
    # 在这里进行图像处理
    result=catcher(frame)
    end=time.time()
    print(result)
    print("time is"+str(end-begin+2))
