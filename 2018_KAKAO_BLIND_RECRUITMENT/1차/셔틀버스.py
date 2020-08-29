def strToMin(s):
    hour = int(s[:2])
    min = int(s[3:])
    min += hour * 60

    return min

def minToStar(n):
    hour = n // 60
    min = n % 60

    result = ""
    if hour < 10: result += "0"
    result += str(hour)
    result += ":"
    if min < 10: result += "0"
    result += str(min)

    return result

def solution(n, t, m, timetable):
    timetable_min = []
    for time in timetable:
        if time == "24:00": continue
        timetable_min.append(strToMin(time))
    timetable_min.sort()
    
    bus_timetable = []
    bus_timetable.append(540)
    for i in range(n-1):
        bus_timetable.append(bus_timetable[-1] + t)
        
    crew_index = 0
    for i in range(len(bus_timetable)-1):
        tmp_time = bus_timetable[i]
        crew_in_bus = 0
        while 1:
            if crew_index >= len(timetable_min): break
            if timetable_min[crew_index] > tmp_time: break
            
            crew_in_bus += 1
            crew_index += 1
            
            if crew_in_bus >= m: break
            
    last_time = bus_timetable[-1]
    crew_in_last_bus = 0
    while crew_index < len(timetable_min) and timetable_min[crew_index] <= last_time:
        crew_in_last_bus += 1
        crew_index += 1
        
    if crew_in_last_bus < m: return minToStar(last_time)
    else:
        con_index = crew_index - (crew_in_last_bus - m + 1)
        con_time = timetable_min[con_index] - 1
        return minToStar(con_time)
