# Script for assignment 2, question 2.
import numpy as np
import matplotlib.pyplot as plt

# Import the function defined in the lecture.
from hor_dist import hor_dist
# Import the function you wrote for part 2(a).
from secant import secant

# Set parameters and initial values for secant.
x0 = np.pi/4
x1 = np.pi/2
err = 10e-12
res = 10e-12
k = 50


# Define a function of a single argument with c, v0 and g fixed.
def f(theta):
    return 9 - hor_dist(theta,0.001,9.81,10.0)

# Do secant iteration.
x, errors = secant(f,x0,x1,err,res,k)


# Plot the errors.
plt.semilogy(errors[:,1])
plt.show()


