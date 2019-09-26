# Numpy

# Numpy takes lists or tuples as its argument
# Data arranged in an array-like structure can be converted to arrays and matrices through the use of the array() and matrix()
# If array is of type int and we have added a float value to it then it converts it to int

import numpy as np
a1 = np.array([0, 1, 2, 3, 4]) # 1D Array
a2 = np.array([ [1, 2, 3], [4, 5, 6] ], dtype = np.int32) # 2D Array
a3 = np.array([ [1.0, 2.0, 3.0], [4, 5, 6] ], dtype = complex) # 2D Complex Array
a4 = np.array([ [1, 2.0], [3, 0], (1 + 1j, 3.) ]) # Mix of tuples and lists, and data types

# Converting a list into array and matrix 
l1 = [ [1, 2, 3], [4, 5, 6] ] # Nested List
la = np.array(l1) # Converts List into Array
lm = np.mat(l1) # Converts List into Matrix

# Copying
print("Copying Demonstration:")
b1 = a1 # No new object is created. b is an alias to a
print(b1 is a1) # True. Since, both points to the same memory. Can verify using id(b1) == id(a1)
b2 = a1.copy() # A new object is created i.e. Deep Copying
print(b2 is a1) # False
print(50*'-')

# Accessing data can be done in either way
# Can access, slice, stride
print( a2[0,0] ) # Preferrable
#print( a2[0][0] )
print(50*'-')

# ndarray attributes
print("NumPy Array type is:", type(a2)) # What Type it is
print("The datatype of the Numpy Array elements is:", a2.dtype) # What DataType it consists of
print("No.of dimensions:", a2.ndim) # 1D or 2D or...
print("The size in bytes of each element is:", a2.itemsize) # No.of bytes of an element of the array
print("The size of the array is:", a2.size) # Prints no.of elements the array consists of
print("The shape of the arrays are:", a1.shape, "and", a2.shape) # Prints (m,n) i.e m*n matrix
print("The location of the array in the buffer:", a2.data)
print(50*'-')

# Array methods
# Most array has equivalent of arr.fun() as np.fun(arr)
print("Array Methods--")
print("Minimum element in array is:", a2.min())
print("Maximum element in array is:", a2.max())
print("Does array consists of all non-zero elements?:", a2.all())
print("Does array consists of atleast one non-zero element?:", a2.any())
print("Nonzero array is:", a2.nonzero())
a2.sort() # or np.sort(a2)
print("Sorted array is:", a2)
print(50*'-')

# Statistics
print("Array Statistics--")
print("Sum is:", a2.sum())
print("Mean is:", a2.mean())
print("Median of array is:", np.median(a2))
print("Standard Deviation is:", a2.std())
print("Correlation coefficient of array is:", np.corrcoef(a2))
print("Co-variance of array is:", np.cov(a2))
print(50*'-')

# arange()
print("arange Demonstration:")
# arange() will create arrays with regularly incrementing values
d = np.arange(4, dtype = float) # 0 to 3 numbers. Default step is 1
print(d)
# Start , Stop , Step and 1D array
e = np.arange(1, 4, 2) # Difference btw each element should be 2 and starts at 1 and ends at 4
print(e)
# reshape()
f = np.arange(12).reshape(3,4) # 0 to 12 numbers and 3*4 matrix
print(f)
# If an array is too large to be printed, NumPy automatically skips the central part of the array and only prints the corners
print(50*'-')

# linspace()
g = np.linspace(1., 4., 6) #  No.of elements should be 6 and Starting and ending elements should be 1. and 4. and evenly spaced
print(g)
print(50*'-')

#random
random_array = np.random.rand(5, 5) # Random numbers of [0,1) of 5*5 size
print(random_array)
print(50*'-')

# Matrices
zeros_matrix = np.zeros( (2, 3) ) # (2,3) is the shape i.e. 2*3 size matrix consisting of all zeroes
ones_matrix = np.ones( [2, 3] ) # 2*3 size matrix consisting of all ones
diag_matrix = np.diag( [1, 2, 3] )
identity_matrix = np.eye(3) # 3*3 Identity(eye) matrix

# Matrix Operations using Arrays
# Arithmetic operators on arrays apply elementwise. A new array is created and filled with the result

A = np.array([ [3, 6], [5, -3] ])
B = np.array([ [1, 1], [2, 1] ])
C = A + B # Addition
# dot for matrices and * for multiplying elements of matrices
C = A.dot(B) # Multiplication
C = np.dot(A, B) # or alternatively
C = A @ B # or alternatively
C = C.transpose() # Transpose of matrix array

# Matrix Class
m = np.mat(a2) # Converts an array into matrix and Creates a copy of array 'a2' i.e changing values in 'a2' doesn't changes in 'm'
m = np.asmatrix(a2) # m3 works as an alias to a2

m1 = np.mat([ [1,2], [1,2] ]) # Converts a list into matrix
m2 = m1

# Matrix Operations using matrices
m3 = m1*m2 # Multiplication
m3 = m1**3 # m1*m1*m1 i.e. Multiplication
m3 = m3.T # Transpose of matrix
m3 = m3.H # Conjugate Transpose of matrix
m3 = m1.I # Inverse of matrix
m3 = m3.A # asarray() of the matrix