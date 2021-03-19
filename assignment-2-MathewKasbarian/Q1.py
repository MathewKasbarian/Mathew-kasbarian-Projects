# Script for assignment 2, question 1.
import numpy as np
import matplotlib.pyplot as plt

# Import the functions you wrote for parts 1(d) and 1(e).
from bisect import bisect
from Newton import Newton

def f(x):
    return np.exp(-x) - x        # insert function
def df(x):
    return -(np.exp(-x)) - 1      # insert derivative

# Set parameters and initial values for bisection.
l = 0
r = 2
k = 50
epsx = 10e-12
epsf = 10e-12
# Do bisection.
x_bisection, errors_bisection = bisect(l,r,k,epsx,epsf,f)

# Set parameters and initial values for Newton iteration.
x0 = 0
epsx = 10e-12
epsf = 10e-12
k = 50
# Do Newton iteration.
x_Newton, errors_Newton = Newton(f,df,x0,epsx,epsf,k)

# Plot the errors.
plt.semilogy(errors_bisection[:,1])
plt.semilogy(errors_Newton[:,1])
plt.show()







