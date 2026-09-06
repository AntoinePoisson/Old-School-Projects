##
## EPITECH PROJECT, 2020
## CNA_trade_2019
## File description:
## main
##

import sys

from src.tool import *
from src.calcul import callGlobalCalcul

def settings(trade, line):
    if (len(line) != 3):
        trade.displayStderr("Error Invalid Settings: '" + ' '.join(map(str, line)).replace('\n', '') + "'")
        return ""
    if (line[1] == "candle_interval"):
        trade.Settings.candleInterval = int(line[2])
    if (line[1] == "candles_total"):
        trade.Settings.candlesTotal = int(line[2])
    if (line[1] == "candles_given"):
        trade.Settings.candlesGiven = int(line[2])
    if (line[1] == "candle_format"):
        trade.Settings.candle_format = line[2].replace('\n', '').split(',')
    if (line[1] == "initial_stack"):
        trade.Settings.initialStack = int(line[2])
        trade.usdt = int(line[2])
    if (line[1] == "transaction_fee_percent"):
        trade.Settings.transactionFeePercent = float(line[2])

def update(trade, line):
    if (len(line) != 4 or line[1] != "game"):
        trade.displayStderr("Error Invalid Parameter Update: '" + ' '.join(map(str, line)).replace('\n', '') + "'")
        return ""
    parserL = ';'
    parseE = ','
    if line[2] != "next_candles":
        parserL = ','
        parseE = ':'
    tmp = line[3].split(parserL)
    if (len(tmp) != 3):
        trade.displayStderr("Error Invalid Parameter Update: '" + ' '.join(map(str, line)).replace('\n', '') + "'")
        return ""
    if line[2] == "stacks":
        trade.Data.stack.insert(0, [parseData(trade, tmp[0], parseE), parseData(trade, tmp[1], parseE), parseData(trade, tmp[2], parseE)])
        trade.btc = trade.Data.stack[0][0][1]
        trade.eth = trade.Data.stack[0][1][1]
        trade.usdt = trade.Data.stack[0][2][1]
    elif line[2] == "next_candles":
        trade.Data.stock.insert(0, [parseData(trade, tmp[0], parseE), parseData(trade, tmp[1], parseE), parseData(trade, tmp[2], parseE)])

def action(trade, line):

    # Si BTC = SELL & ETC = BUY Faire la conversion de l'un en l'autre
    # Si BTC = BUY & ETC = SELL Faire la conversion de l'un en l'autre

    decisionBTC = callGlobalCalcul(trade, True)
    decisionETH = callGlobalCalcul(trade, False)

    decisionBTC = calibrationDecision(decisionBTC, trade, True)
    decisionETH = calibrationDecision(decisionETH, trade, False)

    BTC = takeChoseBTC(decisionBTC, trade);
    ETH = takeChoseETH(decisionETH, trade);

    trade.Action.first = False

    if (BTC[0] == 'p' and ETH[0] == 'p'):
        trade.displayStderr("pass")
        trade.displayStdout("pass")
        return ""

    if (BTC[0] == 'p' and ETH[0] != 'p'):
        trade.displayStderr(ETH)
        trade.displayStdout(ETH)
        return ""

    if (BTC[0] != 'p' and ETH[0] == 'p'):
        trade.displayStderr(BTC)
        trade.displayStdout(BTC)
        return ""

    if (BTC[0] == 'b' and ETH[0] == 'b'):
        trade.displayStderr(BTC)
        trade.displayStderr(ETH)
        if (checkCanMultiOperation(trade, decisionETH, decisionBTC) == 1):
            trade.displayStdout(BTC + " ; " + ETH)
        elif (abs(decisionBTC) < abs(decisionETH)):
            trade.displayStdout(BTC)
        else:
            trade.displayStdout(ETH)
        return ""

    if (BTC[0] == 's' and ETH[0] == 's'):
        trade.displayStderr(BTC)
        trade.displayStderr(ETH)
        if (checkCanMultiOperation(trade, decisionETH, decisionBTC) == 1):
            trade.displayStdout(BTC + " ; " + ETH);
        elif (abs(decisionBTC) < abs(decisionETH)):
            trade.displayStdout(BTC)
        else:
            trade.displayStdout(ETH)
        return ""


    means = abs(((decisionBTC) + (decisionETH)) / 2)

    if (BTC[0] == 'b' and ETH[0] == 's' and calibrationDecision(-means, trade, False) != 0):
        buy = percentOfMoney(means, trade.eth, trade.Data.stock[0][1][5])
        if float(format(buy, '.6f')) >= 0.00001 and float(format((trade.eth - buy), '.6f')) >= 0.00001:
            trade.lastActionBTC = "sell"
            trade.lastActionETH = "buy"
            trade.displayStderr("sell BTC_ETH " + str(buy))
            trade.displayStdout("sell BTC_ETH " + str(buy))
            return ""
        if (checkCanMultiOperation(trade, decisionETH, decisionBTC) == 1):
            trade.displayStdout(BTC + " ; " + ETH);
        elif (abs(decisionBTC) < abs(decisionETH)):
            trade.displayStdout(BTC)
        else:
            trade.displayStdout(ETH)
        return ""

    if (BTC[0] == 's' and ETH[0] == 'b' and calibrationDecision(-means, trade, True) != 0):
        sell = percentOfMoney(-means, trade.btc, trade.Data.stock[0][2][5])
        if float(format(sell, '.6f')) >= 0.00001 and float(format((trade.btc - sell), '.6f')) >= 0.00001:
            trade.lastActionBTC = "buy"
            trade.lastActionETH = "sell"
            trade.displayStderr("buy BTC_ETH " + str(sell))
            trade.displayStdout("buy BTC_ETH " + str(sell))
            return ""
        if (checkCanMultiOperation(trade, decisionETH, decisionBTC) == 1):
            trade.displayStdout(BTC + " ; " + ETH);
        elif (abs(decisionBTC) < abs(decisionETH)):
            trade.displayStdout(BTC)
        else:
            trade.displayStdout(ETH)
        return ""

    trade.displayStdout("pass")
        ## ETH (a rajouté)
    # decisionETH = callGlobalCalcul(trade, False)
    # if (decisionETH > 0):
    #     print("buy USDT_ETH " + )
    #     lastActionETH = "buy"
    # elif (decisionETH < 0):
    #     print("sell USDT_ETH " + )
    #     lastActionETH = "sell"
    # else:
    #     lastActionETH = "pass"

###############################################
        # Algo de Basique:
    # if trade.Action.first:
    #     takeChoseETH(100, trade);        
    # else:
    #     takeChoseETH(50, trade);      
    #######################
    # if trade.Action.first:
    #     trade.Action.first = False
    #     return "buy USDT_ETH 1.041664921899624"
    # else:
    #     return "pass"
###############################################
    return ""

def useless(trade, line):
    return ""