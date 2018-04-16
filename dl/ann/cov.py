import numpy as np
import math

##Resolucao da letra a
# @param container Lista de vetores
# @param x First variable index
# @param y Second variable index
def cov(matrix, x, y):
    
    mean_x = np.mean(matrix[x])
     
    mean_y = np.mean(matrix[y])
     
    cov = 0.0
    for i in range(0, matrix[x].shape[0]):
       cov += (matrix[x][i] - mean_x)*(matrix[y][i] - mean_y)
        
    return cov
     
def var(matrix, x):
    mean_x = np.mean(matrix[x])
    
    var = 0.0
    for i in range(0, matrix[x].shape[0]):
        var += ((matrix[x][i] - mean_x) * (matrix[x][i] - mean_x))
    
    return var
    
def corr(matrix, x, y):
    covCoeff = cov(matrix, x, y)
    varX = math.sqrt(var(matrix, x))
    varY = math.sqrt(var(matrix, y))
    
    
    return (covCoeff/(varX*varY))
     