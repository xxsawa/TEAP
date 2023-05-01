vstup = [['Y','Y','Y','Y'],
         ['Y','Y','Y','Y'],
         ['Y','Y','Y','Y'],]


sucet = 0

def ideme_poitat(cisla,level,kde):
    global sucet
    if level == 3:
        print(cisla)
        sucet += 1
        return
    for i in range(len(vstup[0])):
        if i not in cisla and vstup[kde[level]-1][i] == 'Y':
            cisla.append(i)
            ideme_poitat(cisla,level+1,kde)
            cisla.pop()



def rekurzia(nejaky_arr):
    if len(nejaky_arr) == 4:
        ideme_poitat([],0,nejaky_arr[1:])
    else:
        for i in range(nejaky_arr[-1],len(vstup)):
                if i+1 not in nejaky_arr:
                    nejaky_arr.append(i+1)
                    rekurzia(nejaky_arr)
                    nejaky_arr.pop()




rekurzia([0])



print(sucet)

