import transform
import projections

### Using wavelets for compression
#let n = 16

# v in standard basis
v = [4,5,3,7,4,5,2,3,9,7,3,5,0,0,0,0]

haar = transform.forward_no_normalization(v)
print(haar)
normCoefs = transform.normalize_coefficients(16, haar)
print(normCoefs)

vv = [1, 2]
print( projections.scalar_multiplication(2, vv))

#Haar basis
v1 = [0.5, -0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
v2 = [0, 0, 0.5, -0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
v3 = [0, 0, 0, 0, 0.5, -0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
v4 = [0, 0, 0, 0, 0, 0, 0.5, -0.5, 0, 0, 0, 0, 0, 0, 0, 0 ]
v5 = [0, 0, 0, 0, 0, 0, 0, 0, 0.5, -0.5, 0, 0, 0, 0, 0, 0 ]
v6 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, -0.5, 0, 0, 0, 0 ]
v7 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, -0.5, 0, 0 ]
v8 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, -0.5 ]
v9 = [0.5, 0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
v10 = [0, 0, 0, 0, 0.5, 0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0, 0, 0 ]
v11 = [0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0.5, -0.5, -0.5, 0, 0, 0, 0 ]
v12 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0.5, -0.5, -0.5 ]
v13 = [0.5, 0.5, 0.5, 0.5, -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0, 0, 0 ]
v14 = [0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, -0.5, -0.5, -0.5, -0.5 ]
v15 = [0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, -0.5, -0.5, -0.5, -0.5, -0.5,-0.5, -0.5, -0.5]
v16 = [0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5]
basis = [v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16]


newV = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

n = 8
j = 0
for i in range(16):
    print("[latexmath]")
    print("++++")
    s = "\[ w{"+str(j) + "}^{"+str(n)+"} = "
    print s
    print("\begin{array}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|}")
    print("\hline")
    newVec = projections.scalar_multiplication(normCoefs.get(n, j), basis[i])
    message = ""
    for el in newVec:
        message += str(el) + "&"

    print(message)
    print("\end{array}")
    print("\]")
    print("++++")
    if( j == n ):
        n /= 2
        j = 0
    else:
        j += 1

