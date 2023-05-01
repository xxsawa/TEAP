vstup = [5, 5, 4, 1, 4]
goals = 4

list1 = []
for i in range(0,2):
    list2= []
    for j in range(0,len(vstup)):
        list2.append([None,0])
    list1.append(list2)



for i in range(len(vstup)):

    if i+1 < len(vstup):
        if list1[0][i][0] != None:
            list1[0][i+1][0] = abs(vstup[i] - vstup[i+1]) + list1[0][i][0]
            list1[0][i+1][1] += list1[0][i][1] + 1
            if list1[1][i][0] != None:
                if abs(vstup[i] - vstup[i+1]) + list1[1][i][0] > list1[0][i+1][0]:
                    list1[0][i+1][0] = abs(vstup[i] - vstup[i+1]) + list1[1][i][0]
                    list1[0][i+1][1] += list1[1][i][1] + 1
        else:
            list1[0][i+1][0] = abs(vstup[i] - vstup[i+1])
            list1[0][i+1][1] += 2

        if list1[0][i+1][0] >= goals:
            print(list1[0][i+1][1])
            break


    if i+2 < len(vstup):
        if list1[0][i][0] != None:
            list1[1][i+2][0] = abs(vstup[i] - vstup[i+2]) + list1[0][i][0]
            list1[1][i+2][1] = list1[0][i][1] + 1
            if list1[1][i][0]:
                if abs(vstup[i] - vstup[i+2]) + list1[1][i][0] > list1[1][i+2][0]:
                    list1[0][i+1][0] = abs(vstup[i] - vstup[i+2]) + list1[1][i][0]
                    list1[1][i+1][1] = list1[1][i][1] + 1


                if abs(vstup[i] - vstup[i+2]) + list1[1][i][0] == list1[1][i+2][0]:
                    if list1[1][i+2][1] > list1[1][i][1] + 1:
                        list1[1][i+2][1] = list1[1][i][1] + 1




                    if list1[0][i+1][0] >= goals:
                        print(list1[0][i+1][1])
                        break
        else:
            list1[1][i+2][0] = abs(vstup[i] - vstup[i+2])
            list1[1][i+2][1] += 2

        if list1[1][i+2][0] >= goals:
            print(list1[1][i+2][1])

            break


    
    if i == len(vstup)-1:
        print(len(vstup))



