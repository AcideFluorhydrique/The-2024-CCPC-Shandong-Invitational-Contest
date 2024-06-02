import math

def gold_coin(a,b,c,d,p,q,m,t):


    while t >= a + b + c + d:
        purchase = math.floor(min(m/p,(t - b - d)/(a + c)))
        if purchase == 0:
            break

        t = t - a* purchase - c* purchase - b - d
        m = m -p*purchase + q*purchase
        # print("t =",t,"m =",m)

    return m

T = int(input())
Output = []

for i in range(T):
    p, a, b = input().split()
    p, a, b = int(p), int(a), int(b)
    q, c, d = input().split()
    q, c, d = int(q), int(c), int(d)
    m, t = input().split()
    m, t = int(m), int(t)
    
    y = gold_coin(a,b,c,d,p,q,m,t)
    Output.append(y)

for j in Output:
    print(j)