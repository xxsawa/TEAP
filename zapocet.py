


def hroch(k,n):
    if k == 1:
        return (n+1)/2
    if n == 1:
        return 0
    return 1 + hroch(k, hroch(k-1,n))
print(hroch(3,100))
