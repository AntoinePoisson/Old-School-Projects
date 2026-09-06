##
## EPITECH PROJECT, 2020
## CNA_trade_2019
## File description:
## class
##

import sys

class Trade:
    def parseLine(self, line):
        line.strip()
        line.replace('\n', '')
        return line.split(' ')
    
    def displayStdout(self, string):
        if (string != "" and string is not None):
            print(string, end='\n', flush=True)
        sys.stdout.flush()

    def displayStderr(self, string):
        if (string != "" and string is not None):
            sys.stderr.write(string + "\n")
        sys.stderr.flush()

    class Settings:
        candleInterval = 0
        candlesTotal = 0
        candlesGiven = 0
        initialStack = 0
        transactionFeePercent = 0.0
        candle_format = []

    class Data:
        stock = []
        stack = []
        
    class Action:
        first = True
        lastActionBTC = "buy"
        lastActionETH = "buy"
    btc = 0
    eth = 0
    usdt = 0