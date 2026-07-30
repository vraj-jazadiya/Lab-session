# WAP to find Minimum and Maximum of the given set of integer values
default = [3, 1, 8, 0, 9, 5, 2]

ask = int(input("1. default\n2. custom\n0. exit()\nAns: "))

if ask == 2:
    new_list = input("Enter num separated by space: ")
    default = [int(i) for i in new_list.split()]

elif ask == 1:
    pass

elif ask == 0:
    print("Programmy ended")
    exit()

else:
    print("! Choice")
    exit()

print("Given List:", default)

minimum = default[0]
maximum = default[0]

for num in default:
    if num < minimum:
        minimum = num
    if num > maximum:
        maximum = num

print("Min Value =", minimum)
print("Max Value =", maximum)