
vstup = ">><<>>><<>><><><<>>><<>>><<<>><>>>>>>>><>>>>><<><"

nevyznamny = "<<<<<<<<<<><<<<<><<<<<<<<<<>< <<<<<<<<<><<"


ukonc = 0

1111111111111111111111111111111111111110

arr2d = []

dvojice = []
if vstup[0]+vstup[1+0] == "<<" or vstup[0]+vstup[1+0] == "><":
    dvojice.append(1)
else:
    dvojice.append(0)

for i in range(1,len(vstup)-2):
    if vstup[i]+vstup[i+1] == ">>" or vstup[i]+vstup[i+1] == "><" or vstup[i]+vstup[i+1] == "<<":
        dvojice.append(1)
        continue
    dvojice.append(0)
if vstup[len(vstup)-2]+vstup[len(vstup)-1] == "><" or vstup[len(vstup)-2]+vstup[len(vstup)-1] == ">>":
    dvojice.append(1)
else:
    dvojice.append(0)
print(2,"\t",dvojice)
arr2d.append(dvojice)
# 
for j in range(2,int((len(vstup)-1)/2)+1):
    ktice = []
    for i in range(0,(len(vstup)-j*2)+1):
        if i == 0:
            if (vstup[(j-1)*2+1] == '<' and arr2d[j-2][i+1]) or (arr2d[j-2][0] and arr2d[0][(j-1)*2]):
                ktice.append(1)
                continue

            od_zadu = j*2
            pocitadlo = 0
            koniec = 0
            while(j-2-(int(pocitadlo/2)-1) > 0):
                od_zadu -= 2
                pocitadlo += 2
                if arr2d[int(pocitadlo/2)-1][i] and arr2d[j-2-(int(pocitadlo/2)-1)][i+pocitadlo]:
                    ktice.append(1)
                    koniec = 1
                    break      
            
            if koniec:
                continue
                

            ktice.append(0)
        elif i == len(vstup)-j*2:
            if ((vstup[i]+vstup[i+(j-1)*2+1] == "><" or vstup[i]+vstup[i+(j-1)*2+1] == ">>") and arr2d[j-2][i+1]) or (arr2d[0][i] and arr2d[j-2][i+2]):
                ktice.append(1)
                continue

            od_zadu = j*2
            pocitadlo = 0
            koniec = 0
            while(j-2-(int(pocitadlo/2)-1) > 0):
                od_zadu -= 2
                pocitadlo += 2
                if arr2d[int(pocitadlo/2)-1][i] and arr2d[j-2-(int(pocitadlo/2)-1)][i+pocitadlo]:
                    ktice.append(1)
                    koniec = 1
                    break      
            
            if koniec:
                continue
                
                
            ktice.append(0)
        else:
            if ((vstup[i]+vstup[i+(j-1)*2+1] == "<<" or vstup[i]+vstup[i+(j-1)*2+1] == "><" or vstup[i]+vstup[i+(j-1)*2+1] == ">>") and arr2d[j-2][i+1]) or (arr2d[0][i] and arr2d[j-2][i+2]):
                ktice.append(1)
                continue

            od_zadu = j*2
            pocitadlo = 0
            koniec = 0
            while(j-2-(int(pocitadlo/2)-1) > 0):
                od_zadu -= 2
                pocitadlo += 2
                if arr2d[int(pocitadlo/2)-1][i] and arr2d[j-2-(int(pocitadlo/2)-1)][i+pocitadlo]:
                    ktice.append(1)
                    koniec = 1
                    break      
            
            if koniec:
                continue       
            ktice.append(0)
    print(j*2,"\t",ktice)
    arr2d.append(ktice)

vysledok = ""


for i in range(int((len(vstup)-1)/2)+1):    
    if i == 0:
        if arr2d[int((len(vstup)-1)/2)-1][i+1]:
            vysledok += "o."
        else:
            vysledok += ".."
    elif i == int(len(vstup)-1)/2: 
        if arr2d[int((len(vstup)-1)/2)-1][0]:
            vysledok += "o"
        else:
            vysledok += "."
    
    elif arr2d[i-1][0] and arr2d[int((len(vstup)-1)/2)-(1+i)][(i*2)+1]:
        vysledok += "o."

    else:
        vysledok += ".."
print(vysledok)
        

# dvojice = []


# if vstup[len(vstup)-2]+vstup[len(vstup)-1] == "><" or vstup[len(vstup)-2]+vstup[len(vstup)-1] == ">>":
#     dvojice.append(1)
# else:
#     dvojice.append(0)

# print(2,dvojice)



# stvorice = []

# if (vstup[0]+vstup[3] == "<<" or vstup[0]+vstup[3] == "><") and dvojice[1]:
#     stvorice.append(1)
# else:
#     stvorice.append(0)


# for i in range(1,len(vstup)-4): 
#     pridaj = 1
#     for j in range(0,2):
#         if not dvojice[i+(j*2)]:
#             pridaj = 0
#     if pridaj:
#         stvorice.append(1)
#         continue

#     if (vstup[i]+vstup[i+3] == ">>" or vstup[i]+vstup[i+3] == "><" or vstup[i]+vstup[i+3] == "<<") and dvojice[i+1]:
#         stvorice.append(1)
#         continue
#     stvorice.append(0)

# if (vstup[len(vstup)-4]+vstup[len(vstup)-1] == "><" or vstup[len(vstup)-4]+vstup[len(vstup)-1] == ">>") and dvojice[len(vstup)-2]:
#     stvorice.append(1)
# else:
#     stvorice.append(0)
# print(4,stvorice)


# vstup = ">>><<<>>>>><<<>"

# sestice = []

# if (vstup[0]+vstup[5] == "<<" or vstup[0]+vstup[5] == "><") and stvorice[1]:
#     sestice.append(1)
# else:
#     sestice.append(0)


# for i in range(1,len(vstup)-6):
#     pridaj = 1
#     for j in range(0,3):
#         if not dvojice[i+(j*2)]:
#             pridaj = 0
#     if pridaj:
#         sestice.append(1)
#         continue


#     if (stvorice[i] and dvojice[i+4]) or stvorice[i+2] and dvojice[i]:
#         sestice.append(1)
#         continue
#     if (vstup[i]+vstup[i+5] == ">>" or vstup[i]+vstup[i+5] == "><" or vstup[i]+vstup[i+5] == "<<") and stvorice[i+1]:
#         sestice.append(1)
#         continue
#     sestice.append(0)

# if vstup[len(vstup)-6]+vstup[len(vstup)-1] == "><" or vstup[len(vstup)-6]+vstup[len(vstup)-1] == ">>":
#     sestice.append(1)
# else:
#     sestice.append(0)
# print(6,sestice)

# vstup = ">>><<<>>>>><<<>"

# osmice = []

# if (vstup[0]+vstup[7] == "<<" or vstup[0]+vstup[7] == "><") and sestice[1] or sestice[0] and dvojice[7] or sestice[2] and dvojice[0]:
#     osmice.append(1)
# else:
#     osmice.append(0)


# for i in range(1,len(stvorice)-5):
#     pridaj = 1
#     if j*3+i < len(dvojice):
#         for j in range(0,4):
#             if not dvojice[i+(j*2)]:
#                 pridaj = 0
#         if pridaj:
#             osmice.append(1)
#             continue
#     if i + 7 < len(dvojice):
#         if sestice[i] and dvojice[i + 7] or sestice[i + 2] and dvojice[i]:
#             osmice.append(1)
#             continue
#     if stvorice[i] and stvorice[i+4]:

#         osmice.append(1)
#         continue
#     osmice.append(0)


# if (vstup[len(vstup)-9]+vstup[len(vstup)-1] == "><" or vstup[len(vstup)-9]+vstup[len(vstup)-1] == ">>") and sestice[len(sestice)-2]:
#     osmice.append(1)
# else:
#     osmice.append(0)
# print(8,osmice)



# desatice = []

# if (vstup[0]+vstup[9] == "<<" or vstup[0]+vstup[9] == "><") and osmice[1] or sestice[0] and stvorice[7] or sestice[4] and stvorice[0]:
#     desatice.append(1)
# else:
#     desatice.append(0)


# for i in range(1,len(stvorice)-4):
#     pridaj = 1
#     if j*4+i < len(dvojice):
#         for j in range(0,5):
#             if not dvojice[i+(j*2)]:
#                 pridaj = 0
#                 break
#         if pridaj:
#             desatice.append(1)
#             continue
#     if i + 7 < len(stvorice):
#         if sestice[i] and stvorice[i + 7] or sestice[i + 4] and stvorice[i]:
#             desatice.append(1)
#             continue
#     if osmice[i] and dvojice[i+4]:

#         desatice.append(1)
#         continue
#     desatice.append(0)

# print(desatice)




