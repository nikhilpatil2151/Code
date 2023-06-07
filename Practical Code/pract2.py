
value1 = {22, 3, 4, 23, 1}
value2 = {4, 63, 5, 6, 3}

print(value1.union(value2))
print(value1.intersection(value2))
print(value1.difference(value2))
print(value1.symmetric_difference(value2))
print(value2.symmetric_difference(value1))


def Union(list1, list2):
    return list1+list2


def Intersection(list1, list2):
    l3 = [value for value in list1 if value in list2]
    return l3


def Difference(list1, list2):
    temp3 = []
    for element in list1:
        if element in list2:
            temp3.append(element)


list1 = []
list2 = []

number = int(input("How many element you want to insert in List 1 : "))

for i in range(number):
    ele = int(input())
    list1.append(ele)

number1 = int(input("How many element you want to insert List 2 : "))
for i in range(number1):
    ele = int(input())
    list2.append(ele)

print(list1)
print(list2)

for i in range(len(list1)):
    for j in range(len(list2)):
        if (list1[i] == list2[j]):
            print("match")
            print(list1[i])


print(Union(list1, list2))
print(Intersection(list1, list2))
print(Difference(list1, list2))
