"heart"
A="     "
B="****"
N=10
F=5
for i in range(4):
    print(A[:F],B,B)
    F=F-1
    B=B+"*"
B=B+"******"
F=4
for i in range(6):
    print(A,B[:N])
    N=N-2
    A=A+" "

B="*"
N=1
G=True
for i in range(5):
    for j in range(5):
        if G:
            print(B,end="")
            G=False
        else:
            print(N,end="")
            G=True
            N=N+1
    print("\n")
