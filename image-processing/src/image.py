import numpy as np
from cv2 import imread, cvtColor, IMREAD_COLOR, IMREAD_GRAYSCALE, COLOR_BGR2GRAY, threshold
from cv2 import THRESH_BINARY, imwrite, rectangle, putText, FONT_HERSHEY_PLAIN, LINE_AA
import convolution as conv
import filters
from skimage.filters import threshold_otsu
from skimage.segmentation import clear_border
from skimage.measure import label, regionprops
from skimage.morphology import closing, square
from skimage.color import label2rgb


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
noisen_image = imread('../data/DL04_Img2 (2).jpg', IMREAD_COLOR)
filters.apply_filter(noisen_image, filter1, '../gallery/mean1.png')
filters.apply_filter(noisen_image, filter2, '../gallery/mean2.png')
filters.apply_filter(noisen_image, filter3, '../gallery/mean3.png')
filters.apply_filter(noisen_image, filter3, '../gallery/median1.png', 'median', 3)
filters.apply_filter(noisen_image, filter3, '../gallery/median2.png', 'median', 5)


#########################################
# Problem 5

#Detectin edges
map = imread('../data/DL04_Img3.jpg', IMREAD_COLOR)
map_gray = cvtColor(map, COLOR_BGR2GRAY)
filters.apply_filter(map_gray, [], '../gallery/map-sobel.png', 'sobel')
filters.apply_filter(map_gray, [], '../gallery/map-laplace.png', 'laplace')
filters.apply_filter(map_gray, [], '../gallery/map-canny.png', 'canny')

map_canny = imread('../gallery/map-canny.png', IMREAD_COLOR)
for i in range(len(map_gray)):
    for j in range(len(map_gray[0])):
        if( 230 <= map_gray[i][j] <= 255 ):
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
print(country_area)
#segmentation
regions = filters.segmentation_region(map, '../gallery/')
teste = 0
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
        teste += percent_area
        if region.area >= 100:
            # draw rectangle around segmented states
            minr, minc, maxr, maxc= region.bbox
            rectangle(map,(minc,minr),(maxc, maxr),(200,255,200),2)
            
            # write percentual area
            col = int((minc+maxc)/2)
            row = int((minr+maxr)/2)
            putText(map, "{:.2f}".format(percent_area)+'%',(col, row), FONT_HERSHEY_PLAIN, 1,(255,9,255))
            
imwrite('../gallery/final.png', map)

print(teste)
