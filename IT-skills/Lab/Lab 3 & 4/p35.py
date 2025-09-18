# this is 66 sildes pptx testing programs

import pandas as pd

data = pd.DataFrame( [[2,23,4,21] ,[10,10,10,1] ,[20,20,20,1] , [30,30,30,2]] , index=['R1','R2','R3','R4'] ,columns=['Ram','Daya','Meet','Jatin'])

print(data)

# df= data.rename({'R1':'Maths'})
# df2= data.rename({'Ram':'Harsh'})
#
# print(df)
# print(df2)

# print(data.loc['R3'])
# print("--------------")
# print(data[['Ram','Meet']])
# print("--------------")
# print(data.loc[:,['Ram','Meet']])
print("--------------")
# print(data.iloc[:,1:2])
# print(data.loc['R1':'R3','Ram':'Meet'])
# print(data.loc['R1']<10)

data1 = pd.DataFrame( [[2,23,4,21] ,[10,10,10,1] ,[20,20,20,1] , [30,30,30,2]] , index=['R5','R6','R7','R8'] ,columns=['yash','Dahi','Mayur','Jagu'])
print(data1)

print("--------------")

merge = data.append(data1 , sort=False)
print(merge)