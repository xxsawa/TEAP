#vstup = [ 120 ,140, 150, 200 ,201, 250 ,150 ,150 ,101, 110,160 ,175,130 ,185, 190, 300]
vstup = [ 120 ,140, 150, 200 ,201, 250 ,150 ,150 ,160 ,175,130 ,185, 190, 300]


# 14 120 140 150 200 201 250 150 150 160 175 130 185 190 300

vstup.sort()
vstup.reverse()

print(vstup)

pocet_kamionov = 0
od_ktoreho = 0
od_zadu = 0

for idx,i in enumerate(vstup):
    if i >= 200:
        od_ktoreho += 1
    else:
        if idx >= len(vstup)-od_zadu-1:
            break
                
        print(len(vstup)-od_zadu-1)
        pocet_kamionov += 1

        if i + vstup[len(vstup)-od_zadu-1] > 300:
            continue
        
        
        print(vstup[len(vstup)-od_zadu-1] + i,idx,len(vstup)-od_zadu-1)
        od_zadu +=1



pocet_kamionov += od_ktoreho


print(pocet_kamionov)