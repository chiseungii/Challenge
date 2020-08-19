POSSIBLE = 0
EXCEPT_THIS = 1
EXCEPT_BEFORE = 2
IMPOSSIBLE = 3

N = int(input())

cups = []
for i in range(N):
    x, p = map(int, input().split())
    cups.append([x, p])

sum_price = 0
result = POSSIBLE
for i in range(N):
    if sum_price > cups[i][0]:
        result = EXCEPT_THIS
        except_index = i
        break
    else: sum_price += cups[i][1]

if result == EXCEPT_THIS:
    sum_price = 0; result = POSSIBLE
    for i in range(N):
        if i == except_index: continue
        elif sum_price > cups[i][0]:
            result = EXCEPT_BEFORE
            break
        else: sum_price += cups[i][1]

if result == EXCEPT_BEFORE:
    max_p = -1; max_index = -1
    for i in range(except_index):
        if cups[i][1] > max_p:
            max_p = cups[i][1]
            max_index = i

    sum_price = 0; result = POSSIBLE
    for i in range(N):
        if i == max_index: continue
        elif sum_price > cups[i][0]:
            result = IMPOSSIBLE
            break
        else: sum_price += cups[i][1]

if result == POSSIBLE: print("Kkeo-eok")
else: print("Zzz")
