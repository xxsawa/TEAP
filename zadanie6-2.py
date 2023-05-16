hamburger = [[1, 5, 3, 20, 3, 6, 20, 4, 50, 6],
[6, 4, 9, 20, 5, 4, 5, 6, 7, 8],
[6, 20, 4, 50, 6, 6, 20, 4, 50, 6],
[1, 3, 4, 5, 6, 6, 4, 9, 20, 5],
[4, 5, 6, 7, 8, 6, 4, 9, 20, 5],
[10, 50, 3, 20, 3, 6, 20, 4, 50, 6],
[6, 40, 9, 20, 5, 4, 5, 6, 7, 8],
[6, 20, 4, 50, 6, 6, 20, 4, 50, 6],
[10, 3, 4, 5, 6, 6, 4, 9, 20, 5],
[4, 5, 6, 7, 8, 6, 4, 9, 20, 5]]

vysledne_pole = []
vysledny_sum = 10000

def rekurzia(kde,pole,sucet):
    global vysledne_pole,vysledny_sum
    if len(pole) == 10:
        if sucet < vysledny_sum:
            vysledne_pole = pole.copy()
            vysledny_sum = sucet
    for i in range(len(hamburger[kde])):
        if i+1 not in pole:
            pole.append(i+1)
            rekurzia(i,pole,sucet + hamburger[kde][i])
            pole.pop()


rekurzia(0,[1],0)

print(vysledne_pole,vysledny_sum)