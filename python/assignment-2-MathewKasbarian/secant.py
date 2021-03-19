# Template for secant iteration needed for question 2(a,b).
# Include an output argument called "errors". It must be a numpy array with one row for each completed iteration and, on every row, the iteration number and the error, like this:
# [[0, initial error],[1, error after one iteration], ...]
import numpy as np
def secant(f,x0,x1,eps_x,eps_f,kMax):
    x2 = x1
    conv = 0
    errors = np.empty((0,2))

    for k in range(kMax):

        fpx = (f(x1)-f(x0))/(x1-x0)
        dx = -f(x1)/fpx
        err = abs(dx)
        x2 += dx
        residual = abs(f(x2))
        errors = np.vstack((errors, [k,err]))
        print("it %d err=%e res=%e" % (k,err,residual))
        if err < eps_x and residual < eps_f:
            conv = 1
            break
        x0 = x1
        x1 = x2

    if conv == 0:
        print("Warning: no convergence after %d iterations." % (kMax))

    print (errors)
    return x2,errors
