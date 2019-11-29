# Pandas
# NaN = Not a Number
import pandas as pd
# Creating a dataset using Series
data1 = { 'first_column' : pd.Series( [1., 2., 3.], index=['a', 'b', 'c'] ), 'second_column' : pd.Series( [1., 2., 3., 4.], index =['a', 'b', 'c', 'd'] ) }
# Creating a dataframe
df1 = pd.DataFrame(data1)
# Creating a dataset using Lists and DataFrame
p_id = [1, 2, 3, 4]
p_name = ['John', 'Bob', 'James', 'Bond']
p_marks = [95, 100, 80, 90]
p_data = list(zip(p_id, p_name, p_marks))
# Creating a dataframe
df2 = pd.DataFrame( data = p_data )
# Writing to a csv(common separated values) file
df2.to_csv('table1.csv', index = False, header = False) # No header will be present in the csv file
# Reading from a csv file
df = pd.read_csv('table1.csv', names = ['ID', 'Names', 'Marks']) # If removed names then the header doesn't appears
# Reading from a excel file --- df = pd.read_excel


# Finding Datatypes of columns
print(df.dtypes)
print(50*'-')
# Finding Datatype of a specific column
print(df.Names.dtypes)
print(50*'-')
print(50*'-')

# Printing DataFrames

print(df)
print(50*'-')
print(df.head(2)) # Prints top 2 rows
print(50*'-')
print(df.tail(2)) # Prints bottom 2 rows
print(50*'-')
print(50*'-')

# Printing headers
print(df.columns)
print(50*'-')
# Printing pairs
print(df.values)
print(50*'-')
# Printing Index
print(df.index)
print(50*'-')
print(50*'-')

# Accessing and Indexing data


# Printing data of a 'row' using integer index. Here no row name is given
print(df.iloc[1:3])
print(50*'-')

# Printing data of a specific row and column using integer index
print(df.iloc[1,1])
print(50*'-')
print(50*'-')

print(df['Marks'])
print(df.Marks) # Alternatively

# Printing data of multiple columns
print(df[ ['ID','Names'] ])
print(50*'-')