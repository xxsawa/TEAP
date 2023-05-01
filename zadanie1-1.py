
vstup = [1234 ,3 ,12 ,3 ,6 ,16 ,1000 ,200,4 ,20 ,30 ,15 ,19 ]
#vstup = [20, 4, 5, 10, 10, 10, 10, 10]
def nasa_f(vstup):
    nosnost = vstup[0]
    zemsti = vstup[1]



    vahy = vstup[3:]
    na_moste= []


    sucet = 0


    for i in vahy:
        if not na_moste:
            na_moste.append(i)
            sucet += i
        else:
            if i < na_moste[-1]:
                na_moste.append(i) 
                sucet += i
            elif i >= na_moste[0]:
                na_moste.insert(0,i)
                sucet += i 
            else:
                for idx,j in enumerate(na_moste):
                    if i > j:
                        na_moste.insert(idx ,i)
                        sucet += i 
                        break
                print(na_moste)
        if len(na_moste) > zemsti:
            sucet -= na_moste[-1]
            na_moste.pop()
            


    print(sucet)
    if sucet > nosnost:
        print("NIE")
    else:
        print("ANO")


nasa_f([1234, 3, 4, 1000, 200, 4 ,30 ])