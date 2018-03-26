import numpy as np

def linearConv(kernel, vector, type='full'):
    """Realize linear convolution between two one-dimensional arrays.

    Keyword arguments:
    kernel -- first input array
    vector -- second input array
    type   -- mode of the convolution (default 'full' )
    """

    #create result vector
    if type=='full':
        m = len(vector) + len(kernel) - 1
        diff = 0
    elif type=='same':
        m = len(vector) if len(vector) >  len(kernel) else len(kernel)
        diff = int(np.ceil(2 * m  - len(kernel) - len(vector))/2)

    result = [ 0 for x in range(m)]

    for i in range(len(vector), m+1):
        vector = np.insert(vector, len(vector), 0)
    for i in range(len(kernel), m+1):
        kernel = np.insert(kernel, len(kernel), 0)

    #convolution
    for i in range(diff, m+diff):
        sum = 0
        for j in range(0, i+1):
            sum += vector[j] * kernel[i-j] 
        result[i-diff] = sum  
          
    return result