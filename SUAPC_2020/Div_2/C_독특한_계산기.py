# 해결 안 됨

from collections import deque

def cal_result(a, b, op):
    if op == '+': return a + b
    elif op == '-': return a - b
    elif op == '*': return a * b
    else: return a // b

cal = input()

nums = deque()
ops = deque()

index = 0
for i in range(1, len(cal)):
    if not cal[i].isdigit():
        a = int(cal[index:i])
        nums.append(a)
        ops.append(cal[i])
        index = i + 1
a = int(cal[index:])
nums.append(a)

while len(ops) > 1:
    front_first = True

    front_a = nums.popleft()
    front_b = nums[0]
    back_b = nums.pop()
    back_a = nums[-1]
    front_op = ops[0]
    back_op = ops[-1]

    front_result = cal_result(front_a, front_b, front_op)
    back_result = cal_result(back_a, back_b, back_op)

    if (back_op == '*' or back_op == '/') and (front_op == '+' or front_op == '-'):
        front_first = False
    elif (front_op == '*' or front_op == '/') and (back_op == '+' or back_op == '-'):
        pass
    else:
        if back_result > front_result:
            front_first = False

    if front_first:
        nums.append(back_b)
        nums.popleft()
        nums.appendleft(front_result)
        ops.popleft()
    else:
        nums.appendleft(front_a)
        nums.pop()
        nums.append(back_result)
        ops.pop()

if len(ops) == 1:
    result = cal_result(nums[0], nums[-1], ops[0])
else: result = nums[0]

print(result)
