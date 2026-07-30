# WAP to perform Counting Sort on given data
default = [3, 2, 0, 5, 3, 7, 9, 2, 1, 1, 3]

ask = int(input("1. Default\n2. Custom\n0. Exit\nAns: "))

if ask == 2:
    new_list = input("Enter numbers separated by space: ")
    default = [int(i) for i in new_list.split()]

elif ask == 1:
    pass

elif ask == 0:
    print("Program End")
    exit()

else:
    print("Invalid Choice")
    exit()

print("Original List:", default)

max_element = max(default)

count = [0] * (max_element + 1)

for num in default:
    count[num] += 1

sorted_list = []

for i in range(len(count)):
    while count[i] > 0:
        sorted_list.append(i)
        count[i] -= 1

print("Sorted List:", sorted_list)