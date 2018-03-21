from scipy import ndimage, misc
import numpy as np
import cv2

face = cv2.imread('../data/dsc07348.jpg')
filtroPassaAlta = np.array([[-1,-1,-1],[-1,8,-1],[-1,-1,-1]], dtype=np.float32)
filtroPassaAlta2 = np.array([
    [-1,-1,-1, -1, -1],
    [-1,-1,-1, -1, -1],
    [-1,-1,24, -1, -1],
    [-1,-1,-1, -1, -1],
    [-1,-1,-1, -1, -1]
    ], dtype=np.float32)
filterDetector = np.array([[1,0,-1],[1,0,-1],[1,0,-1]], dtype=np.float32)

ddepth = -1

img = list()
img.append(face)
img.append(face)
img.append(cv2.filter2D(face, ddepth, filtroPassaAlta))
img.append(cv2.filter2D(face, ddepth, filtroPassaAlta2))
img.append(cv2.filter2D(face, ddepth, filterDetector))
img.append(cv2.filter2D(face, ddepth, np.transpose(filterDetector)))

import matplotlib.pyplot as plt

n_images = len(img)
fig = plt.figure()
for n, (image) in enumerate(img):
    a = fig.add_subplot(np.ceil(n_images/2.0), 2, n + 1)
    if image.ndim == 2:
        plt.gray()
    plt.imshow(image)
    a.set_title("Image ("+str(n)+")")
fig.set_size_inches(np.array(fig.get_size_inches()) * n_images)
plt.show()