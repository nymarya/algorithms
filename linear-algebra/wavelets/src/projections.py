"""
Return the inner product of the vectors a and b
"""
def inner_product(a, b):
    sum = 0.0;
    for i in range(0,len(a)):
        sum += a[i] * b[i]

    return sum

"""
Calculate a - b
"""
def sub_vectors(a, b):
    newList = [];
    for i in range(0,len(b)):
        newList.append(a[i] - b[i])

    return newList

def sum_vectors(a, b):
    newList = [];
    for i in range(0,len(b)):
        newList.append(a[i] + b[i])

    return newList

"""
Project vector b onto the span of v.
"""
def project_along(b, v):
    sigma = (inner_product(b,v)/inner_product(v,v)) if inner_product(v,v) != 0 else 0
    newV = []
    for i in range(0, len(v)):
        newV.append(sigma * v[i])

    return newV


"""
Project vector b orthogonal to vector v.
"""
def project_orthogonal_vector(b, v):
    return sub_vectors(b, project_along(b, v))

def project_orthogonal(b, v):
    """Project vector b orthogonal to list v.

    Keyword arguments:
    b -- the vector to be projected
    v -- the list of mutually orthogonal vectors
    """
    for el in v:
        b = sub_vectors(b, el)
    return b

def scalar_multiplication(a, v):
    """
    """
    for el in v:
        el *= a

    return v

def get_norm(v):
    """
    Return the norm of v
    """
    return sqrt(inner_product(v,v))