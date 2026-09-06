##
## EPITECH PROJECT, 2020
## CNA_trade_2019
## File description:
## tool
##

from src.classe import *

def handleConvertionUpdateDate(data):
    index, el = data
    if index:
        return float(el)
    else:
        return str(el)

def parseData(trade, el, parser):
    tmp = []
    if (len(el.split(parser)) > 3):
        tmp = ["",0,0,0,0,0,0]
        index = 0
        while (index < 7):
            if (trade.Settings.candle_format[index] == "pair"):
                tmp[0] = str(el.split(parser)[index])
            if (trade.Settings.candle_format[index] == "date"):
                tmp[1] = float(el.split(parser)[index])
            if (trade.Settings.candle_format[index] == "high"):
                tmp[2] = float(el.split(parser)[index])
            if (trade.Settings.candle_format[index] == "low"):
                tmp[3] = float(el.split(parser)[index])
            if (trade.Settings.candle_format[index] == "open"):
                tmp[4] = float(el.split(parser)[index])
            if (trade.Settings.candle_format[index] == "close"):
                tmp[5] = float(el.split(parser)[index])
            if (trade.Settings.candle_format[index] == "volume"):
                tmp[6] = float(el.split(parser)[index])
            index += 1
    else:
        tmp = list(map(handleConvertionUpdateDate, list(enumerate(el.split(parser)))))
    return tmp

def convertMoney(nbr, valeur):
    if valeur == 0:
        return nbr
    return (nbr / valeur)

def MeansTwoTab(x, y):
    res = 0
    size = len(x) - 1
    if size == -1:
        return res
    while (size >= 0):
        res += x[size] * y[size]
        size -= 1
    return (res / len(x))

def MeansOneTab(x):
    res = 0
    size = len(x) - 1    
    if size == -1:
        return res
    while (size >= 0):
        res += x[size]
        size -= 1
    return (res / len(x))

def MeansOneTabPowerTwo(x):
    res = 0
    size = len(x) - 1    
    if size == -1:
        return res
    while (size >= 0):
        res += pow(x[size], 2)
        size -= 1
    return (res / len(x))

def percentOfMoney(nbr, possede, value):
    result = ((possede * nbr) / 100)
    if (nbr < 0):
        return ((-result) / value)
    return (result / value)

def calibrationDecision(decision, trade, isBTC):
    device = (trade.eth, trade.btc)[isBTC]    
    if (decision == 0):
        return (0)
    if (decision > 0):
        costBuy = (trade.usdt * decision / 100)
        fee = (trade.usdt * trade.Settings.transactionFeePercent / 100)
        # trade.displayStderr("????" + str(costBuy) + " | " + str(decision) + " $$ " + str(trade.usdt))
        if (float(format((trade.usdt - costBuy), '.6f')) < 0) or (costBuy < fee):
            # trade.displayStderr("++++++++++++++++++++++++++++++++++\n")
            return (0)
    if (decision < 0):
        costSell = (device * (-decision) / 100)
        fee = (device * trade.Settings.transactionFeePercent / 100)
        if (float(format((device - costSell), '.6f')) < 0)  or (costSell < fee):
            trade.displayStderr("Meeeeeeeeeeeeeeeeeeerrrrrdeeee  " + str(device - costSell) + " = " + str(device)  + " -"  +str(costSell))
            return (0)
    return (decision)

def takeChoseBTC(decisionBTC, trade):
################## Debug
    if decisionBTC != 0:
        trade.displayStderr("decisionBTC: " + str(decisionBTC))    
##################
    if (decisionBTC > 0):
        buy = percentOfMoney(decisionBTC, trade.usdt, trade.Data.stock[0][2][5])
        # trade.displayStderr(" ++++ " + str(float(format(buy, '.6f'))))        
        if float(format(buy, '.6f')) >= 0.00001:
            trade.lastActionBTC = "buy"
            return ("buy USDT_BTC " + str(buy))
    elif (decisionBTC < 0):
        sell = percentOfMoney(decisionBTC, trade.btc, 1)
        # trade.displayStderr(" ----- " + str(float(format(sell, '.6f'))))
        if float(format(sell, '.6f')) >= 0.00001:
            trade.lastActionBTC = "sell"
            return ("sell USDT_BTC " + str(sell))
    trade.lastActionBTC = "pass"
    return ("pass")
    
def takeChoseETH(decisionETH, trade):
    ################## Debug
    if decisionETH != 0:
        trade.displayStderr("decisionETH: " + str(decisionETH))    
##################
    if (decisionETH > 0):
        buy = percentOfMoney(decisionETH, trade.usdt, trade.Data.stock[0][1][5])
        # trade.displayStderr(" ++++ " + str(float(format(buy, '.6f'))))        
        if float(format(buy, '.6f')) >= 0.00001:
            trade.lastActionETH = "buy"
            return ("buy USDT_ETH " + str(buy))
    elif (decisionETH < 0):
        sell = percentOfMoney(decisionETH, trade.eth, 1)
        # trade.displayStderr(" ----- " + str(float(format(sell, '.6f'))))
        if float(format(sell, '.6f')) >= 0.00001:
            trade.lastActionETH = "sell"
            return ("sell USDT_ETH " + str(sell))
    trade.lastActionETH = "pass"
    return ("pass")

def checkCanMultiOperation(trade, decisionETH, decisionBTC):
    costETH = 0;
    costBTC = 0;
    feeETH = 0;
    feeBTC = 0;
    if (decisionETH == 0 or decisionBTC == 0):
        return (0)
    if (decisionETH > 0):
        costETH = (trade.usdt * decisionETH / 100)
        feeETH = (trade.usdt * trade.Settings.transactionFeePercent / 100)
        if (float(format((trade.usdt - costETH), '.6f')) < 0) or (costETH < feeETH):
            return (0)
    if (decisionETH < 0):
        costETH = (trade.eth * (-decisionETH) / 100)
        feeETH = (trade.eth * trade.Settings.transactionFeePercent / 100)
        if (float(format((trade.eth - costETH), '.6f')) < 0)  or (costETH < feeETH):
            return (0)
    if (decisionBTC > 0):
        costBTC = (trade.usdt * decisionBTC / 100)
        feeBTC = (trade.usdt * trade.Settings.transactionFeePercent / 100)
        if (float(format((trade.usdt - costBTC), '.6f')) < 0) or (costBTC < feeBTC):
            return (0)
    if (decisionBTC < 0):
        costBTC = (trade.btc * (-decisionBTC) / 100)
        feeBTC = (trade.btc * trade.Settings.transactionFeePercent / 100)
        if (float(format((trade.btc - costBTC), '.6f')) < 0)  or (costBTC < feeBTC):
            return (0)
    if (float(format((trade.usdt - costBTC - costETH - feeBTC - feeETH), '.6f')) < 0):
        return (0);
    return (1)