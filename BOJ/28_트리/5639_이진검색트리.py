import sys
sys.setrecursionlimit(int(1e9))
read = sys.stdin.readline

def postorder(st,ed) :
    if st > ed : return

    div = ed + 1
    for i in range(st+1,ed+1) :
        if node[st] < node[i] :
            div = i
            break
    
    postorder(st+1, div-1)
    postorder(div, ed)

    print(node[st])

node = []
while 1 :
    try :
        node.append(int(read()))
    except :
        break

postorder(0,len(node)-1)