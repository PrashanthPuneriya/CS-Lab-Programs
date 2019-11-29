import pandas as pd


p_data = {'ID': [1, 2, 3, 4], 'Names': ['John', 'Bob', 'James', 'Bond'], 'Marks' : [95, 100, 80, 90]}
df1 = pd.DataFrame( data = p_data )
df1.to_csv('table2.csv', index = False, header = True)
df = pd.read_csv('table2.csv') # If removed names then the header doesn't appears

# Working on Data
print(df)
max_value = df['Marks'].max()
print(max_value) # Prints max value of the column marks
print(50*'-')
max_name = df['Names'][df['Marks'] == df['Marks'].max()].values # Prints name who has max marks
print(max_name)
print(50*'-')
print(df['Marks'].describe())
print(50*'-')
print(50*'-')
# Add a column
p_year = [2000, 1999, 2001, 1998]
df['Year'] = p_year
print(df)
print(50*'-')
# Delete a column
del df['Year']
print(df)
print(50*'-')
# Editing a column's data
df['Marks'] = df['Marks'] - 1
print(df)
print(50*'-')
print(50*'-')



