# 23%에서 틀림




import sys

S, E, Q = input().split()
Sh, Sm = map(int, S.split(':'))
Eh, Em = map(int, E.split(':'))
Qh, Qm = map(int, Q.split(':'))

cnt = 0
check = {}
for line in sys.stdin:
    time, name = line.split()

    h, m = map(int, time.split(':'))
    if (h == Sh and m <= Sm) or (h < Sh):
        if name in check:
            check[name] = 1
    else:
        finish_chong = (h == Eh and m >= Em) or (h > Eh)
        finish_streaming = (h == Qh and m <= Qm) or (h < Qh)
        if finish_chong and finish_streaming:
            if name in check:
                cnt += 1
                check.pop(name)

print(cnt)
