
a = 5000
b = 200

################################x
a += 1
b += 2

list1 = [0,0]
for i in range(0,a):
    list1[0] = list1[1]
    list1.pop()
    list2 = [[0,0]]*b
    for j in range(0,b):
        if i == j and j < b-1:
            if j == b - 2:
                list2[j] = [1,0]  
            else:  
                list2[j] = [1,1]
        elif j == b-1 :
            list2[j] = [0,0]
        elif j < i and a-j > i and j < b-1 and j > 0:
            list2[j] = [0,0]
            if j == i-1 and i > 1:
                list2[j][0] = (list1[0][j][0] + list1[0][j-1][0]) % 100000007
            if j < i-1 and j > i-a and i > 1 and j > 0:
                list2[j][0] = (list1[0][j][0] + list1[0][j-1][0] + list1[0][j+1][0]) % 100000007

            if j == i-1 and i > 1 and j < b-2:
                list2[j][1] = (list1[0][j][1] + list1[0][j-1][1]) % 100000007
            if j < i-1 and j > i-a and i > 1 and j > 0 and j < b-2:
                list2[j][1] = (list1[0][j][1] + list1[0][j-1][1] + list1[0][j+1][1]) % 100000007
    list1.append(list2)
print((list1[0][1][0] - list1[0][1][1]) % 100000007)
