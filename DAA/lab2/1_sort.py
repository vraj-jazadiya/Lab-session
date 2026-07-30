# Write a program to sort a given list of numbers in either ascending/descending order 

List = [55,20,3,66,77]

getList = int(input("1. default \n2. custom \n0.exit \nans: "))
ask = int(input("1. ascending \n2. descending \n0.exit \nans: "))

def display(lst):
    print(lst)

def aSort(list,n):
    if list == 1 and ask == 1:
        List.sort()
        display(List)
    elif list == 1 and ask == 2:
        List.sort(reverse=True)
        display(List)
        
    elif list == 2 and ask == 1:
        getList = input("Enter num separated by space: ").strip()
        newList = [int(i) for i in getList.split()]
        newList.sort()
        display(newList)
        
    elif list == 2 and ask == 2:
        getList = input("Enter num separated by space: ").strip()
        newList = [int(i) for i in getList.split()]
        
        newList.sort(reverse=True)
        display(newList)
            
            
aSort(getList,ask)