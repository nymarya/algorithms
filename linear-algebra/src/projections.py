"""
Project vector b onto the span of v.
"""
def project_along(b, v):
    sigma = ((b*v)/(v*v)) if (v*v) != 0 else 0
    return sigma*v


"""
Project vector b orthogonal to v.
"""
def project_orthogonal(b, v):
    return b - project_along(b, v);
