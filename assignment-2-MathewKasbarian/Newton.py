# Template for Newton iteration needed for question 1(e). 
# You can copy and paste from the Newton iteration function in the course_codes repository.
# Add an output argument called "errors". It must be a numpy array with one row for each completed iteration and, on every row, the iteration number and the error, like this:
# [[0, initial error],[1, error after one iteration], ...]
import numpy as np
def Newton(f,df,x0,eps_x,eps_f,kMax):
    x = x0
    conv = 0
    errors = np.empty((0,2))
    for k in range(kMax):
        fx = f(x)
        fpx = df(x)
        dx = -fx/fpx
        err = abs(dx)      # dx is x_{k+1} - x_{k}
        residual = abs(fx)
        x += dx
        errors = np.vstack((errors, [k,err]))
        print("it %d err=%e res=%e" % (k,err,residual))
        if err < eps_x and residual < eps_f:
            conv = 1
            break
    if conv == 0:
        print("Warning: no convergence after %d iterations." % (kMax))

    print (errors)
    return x,errors
