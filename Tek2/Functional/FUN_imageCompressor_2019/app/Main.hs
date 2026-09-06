--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- main
--

module Main where

import System.Environment
import System.Exit
import System.Random
import System.IO
import Text.Printf
import Data.List

---------------------------------------
    -- Transform liste
stringToInt :: [String] -> [Int]
stringToInt x
    | (length x <= 0) = []
    | otherwise = (read (head x)::Int):(stringToInt (tail x))

mySplit :: Char -> String -> [String]
mySplit c xs = case break (==c) xs of 
    (ls, "") -> [ls]
    (ls, x) -> ls : (mySplit c (tail x))

    --                      list        res        res
convertListStringToInt :: [String] -> [[Int]] -> [[Int]]
convertListStringToInt x xs
    | (x == []) = xs
    | otherwise = do
        let one = x!!0
        let two = x!!1
        convertListStringToInt (tail (tail x)) ((xs) ++ [(stringToInt (mySplit ',' (one ++ "," ++ two)))])
    
deleteParenth :: [String] -> Int -> [[Char]] -> [[Char]]
deleteParenth _ 0 list2 = list2
deleteParenth list cont list2 = do 
    let test = delete ')' (delete '(' (list!!(cont - 1)))
    (deleteParenth list (cont - 1) ([test])) ++ list2

---------------------------------------
    -- Loop
calcDistance :: [Int] -> [Int] -> Float
calcDistance [] [] = 0
calcDistance a b = sqrt (fromIntegral ((((a!!2)-(b!!2))^(2::Int)) + (((a!!3)-(b!!3))^(2::Int)) + (((a!!4)-(b!!4))^(2::Int))))
    
randomRange :: [[Int]] -> IO [Int]
randomRange xs = (xs !!) <$> randomRIO (0, length xs - 1)
    
indexing :: [[Int]] -> Int -> [[Int]]
indexing x xs
    | ((length x) > 0)  = (xs : head (x)) : (indexing (tail x) (xs + 1))
    | otherwise         = x     
    
    --       list    element
findSameList :: [[Int]] -> [Int] -> Bool
findSameList x xs
    | x == []            = False
    | ((head x) == xs)   = True
    | otherwise          = findSameList (tail x) xs
    
    --              list    nbr selec    res
selectReference :: [[Int]] -> Int -> [[Int]] -> IO [[Int]]
selectReference _ 0 x = return x
selectReference x k xs = do
    tmp <- (randomRange x)
    if ((findSameList xs tmp) == False)
        then (selectReference x (k - 1) (tmp:xs))
    else
        (selectReference x (k) xs)
    
    --        ele list  ref list index closer  value
finderCloser :: [Int] -> [[Int]] -> Int -> Float -> Int
finderCloser x ref i val
    | ((length ref) <= 0) = i
    | otherwise = do
        let tmpHead = head ref
        let distance = calcDistance x tmpHead
        if ((i == -1) || (distance < val))
            then finderCloser x (tail ref) ((tmpHead)!!0) distance
        else finderCloser x (tail ref) i val
    
    --               list        Ref       res
compareListToRef :: [[Int]] -> [[Int]] -> [[Int]]
compareListToRef [] _ = []
compareListToRef x xs = do
    let tmp = head (x)
    [(finderCloser tmp xs (-1) 0), tmp!!1, tmp!!2, tmp!!3, tmp!!4, tmp!!5]:compareListToRef (tail x) xs
    
    --           list     index    res
getSameIndex :: [[Int]] -> Int -> [[Int]]
getSameIndex x i
    | ((length x) <= 0) = []
    | (((head x)!!0) == i) = ((head x):(getSameIndex (tail x) i))
    | otherwise = getSameIndex (tail x) i
    
    --         list    value   index   res
calcMeans :: [[Int]] -> Bool -> Int -> Int
calcMeans x bool i
    | x == []      = 0
    | bool == True = ((((head x)!!i) + (calcMeans (tail x) False i)) `div` (length x))
    | otherwise    = (((head x)!!i) + (calcMeans (tail x) False i))
    
    --          list        ref        res
handleMeans :: [[Int]] -> [[Int]] -> [[Int]]
handleMeans x xs
    | xs == []  = []
    | otherwise = do
        let tmp = head (xs)
        [tmp!!0, tmp!!1, tmp!!2, (calcMeans (getSameIndex x (tmp!!0)) True 3), (calcMeans (getSameIndex x (tmp!!0)) True 4), (calcMeans (getSameIndex x (tmp!!0)) True 5)]:handleMeans x (tail xs)
    
displayList :: [[Int]] -> IO ()
displayList x
    | x == [] = return ()
    | otherwise = do
        let tmp = head x
        printf "(%d,%d) (%d,%d,%d)\n" (tmp!!1) (tmp!!2) (tmp!!3) (tmp!!4) (tmp!!5) 
        displayList (tail x)
    
    --            list        ref
displayResult :: [[Int]] -> [[Int]] -> IO ()
displayResult x ref
    | ref == [] = return ()
    | otherwise = do
        let tmp = head ref
        let list = getSameIndex x (tmp!!0)
        printf "--\n(%d,%d,%d)\n-\n" (tmp!!3) (tmp!!4) (tmp!!5)
        displayList list
        displayResult x (tail ref)
    
--              ref      new ref   conver  res
convergenceCompare :: [[Int]] -> [[Int]] -> Float -> Bool
convergenceCompare [] [] _ = True
convergenceCompare x xs conv
    | ((calcDistance (head x) (head xs)) < conv) = convergenceCompare (tail x) (tail xs) conv
    | otherwise = False
        
    --    list       ref    converg    first
loop :: [[Int]] -> [[Int]] -> Float  -> Bool -> IO ()
loop x ref conv first
    | first = loop (compareListToRef x ref) ref conv False
    | otherwise = do
        let tmp = handleMeans x ref
        if ((convergenceCompare ref tmp conv) == True)
            then displayResult x tmp
        else
            loop (compareListToRef x tmp) tmp conv False 

---------------------------------------
    -- Check Error
myLeave :: [Char] -> Bool -> IO ()
myLeave x xs
    | xs == False = do
        putStrLn x
        exitWith (ExitFailure 84)
    | otherwise = exitWith (ExitSuccess)

myisDigit :: Char -> Bool
myisDigit a = a >= '0' && a <= '9' || a == '.'

check :: [Char] -> Bool
check [] = True
check (x:xs)
        | myisDigit x = check xs
        | otherwise = False

checkm :: [Char] -> Bool
checkm [] = False
checkm (x:xs) = case (x >= '0' && x <= '9' || x == '.') of
    True -> check xs
    _ -> False

checkargs :: [String] -> Int -> Bool
checkargs _ 0 = True
checkargs [] _ = False
checkargs (x:xs) count
    | checkm x == True = checkargs xs (count - 1)
    | otherwise = False

_myisDigit :: Char -> Bool
_myisDigit a = a >= '0' && a <= '9' || a == ',' || a == ')' || a == '('

_check :: [Char] -> Bool
_check [] = True
_check (x:xs)
        | _myisDigit x = _check xs
        | otherwise = False

check_content :: [Char] -> Bool
check_content [] = False
check_content (x:xs) = case (x >= '0' && x <= '9' || x == ',' || x == ')' || x == '(') of
    True -> _check xs
    _ -> False

checkopen :: [String] -> Int -> Bool
checkopen _ 0 = True
checkopen [] _ = False
checkopen (x:xs) cont
    | check_content x == True = checkopen xs (cont - 1)
    | otherwise = False

check_k :: Int -> Int -> Bool
check_k 0 _ = False
check_k k len
    | k > len = False
    | otherwise = True

------------------------------------------------

main :: IO ()
main = do
    args <- getArgs
    if (((length (args)) /= 3))
        then myLeave "Not enough Argument." False
    else do  
        handle <- openFile (args!!2) ReadMode  
        contents <- hGetContents handle
        if (((checkargs args 2) == False) || (checkopen (words contents) (length (words contents))) == False || (check_k (read (args!!0)::Int) (((length (words contents))) `div` 2)) == False)
            then myLeave "Wrong Arguments." False  
        else do
            let k = (read (args!!0)::Int)
            let convergence = (read (args!!1)::Float)
            let tmp = (words contents)
            let list = indexing (convertListStringToInt (deleteParenth (tmp) (length (tmp)) []) []) 0
            ref <- selectReference list k []
            loop list ref convergence True
            exitWith (ExitSuccess)