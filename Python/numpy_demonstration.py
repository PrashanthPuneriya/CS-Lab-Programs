# Numpy

# Numpy takes lists or tuples as its argument
# Data arranged in an array-like structure can be converted to arrays and matrices through the use of the np.array() and np.mat()
# If array is of type int and we have added a float value to it then it converts it to int

import numpy as np
a1 = np.array([0, 1, 2, 3, 4]) # 1D Array
a2 = np.array([ [1, 2, 3], [4, 5, 6] ], dtype = np.int32) # 2D Array
a3 = np.array([ [1.0, 2.0, 3.0], [4, 5, 6] ], dtype = complex) # 2D Complex Array. Prints in i+j form
a4 = np.array([ [1, 2.0], [3, 0], (1 + 1j, 3.) ]) # Mix of tuples and lists data type. Doesn't print decimals and i+j since it has default data type as int

# Converting a list into array and matrix 
l1 = [ [1, 2, 3], [4, 5, 6] ] # Nested List. Is in 1-D way
la = np.array(l1) # Converts List into Array. Is in 2-D way
lm = np.mat(l1) # Converts List into Matrix
lm = np.asmatrix(l1)

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
print("NumPy Array type is:", type(a2)) # What Type it is : <class 'numpy.ndarray'>
print("The datatype of the Numpy Array elements is:", a2.dtype) # What DataType it consists of: int32
print("No.of dimensions:", a2.ndim) # 1D or 2D or... = 2
print("Total no.of bytes occupied:", a2.nbytes)
print("The size in bytes of each element is:", a2.itemsize) # No.of bytes occupied by an element of the array = 4
print("The size i.e no.of elements in the array is:", a2.size) # Prints no.of elements the array consists of = 6
print("The shape of the arrays are:", a1.shape, "and", a2.shape) # Prints (m,n) i.e m*n matrix = (5,) and (2, 3)
print("The location of the array in the buffer:", a2.data)
print(50*'-')

# Array methods
# np.fun(arr) is equivalent to arr.fun(). Both works
print("Array Methods--")
print("Minimum element in array is:", np.min(a2))
print("Maximum element in array is:", np.max(a2))
print("Does array consists of all non-zero elements?:", np.all(a2))
print("Does array consists of atleast one non-zero element?:", np.any(a2))
print("Indices of elements of the array that are non-zero is:", np.nonzero(a2)) # Returns tuples of arrays. One for each dimension. If used zip function it gives index of each non-zero element
print("Sorted array is:", np.sort(a2))
print(50*'-')

# Statistics
print("Array Statistics--")
print("Sum is:", np.sum(a2))
print("Mean is:", np.mean(a2)) # or np.average(a2)
print("Median of array is:", np.median(a2))
print("Standard Deviation is:", np.std(a2))
print("Correlation coefficient of array is:", np.corrcoef(a2))
print("Co-variance of array is:", np.cov(a2))
print(50*'-')

# arange()
print("arange Demonstration:")
# arange() will create arrays with regularly incrementing values
d = np.arange(4, dtype = float) # Start = 0, Stop = 3, Step = 1
print(d)
e = np.arange(1, 8, 2) # Start = 1, Stop = 4, Step = 2
print(e)
# reshape()
f = np.arange(12).reshape(3,4) # Start = 0, Stop = 11, Step = 1 and 3*4 matrix
print(f)
g = f.reshape(3,3)
# If an array is too large to be printed, NumPy automatically skips the central part of the array and only prints the corners
print(50*'-')

# linspace()
h = np.linspace(1., 4., 6) # Start = 1., Stop = 4. and the no.of elements = 6 and evenly spaced
print(g)
print(50*'-')

# Random numbers generator. Here the input size arg is different. No need to put the size in paranthases
random_array = np.random.rand(5, 5) # Random numbers of [0,1) of 5*5 size
# For integers use np.random.randint(start_range, stop_range, size=(m,n))
print(random_array)
print(50*'-')

# Matrices
zeros_matrix = np.zeros( (2, 3) , dtype = np.int32 ) # (2,3) is the shape i.e. 2*3 size matrix consisting of all zeroes
ones_matrix = np.ones( [2, 3] ) # 2*3 size matrix consisting of all ones
diag_matrix = np.diag( [1, 2, 3] )
identity_matrix = np.eye(3) # 3*3 Identity(eye) matrix
full_matrix = np.full( (3,3), 99 )

# Matrix Operations using Arrays
A = np.array([ [3, 6], [5, -3] ])
B = np.array([ [1, 1], [2, 1] ])
C = A + B # Addition
C = A * B # Element-Wise Multiplication
C = A.dot(B) # Matrix Multiplication
C = np.dot(A, B) # or alternatively
C = A @ B # or alternatively
C = C.transpose() # Transpose of matrix array

# Matrix Class
m = np.mat(a2) # Converts an array into matrix and Creates a copy of array 'a2' i.e changing values in 'a2' doesn't changes in 'm'
m = np.asmatrix(a2) # Alternatively

m1 = np.mat([ [1,2], [1,2] ]) # Converts a list into matrix
m2 = m1 # m2 is alias to m1

# Matrix Operations using matrices
m3 = m1*m2 # Multiplication
m3 = m1**3 # m1*m1*m1 i.e. Multiplication
m3 = m3.T # Transpose of matrix
m3 = m3.H # Conjugate Transpose of matrix
m3 = m1.I # Inverse of matrix
m3 = m3.A # asarray() of the matrix