from scipy import ndimage, misc
import numpy as np
import cv2
import os

face = cv2.imread('../data/dsc07348.jpg', cv2.IMREAD_COLOR)
faceGray = cv2.imread('../data/dsc07348.jpg', cv2.IMREAD_GRAYSCALE)
filtroPassaAlta = np.array([[-1,-1,-1],[-1,8,-1],[-1,-1,-1]], dtype=np.float32)
filtroPassaAlta2 = np.array([
    [-1,-1,-1, -1, -1],
    [-1,-1,-1, -1, -1],
    [-1,-1,24, -1, -1],
    [-1,-1,-1, -1, -1],
    [-1,-1,-1, -1, -1]
    ], dtype=np.float32)
filterDetector = np.array([[1,0,-1],[1,  0,-1],[1,0,-1]], dtype=np.float32)

ddepth = -1

img = list()
img.append(face)
img.append(faceGray)
img.append(cv2.filter2D(face, ddepth, filtroPassaAlta))
img.append(cv2.filter2D(faceGray, ddepth, filtroPassaAlta))
img.append(cv2.filter2D(face, ddepth, filtroPassaAlta2))
img.append(cv2.filter2D(faceGray, ddepth, filtroPassaAlta2))
img.append(cv2.filter2D(face, ddepth, filterDetector))
img.append(cv2.filter2D(faceGray, ddepth, filterDetector))
img.append(cv2.filter2D(face, ddepth, np.transpose(filterDetector)))
img.append(cv2.filter2D(faceGray, ddepth, np.transpose(filterDetector)))

import matplotlib.pyplot as plt

n_images = len(img)
for n, (image) in enumerate(img):
    cv2.imwrite('../gallery/image'+str(n)+'.png',image)