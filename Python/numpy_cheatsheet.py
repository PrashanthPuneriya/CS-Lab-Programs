import numpy as np

a = np.array( [ [1,2,3], [4,5,6] ] , dtype = np.int32 )
a2 = np.array([ [1, 2.0], [3, 0], (1 + 1j, 3.) ]) # Default dtype is int
l = [ [1,2,3], [4,5,6] ]

la = np.array(l)
lm = np.mat(l)
lm = np.asmatrix(l)

b = a.copy() # A new object is created i.e. Deep Copying

print( a[0,0] ) # Preferrable
print( a[0][0] )

# Returns answer
type(a)
a.dtype
a.ndim
a.nbytes
a.itemsize
a.size
a.shape
a.data

# Returns answer
np.min(a)
np.max(a)
np.all(a)
np.any(a)

np.nonzero(a)
np.sort(a)

np.sum(a)
np.average(a)
np.mean(a)
np.median(a)
np.std(a)
np.corrcoef(a)
np.cov(a)

d = np.arange(4, dtype = np.int32) # Start = 0, Stop = 3, Step = 1
e = np.arange(1, 4, 2) # Start = 1, Till = 4, Step = 2
f = np.arange(12).reshape(3,4) # Start = 0, Stop = 11, Step = 1 and 3*4 matrix
g = np.linspace(1., 4., 6) # Start = 1., Stop = 4. and the no.of elements = 6 and evenly spaced
random_array = np.random.rand(5, 5) # Random numbers of [0,1) of 5*5 size

zeros_matrix = np.zeros( (2, 3) , dtype = np.int32) 
ones_matrix = np.ones( [2, 3] ) 
diag_matrix = np.diag( [1, 2, 3] )
identity_matrix = np.eye(3) 
full_matrix = np.full( (3,3), 99 )

# Arrays
A = np.array([ [3, 6], [5, -3] ])
B = np.array([ [1, 1], [2, 1] ])
C = A + B # Addition
C = A * B # Element-Wise Multiplication
C = A.dot(B) # Matrix Multiplication
C = np.dot(A, B) # or alternatively
C = A @ B # or alternatively
C = C.transpose() # Transpose of matrix array

m1 = np.mat( [ [1,2], [1,2] ] ) # Converts a list into matrix
# Matrix Operations using matrices
m2 = m1*m1 # Multiplication
m2 = m1**3 # m1*m1*m1 i.e. Multiplication
m2 = m2.T # Transpose of matrix
m2 = m2.H # Conjugate Transpose of matrix
m2 = m1.I # Inverse of matrix
m2 = m2.A # asarray() of the matrix