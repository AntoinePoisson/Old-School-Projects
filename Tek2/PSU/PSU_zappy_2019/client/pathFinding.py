def findBestPath(pos, pos2, totalLength):
    dist = abs(pos2 - pos)
    if dist > (totalLength / 2):
        return -1
    return 1

def getLength(pos, pos2, totalLength):
    res = findBestPath(pos, pos2, totalLength)
    if res == -1:
        return -1 * (pos + (totalLength - pos2))
    else:
        return pos2 - pos

def getCoordinatesDisplacement(pos, dest, dim):
    x = getLength(pos["x"], dest["x"], dim["x"])
    y = getLength(pos["y"], dest["y"], dim["y"])
    return x, y

def getPath(pos, dest, dim):
    x, y = getCoordinatesDisplacement(pos, dest, dim)
    path = {}
    if x < 0:
        path["Left"] = x * -1
    elif x > 0:
        path["Right"] = x
    if y < 0:
        path["Down"] = y * -1
    elif y > 0:
        path["Up"] = y
    return path
