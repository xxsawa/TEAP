vstup = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

do = 100000

tabuulka = [None] * (do+1)


vyhra = False
remiza = False
temp = 0

kolko_v = 0

posledne_v = 0


for i in range(1,do+1):
    for j in vstup:
        if i - j == 0:
            tabuulka[i] = 'V'
            kolko_v += 1
            break
        elif i - j > 0:
            if tabuulka[i-j]:
                if tabuulka[i-j] == 'V':
                    tabuulka[i] = 'P'
                if tabuulka[i-j] == 'P':
                    tabuulka[i] = 'V'
                    kolko_v += 1
                    break
                if tabuulka[i-j] == 'R':
                    tabuulka[i] = 'R'
                
            else:
                break
        elif i - j < 0:
            break

print(tabuulka[1:])
print(kolko_v)

