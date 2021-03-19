#Author: Lennaert van Veen, Ontario Tech U, 2020.
# Python function that computes the distance travelled by a projectile with air friction.
# In: theta, angle of the shot; c, coefficient of air friction;
# g, accelleration of gravity; V0, initial speed. See lecture 2, slide 7/19 (point 2).
import numpy as np

def hor_dist(theta,c,g,V0):
    return (1/c) * np.log((c*V0*np.cos(theta)/np.sqrt(c*g)) *                    \
                       (np.arctan(np.sqrt(c/g)*V0*np.sin(theta)) +                 \
                        np.arccosh(np.sqrt((g+c* V0**2 * np.sin(theta)**2)/g)))+1.0)


