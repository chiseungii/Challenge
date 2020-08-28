def solution(dartResult):
    score = 0
    before = 0
    
    index = 0
    for i in range(3):
        if dartResult[index + 1] == '0':
            tmp_score = 10
            index += 2
        else:
            tmp_score = int(dartResult[index])
            index += 1
            
        bonus = dartResult[index]; index += 1
        if bonus == 'D': tmp_score *= tmp_score
        elif bonus == 'T': tmp_score **= 3
        
        if index >= len(dartResult): pass
        elif dartResult[index] == '*':
            score += before
            tmp_score *= 2
            index += 1
        elif dartResult[index] == '#':
            tmp_score = -tmp_score
            index += 1
            
        score += tmp_score
        before = tmp_score
        
    return score
