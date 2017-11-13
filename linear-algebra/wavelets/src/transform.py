from __future__ import division
from math import sqrt

def forward_no_normalization(v):
    """
    The representation of v in terms of the Haar wavelet basis is stored in a dictionary.

    Keyword arguments:
    v -- the vector to be projected
    """
    D = {}
    while len(v) > 1:
        k = len(v)
        # v is a k-element list
        vnew = [(v[2*i]+v[2*i+1])/2 for i in range(k//2)]
        # vnew is a k//2-element list
        w = [(v[i]-v[i+1]) for i in range(0, k, 2)]
        # w is a list of coefficients
        D.update(dict([ ((k//2, i), w[i]) for i in range(k//2) ]))
        v = vnew
       
    # v is a 1-element list
    D[(0,0)] = v[0] #store the last coefficient
    return D

def normalize_coefficients(n, D):
    """
    """
    dic = {}
    for el in D.items():
        square = sqrt(n / (4*el[0][0])) if el[0][0] != 0 else sqrt(n)
        dic. update({(el[0][0], el[0][1]): el[1 ]* square})
        D.update(dic)

    return dic