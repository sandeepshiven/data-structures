def append(txt,add_txt):
    stack.append(txt)
    txt += add_txt
    return txt

def delete(txt,del_from):
    stack.append(txt)
    txt = txt[:len(txt)-del_from]
    return txt

def undo(txt):
    last = stack.pop()
    txt = last
    return txt

no_operations = int(input())
text = ''
stack = []
for _ in range(no_operations):
    operation = list(input().split())
    if operation[0] == '1':
        text = append(text,operation[1])
    elif operation[0] == '2':
        text = delete(text,int(operation[1]))
    elif operation[0] == '3':
        print(text[int(operation[1])-1])
    else:
        text = undo(text) 




