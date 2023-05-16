


def rekurzia(nejaky_arr):
    if len(nejaky_arr) == 3:
        print(nejaky_arr)
    else:
        for i in range(6):
            nejaky_arr.append(i+1)
            rekurzia(nejaky_arr)
            nejaky_arr.pop()




rekurzia([])