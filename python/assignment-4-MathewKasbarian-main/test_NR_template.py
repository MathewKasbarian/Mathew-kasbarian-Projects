import numpy as np
from NR import NR
import matplotlib.pyplot as plt

def Function(a):           # define the vector-valued function F as in the assignment PDF
    function = np.zeros((3,1))
    function[0] = -(a[1]**2) - a[2]**2 - (1/4 * a[0]) + 2
    function[1] = (a[0] * a[1]) - (4 * a[0] * a[2]) - a[1] + 1
    function[2] = (4 * a[0] * a[1]) + (a[0] * a[2]) - a[2]
    return function
 

def DofF(a):              # compute and return the Jacobian of F, i.e. the matrix of partial derivatives
    P = np.zeros((3,3))
    P[0,0] = -(1/4)
    P[0,1] = 2 * a[1]
    P[0,2] = -(2 * a[2])
    P[1,0] = a[1] - (4 * a[2])
    P[1,1] = a[0] - 1
    P[1,2] = - (4 * a[0])
    P[2,0] = 4 * a[1] + a[2]
    P[2,1] = 4 * a[0]
    P[2,2] =  a[0] - 1
    return P



    

# Set the inputs for Newton-Raphson:
x0 = np.matrix([[7.0],[0.0],[0.0]]) 
Max = 10
err = 10e-12
res = 10e-12
x, err,res = NR(Function,DofF,x0,Max,res,err)
print("The approximate solution is:")
print(x)
print("With residual %e and apprximate error %e." % (res,err))
