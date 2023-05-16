vstup = "9230560001"
vysledok = 71

da_sa = False

najlepsie = []


def rekurzia(pocet_plus,j,our_sum,array):
    global da_sa
    for i in range(j,len(vstup)):
        if int(vstup[j:i+1]) == 0:
            j += 1
            continue

            
        elif int(vstup[j:i+1]) < vysledok:
            if our_sum + int(vstup[j:i+1]) == vysledok and i+1 == len(vstup)+1:
                da_sa = True
                najlepsie.append(pocet_plus)
                
                break

            if our_sum + int(vstup[j:i+1]) < vysledok:
                array.append(vstup[j:i+1])
                rekurzia(pocet_plus+1,i+1,our_sum+int(vstup[j:i+1]),array)
                array.pop()

        elif our_sum + int(vstup[j:i+1]) > vysledok:
            break 
        


rekurzia(0,0,0,[])

najlepsie.sort()

if not da_sa:
    print("IMPOSSIBLE")
else:
    print(najlepsie[0])