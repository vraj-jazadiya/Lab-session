import pandas as pd

#From a Dictionary
data = {
    'name' : ['Meet','jatin','mehul'],
    'age' : [6 ,35 ,14],
    'city' : ['rajkot','rajastan' ,'junagath' ]
}
df = pd.DataFrame(data)
# print(df)


#From a List to Dictionaries
data2 = [
    { 'Name' : 'Rathod','Age': 18},
    { 'Name' : 'Karan','Age': 22}
]
df2 = pd.DataFrame(data2)
# print(df2)


#listOfLists
data3 = [['Alice',25],['Bob',30]]
df3 = pd.DataFrame(data3 , columns=['name','age'])
print(df3)




