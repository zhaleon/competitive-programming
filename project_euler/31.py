coins = [1, 2, 5, 10, 20, 50, 100, 200]

ways = [0 for _ in range(201)]
ways[0] = 1

for coin in coins:
    for i in range(200, 0, -1):
        for num_coins in range(1 , 200 // coin + 1):
            if i < coin * num_coins:
                break
            ways[i] += ways[i - num_coins * coin]
    
print(ways[200])
    