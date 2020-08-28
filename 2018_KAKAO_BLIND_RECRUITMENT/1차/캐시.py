HIT = 1
MISS = 5

def solution(cacheSize, cities):
    if cacheSize == 0:
        return MISS * len(cities)
    
    Cache = []
    for i in range(cacheSize):
        Cache.append([0, ""])
        
    num = 0; sum_time = 0
    for i in range(len(cities)):
        tmp = ""
        for j in range(len(cities[i])):
            tmp += cities[i][j].upper()
            
        exist = False
        min_index = 0; min_used = Cache[0][0]
        for j in range(len(Cache)):
            if Cache[j][0] < min_used:
                min_used = Cache[j][0]
                min_index = j
            if Cache[j][1] == tmp:
                num += 1
                Cache[j][0] = num
                sum_time += HIT
                exist = True
                break
                
        if not exist:
            num += 1
            Cache[min_index][0] = num
            Cache[min_index][1] = tmp
            sum_time += MISS
            
    return sum_time
