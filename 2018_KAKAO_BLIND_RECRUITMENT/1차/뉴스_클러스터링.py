cnt_1 = []; cnt_2 = []
for i in range(26):
    tmp = []
    for j in range(26):
        tmp.append(0)

    cnt_1.append(tmp)
    tmp_2 = tmp.copy()
    cnt_2.append(tmp_2)

def solution(str1, str2):
    empty_1 = True
    for i in range(len(str1)-1):
        a = str1[i].lower()
        b = str1[i+1].lower()

        if not a.isalpha() or not b.isalpha():
            continue
        else:
            cnt_1[ord(a) - ord('a')][ord(b) - ord('a')] += 1
            empty_1 = False

    empty_2 = True
    for i in range(len(str2) - 1):
        a = str2[i].lower()
        b = str2[i + 1].lower()

        if not a.isalpha() or not b.isalpha():
            continue
        else:
            cnt_2[ord(a) - ord('a')][ord(b) - ord('a')] += 1
            empty_2 = False

    if empty_1 and empty_2: return 65536

    cnt_inter = 0; cnt_union = 0
    for i in range(26):
        for j in range(26):
            cnt_union += max(cnt_1[i][j], cnt_2[i][j])
            if cnt_1[i][j] and cnt_2[i][j]:
                cnt_inter += min(cnt_1[i][j], cnt_2[i][j])

    cnt_inter *= 65536
    return cnt_inter // cnt_union
