# 기존 풀이
import re

def solution(record):

    enter = "님이 들어왔습니다."
    leave = "님이 나갔습니다."
    lines = []
    names = {}

    for rec in record :
        recs = rec.split() # move, user_id, name
        if recs[0] == "Enter" :
            lines.append(recs[1] + enter)
            names[recs[1]] = recs[2]

        elif recs[0] == "Leave" :
            lines.append(recs[1] + leave)
        else :
            names[recs[1]] = recs[2]

    for i in range(len(lines)) :
        user_id = re.match("[A-Za-z0-9]+", lines[i])[0]
        lines[i] = lines[i].replace(user_id, names[user_id])

    return lines
    
record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]

print(solution(record))


# 이후 풀이
def solution(record):
    lines = {"Enter" :  "님이 들어왔습니다.", "Leave" :"님이 나갔습니다."}
    names = {}
    
    for r in record :
        rs = r.split() # move, user_id, name
        if rs[0] in ["Enter","Change"] :
            names[rs[1]] = rs[2]
        
    ans = []
    for r in record :
        rs = r.split() # move, user_id, name
        if rs[0] != "Change" :
            ans.append(names[rs[1]] + lines[rs[0]])
    
    return ans