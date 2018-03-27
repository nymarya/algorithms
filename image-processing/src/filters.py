import cv2

def apply_filter(image, filter, filepath, type=None, noise=None):
    """Apply filter to image.

    Keyword arguments:
    image      -- matrix with image 
    filter     -- matrix containing 
    filepath   -- path where image will be save
    """

    if (type == None):
        result = cv2.filter2D(image, -1, filter)
    elif (type == 'median'):
        result = cv2.medianBlur(image,noise)
    cv2.imwrite(filepath, result)