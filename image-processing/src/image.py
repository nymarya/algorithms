import numpy as np
from cv2 import COLOR_BGR2GRAY, IMREAD_COLOR, IMREAD_GRAYSCALE, FONT_HERSHEY_PLAIN, THRESH_BINARY
from cv2 import cvtColor, imread, imwrite, rectangle, putText, threshold, blur
import convolution as conv
import filters
from skimage.measure import regionprops
from sklearn.metrics import mean_squared_error
import conv2d
from scipy import signal


face = imread('../data/dsc07348.jpg', IMREAD_COLOR)
faceGray = imread('../data/dsc07348.jpg', IMREAD_GRAYSCALE)
filtroPassaAlta = np.array([[-1,-1,-1],[-1,8,-1],[-1,-1,-1]], dtype=np.float32)
filtroPassaAlta2 = np.array([
    [-1,-1,-1, -1, -1],
    [-1,-1,-1, -1, -1],
    [-1,-1,24, -1, -1],
    [-1,-1,-1, -1, -1],
    [-1,-1,-1, -1, -1]
    ], dtype=np.float32)
filterDetector = np.array([[1,0,-1],[1,  0,-1],[1,0,-1]], dtype=np.float32)

filters.apply_filter(face, filtroPassaAlta, '../gallery/image1.png')
filters.apply_filter(faceGray, filtroPassaAlta, '../gallery/image2.png')
filters.apply_filter(face, filtroPassaAlta2, '../gallery/image3.png')
filters.apply_filter(faceGray, filtroPassaAlta2, '../gallery/image4.png')
filters.apply_filter(face, filterDetector, '../gallery/image5.png')
filters.apply_filter(faceGray, filterDetector, '../gallery/image6.png')
filters.apply_filter(face,  np.transpose(filterDetector), '../gallery/image7.png')
filters.apply_filter(faceGray,  np.transpose(filterDetector), '../gallery/image8.png')

###########################################
## Problem 1
    
array1 = np.array([1,2,3,4,5])
array2 = np.array([1,2,3])
print(np.convolve(array1, array2, 'same'))
print(conv.linear_conv(array1,array2, 'same'))

print(np.convolve(array1, array2))
print(conv.linear_conv(array1,array2))

print(np.convolve(array2, array1))
print(conv.linear_conv(array2,array1))

#########################################
#Problem 2
ar1 = np.array([
	[8, 5, 8, 1, 6, 8, 7],
	[9, 9, 2, 8, 2, 7, 8],
	[2, 9, 4, 9, 7, 3, 2],
	[9, 2, 9, 7, 1, 9, 5],
	[6, 9, 8, 7, 3, 1, 5],
	[1, 9, 9, 7, 1, 4, 6],
	[3, 5, 6, 4, 1, 4, 7]])

ar2 = np.array([
	[3,2,2],
	[1,1,3],
	[3,1,2]])

print(signal.convolve2d(ar1, ar2, 'full'))
print(conv2d.linear_conv2d(ar1,ar2))

print(signal.convolve2d(ar2, ar1, 'full'))
print(conv2d.linear_conv2d(ar2,ar1))

print(signal.convolve2d(ar1, ar2, 'same'))
print(conv2d.linear_conv2d(ar1,ar2, 'same'))

print(signal.convolve2d(ar2, ar1, 'same'))
print(conv2d.linear_conv2d(ar2,ar1, 'same'))


#########################################
#Problem 3

image = imread('../data/DL04_Img1.jpg', IMREAD_COLOR)
image_gray = cvtColor(image, COLOR_BGR2GRAY)

filter1 = np.array([[1.0/9.0 for x in range(0, 3)] for y in range(0, 3)], dtype=np.float32)
filter2 = np.array([[1.0/49.0 for x in range(0, 7)] for y in range(0, 7)], dtype=np.float32)
filter3 = np.array([[1.0/121.0 for x in range(0, 11)] for y in range(0, 11)], dtype=np.float32)

filters.apply_filter(image_gray, filter1, '../gallery/result1.png')
filters.apply_filter(image_gray, filter2, '../gallery/result2.png')
filters.apply_filter(image_gray, filter3, '../gallery/result3.png')
filters.apply_filter(image, filter3, '../gallery/result4.png')

#########################################
#Problem 4
noisen = imread('../data/DL04_Img2 (2).jpg', IMREAD_COLOR)
smooth_image = imread('../data/DL04_Img2 (1).jpg', IMREAD_COLOR)
noisen_image = np.array(smooth_image, dtype=np.uint8)
#make matrices with same shape
for i in range(3, 213):
    for j in range(3, 270):
        noisen_image[i-3][j-3] = noisen[i][j] 
        
error = filters.mse(smooth_image, smooth_image)
print(" erro teste  " + str(error))
filter5 = np.array([[1.0/25.0 for x in range(0, 5)] for y in range(0, 5)], dtype=np.float32)

mean1 = filters.apply_filter(noisen_image, filter1, '../gallery/mean1.png')
error = filters.mse(smooth_image, mean1)
print(" erro media 1: " + str(error))
mean2 = filters.apply_filter(noisen_image, filter5, '../gallery/mean2.png')
error = filters.mse(smooth_image, mean2)
print(" erro media 2: " + str(error))
mean3 = filters.apply_filter(noisen_image, filter2, '../gallery/mean3.png')
error = filters.mse(smooth_image, mean3)
print(" erro media 3: " + str(error))
mean4 = filters.apply_filter(noisen_image, filter3, '../gallery/mean4.png')
error = filters.mse(smooth_image, mean4)
print(" erro media 3: " + str(error))
median1 = filters.apply_filter(noisen_image, filter3, '../gallery/median1.png', 'median', 3)
error = filters.mse(smooth_image, median1)
print(" erro mediana 1: " + str(error))
median2 = filters.apply_filter(noisen_image, filter3, '../gallery/median2.png', 'median', 5)
error = filters.mse(smooth_image, median2)
print(" erro mediana 2: " + str(error))
median3 = filters.apply_filter(noisen_image, filter3, '../gallery/median3.png', 'median', 7)
error = filters.mse(smooth_image, median3)
print(" erro mediana 3: " + str(error))

#########################################
# Problem 5

#Detectin edges
map = imread('../data/DL04_Img3.jpg', IMREAD_COLOR)
map_gray = cvtColor(map, COLOR_BGR2GRAY)
map_sobel = filters.apply_filter(map_gray, [], '../gallery/map-sobel.png', 'sobel')
map_laplace = filters.apply_filter(map_gray, [], '../gallery/map-laplace.png', 'laplace')
map_canny = filters.apply_filter(map_gray, [], '../gallery/map-canny.png', 'canny')

for i in range(len(map_gray)):
    for j in range(len(map_gray[0])):
        border_canny = map_canny[i][j] != 0
        border_laplace = 230 <= map_laplace[i][j] <= 255
        border_sobel = 200 <= map_sobel[i][j] <= 255
        if( (230 <= map_gray[i][j] <= 255) or (border_canny) or border_laplace or border_sobel ):
            map_gray[i][j] = 0
        
r, thresh1 = threshold(map_gray,50,255,THRESH_BINARY)
imwrite('../gallery/thresh.png', thresh1)
regions = regionprops(thresh1)

country_area = 0
map = imread('../data/DL04_Img3.jpg')
for region in regions:
    # take regions with large enough areas
    country_area = region.area
    if region.area >= 100:
        # draw rectangle around segmented coins
        minr, minc, maxr, maxc = region.bbox


imwrite('../gallery/regions.png', map)

#segmentation
regions = filters.segmentation_region(map, '../gallery/')
p = 0.0
for (n,img) in enumerate(regions):
    filters.apply_filter(img, [], '../gallery/map'+str(n)+'-laplace.png', 'laplace')
    img_gray = cvtColor(img, COLOR_BGR2GRAY)
    r, thresh = threshold(img_gray,50,255,THRESH_BINARY)
    imwrite('../gallery/thresh'+str(n)+'.png', thresh)
    components = regionprops(thresh)
    for region in components:
        # take regions with large enough areas 
        state_area = region.area
        percent_area = state_area*100 / country_area
        p+= percent_area
        if region.area >= 100:
            # draw rectangle around segmented states
            minr, minc, maxr, maxc= region.bbox
            rectangle(map,(minc,minr),(maxc, maxr),(255,9,255),2)
            
            # write percentual area
            col = int((minc+maxc)/2)
            row = int((minr+maxr)/2)
            putText(map, "{:.2f}".format(percent_area)+'%',(col, row), FONT_HERSHEY_PLAIN, 1,(200,255,200))
            
imwrite('../gallery/final.png', map)
print(p)
