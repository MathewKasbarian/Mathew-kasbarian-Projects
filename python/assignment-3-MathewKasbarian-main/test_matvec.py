import numpy as np
from time import time                     # for timing the banded_matvec function
import matplotlib.pyplot as plt
from banded_matvec import banded_matvec   # your banded_matvec function


time = []
time2 = []
s=[]

for i in range(5, 9):
   n = 4**i
   a = np.random.rand(1, n - 1)
   b = np.random.rand(1, n)
   c = np.random.rand(1, n - 1)
   x = np.random.rand(1, n)
   s.append[n]
   # start the timer
   Start = time()
   # call banded_matvec
   banded_matvec(a[0], b[0], c[0], x[0])

   # stop the timer and store the wall time
   end = time()
   time.append(end - Start)

   A = np.zeros((n, n))
   for j in range(n):
      A[j][j] = b[0][j]
      if j < i - 1:
         A[j][j+1] = c[0][j]
         A[j+1][j] = a[0][j]

   Start = time()
   np.matmul(A, x[0])
   end = time()
   time2.append(end - Start) 
plt.loglog(s,time2)
plt.loglog(s,time)
plt.show()
