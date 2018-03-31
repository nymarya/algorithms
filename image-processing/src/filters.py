import cv2
import numpy as np

def apply_filter(image, filter, filepath, type=None, noise=None):
    """Apply filter to image.

    Keyword arguments:
    image      -- matrix with image 
    filter     -- matrix containing 
    filepath   -- path where image will be save
    """

    bla = np.array([])
    if (type == None):
        result = cv2.filter2D(image, -1, filter)
    elif (type == 'median'):
        result = cv2.medianBlur(image,noise)
    elif (type == 'laplace'):
        result = cv2.Laplacian(image,cv2.CV_64F)
    elif (type == 'sobel'):
        result = cv2.Sobel(image,cv2.CV_64F,0,1,ksize=3)
    elif (type == 'canny'):
        result = cv2.Canny(image,100,200)
        
    cv2.imwrite(filepath, result)
    return result
    
def segmentation_region(image, filepath):
    
    # define the list of boundaries BGR
    # first is lower bound and second upper bound
    boundaries = [
    	([0, 120, 120], [30, 255, 255]), #Norte
    	([0, 120, 0], [20, 255, 80]), # Nordeste
    	([0, 0, 140], [20, 40, 255]), # Centro-Oeste
    	([120, 0, 0], [255, 100, 100]), #Suldeste
    	([120, 120, 0], [255, 255, 50]) #Sul
    ]
    
    images = list()
    
    # loop over the boundaries
    i = 0
    for (lower, upper) in boundaries:
    	# create NumPy arrays from the boundaries
    	lower = np.array(lower, dtype = "uint8")
    	upper = np.array(upper, dtype = "uint8")
     
    	# find the colors within the specified boundaries and apply
    	# the mask
    	mask = cv2.inRange(image, lower, upper)
    	output = cv2.bitwise_and(image, image, mask = mask)
     
    	images.append(output)
     
    	# show the images
    	cv2.imwrite(filepath+ "/map"+str(i)+".png",  output)
    	i+=1
    
    return images
 
def mse(image1, image2):
	"""Calculate Mean Square Error

    Keyword arguments:
    image1     -- matrix with image 
    image2     -- matrix with image 
    """
    
	error = ((image1 - image2) ** 2).mean(axis=None)
	
	return error
    