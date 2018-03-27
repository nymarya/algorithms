import cv2

def apply_filter(image, filter, filepath):
    """Apply filter to image.

    Keyword arguments:
    image      -- matrix with image 
    filter     -- matrix containing 
    filepath   -- path where image will be save
    """

    result = cv2.filter2D(image, -1, filter)
    cv2.imwrite(filepath, result)