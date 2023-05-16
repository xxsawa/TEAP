class TreeNode:
    def __init__(self, done):
        self.done = done
        self.one = None
        self.zer = None

    def add_one(self, done):
        self.one = TreeNode(done)

    def add_zer(self, done):
        self.zer = TreeNode(done)

root = TreeNode(True)


mocniny_5 = []
cislo1 = "1"
cislo2 = 1


while True:
    actual_node = root
    i = 0
    mocniny_5.append(cislo1)
    cislo1 = bin(pow(5,cislo2))[2:]
    if len(cislo1) > 50:
        break
    print((cislo1[::-1])[1:])
    while i < len(cislo1) - 1:
        next_num = cislo1[len(cislo1)-i-2]


        if next_num == "0":
            if not actual_node.zer: 
                if len(cislo1)-2-i == 0:
                    actual_node.add_zer(True)
                else:
                    actual_node.add_zer(False)
            actual_node = actual_node.zer



        else:
            if not actual_node.one: 
                if len(cislo1)-2-i == 0:
                    print(i)
                    actual_node.add_one(True)
                else:
                    actual_node.add_one(False)
            actual_node = actual_node.one
            
        i+=1
            
    cislo2 += 1



najlepsie = 10000

def rekurzia_na_strome(slovo,i,actual_node,pocet_iter,nas_string):
    global najlepsie
    if slovo[i] == "0":
        return 
    
    if i == len(slovo)-1:
        if pocet_iter < najlepsie:
            najlepsie = pocet_iter+1
    
    j = i
    while j < len(slovo)-1:
        if slovo[j+1] == '0':
            if actual_node.zer:
                actual_node = actual_node.zer
                nas_string += "0"
            else:
                break 
        else:
            if actual_node.one:
                actual_node = actual_node.one
                nas_string += "1"
                if actual_node.done:
                    if j+2 == len(slovo):
                        if pocet_iter < najlepsie:
                            najlepsie = pocet_iter+1
                            break
                    rekurzia_na_strome(slovo,j+2,root,pocet_iter+1,nas_string)
            else:
                if actual_node.done:
                    rekurzia_na_strome(slovo,j+1,root,pocet_iter+1,nas_string)
                break

        j+=1
    
        
rekurzia_na_strome(str(1010101)[::-1],0,root,0,"1")


if najlepsie == 10000:
    print(-1)
else:
    print(najlepsie)


