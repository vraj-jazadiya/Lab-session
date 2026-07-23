list = [10,20,30,40,50]

class test:
    def __init__(self):
        print("test class created")
    
    def avg(self , list):
        n = len(list)
        sum = 0
        for i in range(n):
            sum+=list[i]
            
        avg = sum/n
        return avg
    
t1 = test()

print(t1.avg(list))