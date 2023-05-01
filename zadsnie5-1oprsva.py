from math import ceil


print(0%2)

vstup = [1,2,3]
goals = 2


umin = [vstup[0],0]
umax = [0,0]

for i in range(len(vstup)):
    if vstup[i] > umax[0]:
        umax[0] = vstup[i]
        umax[1] = i
        if abs(umax[0] - umin[0]) >= goals:
            print("tu")
            print(ceil(min(umin[1],umax[1])/2) + ceil(abs(umax[1] - umin[1])/2) + 1)
            break

    if vstup[i] < umin[0]:
        umin[0] = vstup[i]
        umin[1] = i
        if abs(umax[0] - umin[0]) >= goals:
            print(ceil(min(umin[1],umax[1])/2) + ceil(abs(umax[1] - umin[1])/2) + 1)
            break



#12ty od zadu ma byt 3