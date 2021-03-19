import numpy as np

def banded_matvec(a,b,c,x):
    # Insert code to compute the product y of the banded matrix A (specified by a, b and c) with vector x.
    y=[]
    j=0
    for i,j in range(len(x)):
        if i==0:
            y.append(b[i]*x[i]+c[i]*x[i])

        elif i==(len(x)-1):
            y.append(b[i]*x[i]+a[j]*x[i])
        else:
            y.append(a[j]*x[i]+b[i]*x[i]+c[i]*x[i])
            j+=1
    return y
