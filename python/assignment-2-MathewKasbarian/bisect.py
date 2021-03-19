# Template for the bisection function needed for question 1(d). 
# You can copy and paste from the bisection function in the course_codes repository.
# Add an output argument called "errors". It must be a numpy array with one row for each completed iteration and, on every row, the iteration number and the error, like this:
# [[0, initial error],[1, error after one iteration], ...]
import numpy as np
def bisect(a, b, k_max, eps_x, eps_f, f):
    l = a
    r = b
    
    errors = np.empty((0,2))

    conv = 0                         # flag for convergence, default is "not converged"
    for k in range(k_max):           # loop over at most k_max bisection steps
        m = (l+r)/2.0                # find the current mid point
        f_m = f(m)                 # compute the function value there
        f_l = f(l)                # compute the function value at the left hand side
        if f_l * f_m > 0:       # if they have the same sign...
            l = m                   # update the left boundary, else...
        else:
            r = m                    # update the right boundary
        max_err = abs(r-l)           # compute the maximal error and the residual
        residual = abs(f_m)
        errors = np.vstack((errors,[k,max_err]))

        print("iteration %d err=%e res=%e" % (k,max_err,residual))
        if max_err < eps_x and residual < eps_f: # if both are less than their tolerance, stop
            conv = 1                 # flag convergence
            break
    if conv == 0:                    # print warning if the iterations did not converge
        print("No convergence after %d iterations!" % (k_max))            
    print (errors)
    return m,errors # return the approximate solution and maximal error
