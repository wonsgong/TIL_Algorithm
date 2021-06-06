import sys

read = sys.stdin.readline
MAXN = 4000000

def eratos() :
    isPrime = [False for _ in range(MAXN+1)]
    prime = []
    for i in range(2,2001) :
        if not isPrime[i] :
            prime.append(i)
            for j in range(i*i,MAXN+1,i) :
                isPrime[j] = True

    for i in range(2001,MAXN+1) :
        if not isPrime[i] :
            prime.append(i)
    
    return prime

N = int(read())
prime = eratos()

st = 0
ed = 0
cnt = 0
sum_ = 0

while ed < len(prime) :
    if sum_ < N :
        sum_ += prime[ed]
        ed += 1
    elif sum_ > N :
        sum_ -= prime[st]
        st += 1
    else :
        sum_ -= prime[st]
        st += 1
        cnt += 1
    
print(cnt)
