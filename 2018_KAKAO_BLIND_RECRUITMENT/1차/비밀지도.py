two = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768]

def intToMap(a, n):
    # base = n - 1
    result = ""
    for base in range(n-1, -1, -1):
        if two[base] <= a:
            a -= two[base]
            result += "#"
        else: result += " "

    return result

def solution(n, arr1, arr2):
    result = []
    for i in range(n):
        s1 = intToMap(arr1[i], n)
        s2 = intToMap(arr2[i], n)
        
        tmp = ""
        for j in range(n):
            if s1[j] == '#' or s2[j] == '#':
                tmp += '#'
            else: tmp += ' '
            
        result.append(tmp)
        
    return result
