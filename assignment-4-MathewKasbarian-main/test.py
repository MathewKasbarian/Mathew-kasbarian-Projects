import numpy as np
def lowerProduct(A,B):
    flop = 0
    n = np.shape(A)[0]
    C = np.zeros([n,n])
    for i in range(0,n):
        for j in range(0,i+1):
            for k in range (j,i+1):
                print('C[', i, j, ']', C[i,j], '+=', A[i,k], '*', B[k,j])
                C[i,j] += A[i,k] * B[k,j]
                flop += 2

    return C, flop