##
## EPITECH PROJECT, 2020
## CNA_trade_2019
## File description:
## calcul
##

import sys
import math
import random
from src.tool import *

## range des réponse de 0 à 100
##  de 0 à 30 sell
##  de 30 à 70 pass (pas inclut)
##  de 70 à 100 buy
##
## Un pourcentage est ensuite effectué, par exemple:
##    response = 10 alors vendre (30 - response): 20/30 -> 66/100 -> sell 66%
## Autre exemple:
##    response = 75 alors acheter (response - 70): 5/30 -> 16/100 -> buy 16%
## Mini conclusion:
## Pour VENDRE 50% la réponse doit être égale à 15
## Pour ACHETER 50% la réponse doit être égale à 85

###################################################################### 
##                  - Coef de référence:
## 1-3: Faible impact
## 4-6: Fort impact
## 6-10: TRES FORT IMPACT
## (>= 100: ACTION OBLIGATOIRE)
######################################################################


## Pense Bete Perso:
## mettre en commentaire la maniere que les données son stocker
## faire un truc flexible au niveau du stokage ?? (Demander à Tony)
## Possibilité de de convversion inter money
## 
## trade.Data.stock[0]:
## [['BTC_ETH', 1517439600.0, 0.10933, 0.109, 0.10930997, 0.109285, 32.66246468], ['USDT_ETH', 1517439600.0, 1113.0, 1105.00000003, 1112.99999988, 1112.84309464, 130996.70979922], ['USDT_BTC', 1517439600.0, 10221.1204002, 10106.08674044, 10185.14136698, 10207.85630909, 413829.60256904]]
##
## Evolution des gains:
## 1S: 987.73 - 988.77
##
## /home/quentin/year2/Projects/CNA_trade_2019/training_set.csv
##

def callGlobalCalcul(trade, isBTC):
    result = []
    # if (isBTC == False):
    #     result += [doublebollingerBandsETH(trade)]
    # else:
    #     result += [doublebollingerBandsBTC(trade)]
    if (isBTC == False):
        result += [bollingerBandsETH(trade)]
    else:
        result += [bollingerBandsBTC(trade)]
    # result += [compareWithLastValue(trade, isBTC)]         # PERTE -> 935 -- Fonctionnel -> 1150
    # result += [FirstTrade(trade, isBTC)]                   # PERTE -> 986 -- Fonctionnel -> 1073
    # result += [AverageHight(trade, isBTC)]                 # PERTE -> 965
    # result += [MobileAverageHight(trade, isBTC)]           # PERTE -> 965
    # result += [MobileEcartType(trade, isBTC)]              # RIEN  -> 1000
    # result += [calculOfTendance(trade, isBTC, 0.03, 10, 4)]  # RIEN -> 1000   ## % relativement bas avant 0.0008, 5, 4
    # result += [calculOfTendance(trade, isBTC, 0.8, 30, 3)] # RIEN -> 1000
    # result += [calculOfTendance(trade, isBTC, 1, -1, 2)]   # RIEN -> 1000
    # result += [computeOBV(trade, isBTC)]
        # result += [LookLastTrade(trade, isBTC, result)] ## doit être dernier  # PERTE -> 960 -- Fonctionnel

    ####### Random
    # result = [[int(random.randint(0, 100)), 1]]
    #######
    # trade.displayStderr("Avant: "  + str(result));
        ## Calcul de la moyenne de nos fonction
    result = calculMeansResultat(result)
    # trade.displayStderr("Apres: "  +str(result));    
    if (result <= 30):
        return (calculHowManyToSell(result, trade, isBTC))
    if (result < 70):
        return (0)
    if (result <= 100):
        return (calculHowManyToBuy(result, trade, isBTC))
    return (0)

_recurrence_last_action = 0
_recurrence_last_actionB = 0

##########################################################################################################################################
##########################################################################################################################################

def determineHowManyToSellBDouble(trade):
    # global _recurrence_last_actionB
    # if (_recurrence_last_actionB > 0):
    #     _recurrence_last_actionB = 0
    # _recurrence_last_actionB -= 1
    # size = _recurrence_last_actionB * -1
    # if (_recurrence_last_actionB == -1):
    #     return (([72, 9]))
    # return calculOfTendance(trade, True, 0, size, 9) ##Mettre True
    return (([85, 9]))

def determineHowManyToBuyBDouble(trade):
    # global _recurrence_last_actionB
    # if (_recurrence_last_actionB < 0):
    #     _recurrence_last_actionB = 0
    # _recurrence_last_actionB += 1
    # size = _recurrence_last_actionB
    # if (_recurrence_last_actionB == 1):
    #     return (([28, 9]))
    # return calculOfTendance(trade, True, 1, size, 9) ##Mettre True
    return (([15, 9]))

def determineHowManyToSellDouble(trade):
    # global _recurrence_last_action
    # if (_recurrence_last_action > 0):
    #     _recurrence_last_action = 0
    # _recurrence_last_action -= 1
    # size = _recurrence_last_action * -1
    # if (_recurrence_last_action == -1):
    #     return (([72, 9]))
    # return calculOfTendance(trade, False, 0, size, 9)
    return (([85, 9]))

def determineHowManyToBuyDouble(trade):
    # global _recurrence_last_action
    # if (_recurrence_last_action < 0):
    #     _recurrence_last_action = 0
    # _recurrence_last_action += 1
    # size = _recurrence_last_action
    # if (_recurrence_last_action == 1):
    #     return (([28, 9]))
    # return calculOfTendance(trade, False, 1, size, 9)
    return (([15, 9]))

def doublebollingerBandsETH(trade):
    if len(trade.Data.stock) < 20:
        return (([50, 9]))

    values_2 = list(map(lambda x: x[1][5], trade.Data.stock[:10]))
    values_3 = list(map(lambda x: x[1][5], trade.Data.stock[:20]))

    average_2 = sum(values_2) / len(values_2)
    average_3 = sum(values_3) / len(values_3)

    stdev_2 = math.sqrt(sum(map(lambda x: ((abs(x - average_2))**2), values_2)) / len(values_2))
    stdev_3 = math.sqrt(sum(map(lambda x: ((abs(x - average_3))**2), values_3)) / len(values_3))

    bands_2 = [average_2 + stdev_2, average_2 - stdev_2]
    bands_3 = [average_3 + stdev_3, average_3 - stdev_3]

    if bands_2[0] > bands_3[0]:
        return determineHowManyToSellDouble(trade)
    if bands_2[1] < bands_3[1]:
        return determineHowManyToBuyDouble(trade)
        # prev = list(map(lambda x: x[1][5], trade.Data.stock[:4]))
        # decision = 0
        # for index in range(3):
        #     decision += (-1, 1)[prev[index] > prev[index + 1]]
        # if decision > 0:
        #     return (([28, 9]))
        # return (([72, 9]))
    return (([50, 9]))

def doublebollingerBandsBTC(trade):
    if len(trade.Data.stock) < 20:
        return (([50, 9]))

    values_2 = list(map(lambda x: x[2][5], trade.Data.stock[:10]))
    values_3 = list(map(lambda x: x[2][5], trade.Data.stock[:20]))

    average_2 = sum(values_2) / len(values_2)
    average_3 = sum(values_3) / len(values_3)

    stdev_2 = math.sqrt(sum(map(lambda x: ((abs(x - average_2))**2), values_2)) / len(values_2))
    stdev_3 = math.sqrt(sum(map(lambda x: ((abs(x - average_3))**2), values_3)) / len(values_3))

    bands_2 = [average_2 + stdev_2, average_2 - stdev_2]
    bands_3 = [average_3 + stdev_3, average_3 - stdev_3]

    if bands_2[0] > bands_3[0]:
        return determineHowManyToSellBDouble(trade)
    if bands_2[1] < bands_3[1]:
        return determineHowManyToBuyBDouble(trade)
        # prev = list(map(lambda x: x[1][5], trade.Data.stock[:4]))
        # decision = 0
        # for index in range(3):
        #     decision += (-1, 1)[prev[index] > prev[index + 1]]
        # if decision > 0:
        #     return (([28, 9]))
        # return (([72, 9]))
    return (([50, 9]))

##########################################################################################################################################
##########################################################################################################################################

_prev_boundaries = [0, 0]
_tightening = 0
_prev_average = 0

def determineHowManyToSell(trade):
    global _recurrence_last_action
    if (_recurrence_last_action > 0):
        _recurrence_last_action = 0
    _recurrence_last_action -= 1
    size = _recurrence_last_action * -1
    if (_recurrence_last_action == -1):
        return (([72, 9]))
    return calculOfTendance(trade, False, 0, size, 9)
    # return (([75, 9]))

def determineHowManyToBuy(trade):
    global _recurrence_last_action
    if (_recurrence_last_action < 0):
        _recurrence_last_action = 0
    _recurrence_last_action += 1
    size = _recurrence_last_action
    if (_recurrence_last_action == 1):
        return (([28, 9]))
    return calculOfTendance(trade, False, 1, size, 9)
    # return (([25, 9]))

def determineHowManyToSellB(trade):
    global _recurrence_last_actionB
    if (_recurrence_last_actionB > 0):
        _recurrence_last_actionB = 0
    _recurrence_last_actionB -= 1
    size = _recurrence_last_actionB * -1
    if (_recurrence_last_actionB == -1):
        return (([72, 9]))
    return calculOfTendance(trade, True, 0, size, 9) ##Mettre True
    # return (([75, 9]))

def determineHowManyToBuyB(trade):
    global _recurrence_last_actionB
    if (_recurrence_last_actionB < 0):
        _recurrence_last_actionB = 0
    _recurrence_last_actionB += 1
    size = _recurrence_last_actionB
    if (_recurrence_last_actionB == 1):
        return (([28, 9]))
    return calculOfTendance(trade, True, 1, size, 9) ##Mettre True
    # return (([25, 9]))

def bollingerBandsETH(trade):
    global _prev_boundaries, _tightening, _prev_average
    if len(trade.Data.stock) < 15:
        return (([50, 9]))
    values = list(map(lambda x: x[1][5], trade.Data.stock[:15]))
    mobile_average = sum(values) / len(values)
    std_dev = math.sqrt(sum(map(lambda x: ((abs(x - mobile_average))**2), values)) / len(values))
    boundaries = [(mobile_average + (2 * std_dev)), (mobile_average - (2 * std_dev))]
    if _prev_boundaries != [0, 0] and abs(boundaries[0] - boundaries[1]) > abs(_prev_boundaries[0] - _prev_boundaries[1]):
        _tightening = 0
        _prev_boundaries = boundaries
        prev = _prev_average
        _prev_average = mobile_average
        if (prev < mobile_average):
            return determineHowManyToSell(trade)
        return determineHowManyToBuy(trade)
    _prev_boundaries = boundaries
    _prev_average = mobile_average
    return (([50, 9]))

_prev_boundariesB = [0, 0]
_tighteningB = 0
_prev_averageB = 0

def bollingerBandsBTC(trade):
    global _prev_boundariesB, _tighteningB, _prev_averageB
    if len(trade.Data.stock) < 15:
        return (([50, 9]))
    values = list(map(lambda x: x[2][5], trade.Data.stock[:15]))
    mobile_average = sum(values) / len(values)
    std_dev = math.sqrt(sum(map(lambda x: ((abs(x - mobile_average))**2), values)) / len(values))
    boundaries = [(mobile_average + (2 * std_dev)), (mobile_average - (2 * std_dev))]
    if _prev_boundariesB != [0, 0] and abs(boundaries[0] - boundaries[1]) > abs(_prev_boundariesB[0] - _prev_boundariesB[1]):
        _tighteningB = 0
        _prev_boundariesB = boundaries
        prev = _prev_averageB
        _prev_averageB = mobile_average
        if (prev < mobile_average):
            return determineHowManyToSell(trade)
        return determineHowManyToBuy(trade)
    _prev_boundariesB = boundaries
    _prev_averageB = mobile_average
    return (([50, 9]))

##########################################################################################################################################
##########################################################################################################################################

    ## Antoine Semaine 1 Function:
def compareWithLastValue(trade, isBTC):
    index = (1, 2)[isBTC]
    if (len(trade.Data.stock) < 2):
        return ([50, 1])
    newElement = trade.Data.stock[0][index][5]
    oldElement = trade.Data.stock[1][index][5]
    rangeError = ((oldElement * 1.1) / 100) ## avant 1.3
    if (((oldElement + rangeError) >= newElement) and
        ((oldElement - rangeError) <= newElement)):
        return ([50, 3])
    if (oldElement < newElement):
        start = 71
        multi = 1.0
        while start <= 100:
            if (oldElement + rangeError * 1.0) >= newElement:
                return ([start, 3])
            start += 2
            multi += 0.1
        return ([100, 2])
    start = 29
    multi = 1.0
    while start >= 0:
        if (oldElement - rangeError * 1.0) >= newElement:
            return ([start, 3])
        start -= 2
        multi += 0.1
    return ([0, 2])

def FirstTrade(trade, isBTC):
    if (trade.Action.first == True):
        return ([83, 8])
    return ([50, 0])

def LookLastTrade(trade, isBTC, result):
    total = calculMeansResultat(result)
    prev = (trade.Action.lastActionETH, trade.Action.lastActionBTC)[isBTC]
    rangeError = ((total * 5) / 100)    
    if (prev == "buy" and ((total) < 70) and ((total + rangeError) >= 70)):
        return ([75, 2])
    elif (prev == "sell" and ((total) > 30) and ((total - rangeError) <= 30)):
        return ([25, 2])
    return ([50, 0])
    ######################

    ## Quentin Semaine 1 Function:
def AverageHight(trade, isBTC):
    index = (1, 2)[isBTC]
    if (len(trade.Data.stock) < 5):
        return ([50, 1])
    sum = 0
    for i in trade.Data.stock:
        sum += i[index][2]
    if (sum / len(trade.Data.stock) >= 10000.0):
        return ([85, 3])
    return ([25, 3])

def MobileAverageHight(trade, isBTC):
    index = (1, 2)[isBTC]
    if (len(trade.Data.stock) < 5):
        return ([50, 0])
    sum = 0
    for i in range(0, 5):
        sum += trade.Data.stock[i][index][2]
    if (sum / 5 >= 10000.0):
        return ([85, 5])
    return ([25, 5])

def MobileEcartType(trade, isBTC):
    index = (1, 2)[isBTC]
    if (len(trade.Data.stock) < 5):
        return ([50, 0])
    res = (trade.Data.stock[0][index][2] - trade.Data.stock[4][index][2]) / trade.Data.stock[4][index][2] * 100.0
    if (res <= 10.0):
        return ([20, 3])
    return ([65, 4])
    ######################

    ## Antoine Semaine 2 Function:
def calculOfTendance(trade, isBTC, buff, size, impact):
    index_list = (1, 2)[isBTC]
    if (size == -1):
        size = len(trade.Data.stock)
    value = []
    date = []
    index = 0
    while (size > 0 and index < len(trade.Data.stock)):
        value += [float((trade.Data.stock[index][index_list][2] + trade.Data.stock[index][index_list][3]) / 2)]
        date += [float(trade.Data.stock[index][index_list][1])]
        size -= 1
        index += 1
    if len(date) <= 1:
        return ([50, 9])
    # trade.displayStderr(str(value))
    diff = value[0] - value[len(value) - 1]
    multiplicator = 5 + buff
    tmp = abs(diff)
    if (tmp > 0 and tmp - (5 * (len(value) / 3)) > 0) == False and len(value) % 10:
        multiplicator += 1
    if (tmp > 0 and tmp - (5 * (len(value) / 3)) > 0) == False and len(value) % 15:
        multiplicator += 1
    if (tmp > 0 and tmp - (5 * (len(value) / 3)) > 0) == False and len(value) % 20:
        multiplicator += 1
    if (tmp > 0 and tmp - (5 * (len(value) / 3)) > 0) == False and len(value) % 25:
        multiplicator += 1
    while (tmp > 0 and tmp - (5 * (len(value) / 2)) > 0):
        tmp -= (5 * (len(value) / 2))
        multiplicator += 2
    if (multiplicator > 30):
        multiplicator = 30
    # trade.displayStderr("MULTIPLICATOR = " + str(multiplicator))
    if (diff < 0):
        # trade.displayStderr(" --- Down   " + str(([30 - multiplicator, 9])))
        return ([30 - multiplicator, 9])
    else:
        # trade.displayStderr(" +++ UP   " + str(([multiplicator + 70, 9])))
        return ([multiplicator + 70, 9])

def computeOBV(trade, isBTC):
    if (len(trade.Data.stock) < 20):
        return ([50, 0])
    index = (1, 2)[isBTC]
    obv = 0.0
    prev = trade.Data.stock[0][index][5]
    for i in range(1, 20):
        if (trade.Data.stock[i][index][5] > prev):
            obv += trade.Data.stock[i][index][6]
        elif (trade.Data.stock[i][index][5] < prev):
            obv -= trade.Data.stock[i][index][6]
    if (obv > 0.0):
        return ([75, 4])
    return ([20, 4])
    
    ######################

def calculMeansResultat(tab):
    result = 0
    divisor = 0
    if (len(tab) == 0):
        return (50)
    for element in tab:
        if (len(element) == 2):
            coef = element[1]
            while (coef > 0):
                result += element[0]
                divisor += 1
                coef -= 1
    if (divisor == 0):
        return (50)
    return (result / divisor)

def calculHowManyToSell(value, trade, isBTC):
    result = (((30 - value) * 100) / 30)
    # trade.displayStderr(str(trade.usdt) + ' ' + str(trade.btc) + ' ' + str(trade.eth))
    # if isBTC and trade.btc < result:
    #     return (0)
    # elif trade.usdt < result:
    #     return (0)
    # else:
    ## if (trade.Settings.transactionFeePercent >= ((result * (trade.eth, trade.btc)[isBTC]) / 100))
    return (-result)

def calculHowManyToBuy(value, trade, isBTC):
    result = (((value - 70) * 100) / 30)
    # sys.stderr.write("calculHowManyToBuy :" + str(result) + '\n')
    # if trade.usdt <= 50.0:
    #     return (0)
    return (result)
