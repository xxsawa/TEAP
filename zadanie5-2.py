vstup = ">>><<<>>>>><<<>"
        


list1 = []
list2 = []
for i in vstup:
    for j in range(0,int(len(vstup)/2)-1):
        list2.append(None)
    list1.append(list2)
    list2 = []


for i in range(0,len(vstup)):
    if i % 2 == 0:
        print(i)
                        
                    
        for j in range(0,int(len(vstup)/2)):
            if len(vstup)-1-i-(j*2) < 1:
                break
            if j > 0:
                print(i+1,j*2)
                print(i+1+(j*2),len(vstup)-1-i-(j*2))
                print("\t\t",j*2,len(vstup)-1-i-(j*2))
                print(vstup[:i+1],"-",vstup[i+1:i+1+(j*2)],"-",vstup[i+1+(j*2):])
                if j == 1 or len(vstup)-1-i-(j*2) == 2:
                    if vstup[i+1:i+1+(j*2)] == ">>" or vstup[i+1:i+1+(j*2)] == "<<" or vstup[i+1:i+1+(j*2)] == "><" or vstup[i+1+(j*2):] == ">>" or vstup[i+1+(j*2):] == "<<" or vstup[i+1+(j*2):] == "><":
                        list1[i+1][j-1] = True
            if j == 0 and len(vstup)-1-i-(j*2) == 2:
                print("\t\t",j*2,len(vstup)-1-i-(j*2))



for i in list1:
    print(i)
