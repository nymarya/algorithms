import numpy as np
from cv2 import COLOR_BGR2GRAY, IMREAD_COLOR, IMREAD_GRAYSCALE, FONT_HERSHEY_PLAIN, THRESH_BINARY, THRESH_OTSU
from cv2 import cvtColor, imread, imwrite, rectangle, putText, threshold, blur, GaussianBlur
import convolution as conv
import filters
import conv2d
from scipy import signal
from skimage.filters import threshold_otsu
from skimage.segmentation import clear_border
from skimage.measure import label, regionprops
from skimage.morphology import closing, square
from skimage.color import label2rgb

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
        border_sobel = 230 <= map_sobel[i][j] <= 255
        if( (230 <= map_gray[i][j] <= 255) or border_laplace  ):
            map_gray[i][j] = 0
        
#total area
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

#segmentation
regions = filters.segmentation_region(map, '../gallery/')

new_map = np.zeros((len(map)+100, len(map[0])+100, 3), dtype=np.uint8)
diff = [[0,0], [0,50],[70, -10],[40, 70],[70,30]]
for x in range(0,5):
    map_lap = filters.apply_filter(regions[x], [], '../gallery/map'+str(x)+'-laplace.png', 'laplace')
    for i in range(0, len(regions[x])):
        for j in range(0, len(regions[x][0])):
            r = regions[x][i][j][0]
            g = regions[x][i][j][1] 
            b = regions[x][i][j][2]
            border = map_lap[i][j]
            if( r != 0 or g!= 0 or b!=0 ):
                new_map[i + diff[x][0]][j + diff[x][1]] = regions[x][i][j]
            elif( border[0] != 0 and border[1] != 0 and border[2] != 0):
                new_map[i + diff[x][0]][j + diff[x][1]] = border
            

new_map_gray = cvtColor(new_map, COLOR_BGR2GRAY)
new_map_gray = GaussianBlur(new_map_gray,(5,5),0)
r, new_thresh = threshold(new_map_gray,50,255,THRESH_BINARY)

#ref: http://scikit-image.org/docs/dev/auto_examples/segmentation/plot_label.html
bw = closing(new_map_gray > 50, square(3))

# remove artifacts connected to image border
cleared = clear_border(bw)

# label image regions
label_image = label(cleared)

p = 0.0
for region in regionprops(label_image):
    state_area = region.area
    percent_area = state_area*100 / country_area
    p+= percent_area
    if region.area >= 100:
        # draw rectangle around segmented regions
        minr, minc, maxr, maxc = region.bbox
        rectangle(new_map,(minc,minr),(maxc, maxr),(255,9,255),2)
        
        # write percentual area
        col = int((minc+maxc)/2)-50
        row = int((minr+maxr)/2)
        putText(new_map, "{:.2f}".format(percent_area)+'%',(col, row), FONT_HERSHEY_PLAIN, 1.5,(200,200,200), 2)
              
#imwrite('../gallery/regions.png', new_map)
imwrite('../gallery/final.png', new_map)
