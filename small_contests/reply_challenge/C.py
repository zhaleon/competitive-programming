T = int(input())

for case in range(1,T+1):
    N, K = map(int, input().split())
    A = sorted(map(int, input().split()))
    B = sorted(map(int, input().split()))

    af = 0
    bf = 0
    ab = N-1
    bb = N-1
    small = 0
    big = 0

    print(A,B)
    for i in range(K):
        if A[af] * B[bb] > 0:
            bb = af + K-i
        if A[af] * B[bb] < B[bf] * A[ab]:
            small += A[af] * B[bb]
            af += 1
            bb -= 1
        else:
            small += B[bf] * A[ab]
            bf += 1
            ab -= 1

    af, bf, ab, bb = 0, 0, N-1, N-1

    for i in range(K):
        if A[af] * B[bf] > B[bb] * A[ab]:
            big += A[af] * B[bf]
            af += 1
            bf += 1 
        else:
            big += B[bb] * A[ab]
            bb -= 1
            ab -= 1

    print(f"Case #{case}: ", small, big)
