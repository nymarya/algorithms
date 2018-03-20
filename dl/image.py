from scipy import ndimage, misc
import numpy as np

face = imread('dsc07348.jpg')

filterDetector = np.array([[1,1,1],[1,1,0],[1,0,0]])
face = face[:,:,None]

#img = ndimage.filters.convolve(face, filterDetector, mode='constant')
img = ndimage.sobel(face, 8)

import matplotlib.pyplot as plt
plt.imshow(img)
plt.show()