def is_triangle(Sa,Sb,Sc):
    if ((Sa + Sb > Sc) or (Sb + Sa >Sc)) and ((Sa + Sc > Sb) or (Sc + Sa >Sb)) and ((Sc + Sb > Sa) or (Sb + Sc >Sa)):
        return True
    else:
        return False

def count_triangle(A):
    count = 0
    for i in range(len(A)-2):
        for j in range(i+1,len(A)-1):
            for k in range(j+1,len(A)):
                if is_triangle(A[i],A[j],A[k]):
                    count += 1
    return count

T = int(input())
Output = []

for i in range(T):
    n = int(input())

    Si_list = []
    for j in range(n):
        Si = str(input())
        Si_list.append(Si)
    # Si_list.sort()
    # print(count_triangle(Si_list))
    Output.append(count_triangle(Si_list))

for j in Output:
    print(j)
