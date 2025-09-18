import pandas as pd
import numpy as np

ar1 = np.array([1,2,3,4])
ar2 = np.array([10,20,30,40])
ar3 = np.array([11,22,33,44])

df = pd.DataFrame([ar1,ar2,ar3] , index=[2,3,4] ,columns=['a1','a2','a3','a4'])
print(df)