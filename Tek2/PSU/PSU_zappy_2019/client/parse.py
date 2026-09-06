# food
# linemate
# deraumere
# sibur
# mendiane
# phiras
# thystame

def getLen(level):
    size = 1
    line = 1
    for i in range(0, level):
        line += 2
        size += line
    return size

def parseTile(str):
    array = str.split(" ")
    obj = {
        "food": 0,
        "linemate": 0,
        "deraumere": 0,
        "sibur": 0,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0,
        "player": 0
    }
    for i in array:
        if i in obj:
            obj[i] += 1
    return obj

def parseLook(str, soughtObject, level):
    str = str.replace('[', '')
    str = str.replace(']', '')

    obj = []
    tab = str.split(',')
    # print(tab)
    for i in range(len(tab)):
        obj.append(parseTile(tab[i]))
        obj[-1]["idx"] = i
    # print(obj)
    nbObj = 0
    pos = 0
    arrPos = []
    for i in range(len(tab)):
        if soughtObject in obj[i] and "idx" in obj[i] and obj[i][soughtObject] > nbObj:
            arrPos = []
            arrPos.append(obj[i]["idx"])
            pos = obj[i]["idx"]
            nbObj = obj[i][soughtObject]
        elif soughtObject in obj[i] and "idx" in obj[i] and obj[i][soughtObject] == nbObj and nbObj != 0:
            arrPos.append(obj[i]["idx"])

    if pos == 0:
        if soughtObject in obj[0] and obj[0][soughtObject] > 0:
            return obj[0], []
        else:
            return None, None
    listPath = []
    for i in arrPos:
        listPath.append(getPath(level, i, obj, soughtObject))
    path = []
    path.extend(["Up" for i in range(100)])
    for i in range(len(listPath)):
        if len(path) > len(listPath[i]):
            path = listPath[i]
            pos = arrPos[i]
    # path = getPath(level, pos, obj, soughtObject)
    return obj[pos], path

def getPath(level, pos, obj, soughtObject):
    path = []
    size = 1
    line = 1
    idx = 0
    for i in range(0, level):
        line += 2
        if pos < size + line:
            idx = i
            break
        size += line
    path.extend(["Up" for i in range(idx + 1)])
    middle = line // 2
    if pos < size + middle:
        path.append("Left")
        while pos < size + middle:
            if soughtObject in obj[size + middle] and obj[size + middle][soughtObject] > 0:
                for i in range(0, obj[size + middle][soughtObject]):
                    path.append("takeObject")
            path.append("Up")
            middle -= 1
    if pos > size + middle:
        path.append("Right")
        while pos > size + middle:
            if soughtObject in obj[size + middle] and obj[size + middle][soughtObject] > 0:
                for i in range(0, obj[size + middle][soughtObject]):
                    path.append("takeObject")
            path.append("Up")
            middle += 1
    return path

# string = "[player,,food,thystame,,food,,,,,thystame,,,,,,]"
# string = "[' player phiras', ' food food food food food food food food food food food phiras', '', ' food food food food food food food food food food linemate sibur ']"
# string = "[' player phiras', ' phiras', '', ' linemate sibur ', ' phiras', '', ' linemate sibur ', ' food phiras', ' food food food food food food ', ' linemate sibur ', ' phiras', '', ' linemate sibur ', ' phiras', '', ' linemate sibur ']"
# string = "[' player phiras', ' food food phiras', ' food food ', ' linemate sibur ']"
# string = "[' player phiras', ' phiras', '', ' linemate sibur ']"
# value, path = parseLook(string, "food", 3)
# print(path)
# print(value)
# print(getPath(3, 11))

# print(value)

# path = ["coco", "vanille","frise", "straberry like", "clementine"]

# print(path[0:len(path) - 2])
# print(path)
