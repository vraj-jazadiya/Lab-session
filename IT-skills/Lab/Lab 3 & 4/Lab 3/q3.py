import pandas as pd

data = (
    [   {'ram' : 5 , 'anil' : 7 , 'Simple': 10},
        {'ram' : 6 , 'anil' : 6 , 'Simple': 10},
        {'ram' : 7 , 'anil' : 5 , 'Simple': 10}
    ]
)

df = pd.DataFrame(data,index=['R1','R2','R3'])

df['amit'] = [4,4,10]

df.loc['R4'] = [1,1,1,1]

print(df)
print("\n")

df = df.drop('R2', axis=0)
print(df)