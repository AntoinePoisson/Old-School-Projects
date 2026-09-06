-- --
-- -- EPITECH PROJECT, 2020
-- -- FUN_wolfram_2019
-- -- File description:
-- -- wolfram
-- --

import System.IO
import System.Environment
import System.Exit

-- import Data.Char
-- -- myError :: [Char] -> IO ()
-- -- myError e = do
-- --     putStrLn e
-- --     exitWith (ExitFailure 84)

-- -- main :: IO ()
-- -- main = do
-- --     args <- getArgs
-- --     file <- if null args
-- --         then do putStr "File: " ; getLine
-- --         else pure (head args)
-- --     putStr "processing "
-- --     putStrLn file
-- --     writeFile file "some very nice text"
-- --     myError "OKKKKKKKKKKKKKKK"


-- -- success = exitWith (0)

-- -- error :: String xs -> Nothing
-- -- error = print xs
-- -- error = exitWith (ExitFailure 84)

-- -- main = 0


-- --
-- -- EPITECH PROJECT, 2020
-- -- FUN_wolfram_2019
-- -- File description:
-- -- wolfram
-- --

-- -- import System.IO
-- -- import System.Environment
-- -- import System.Exit

-- -- checkArgs :: [String] -> IO ()
-- -- checkArgs xs = print xs

-- -- myLeave :: [Char] -> Bool -> IO ()
-- -- myLeave x xs
-- --     | xs == False = do 
-- --                 putStrLn x
-- --                 exitWith (ExitFailure 84)
-- --     | otherwise = exitWith (ExitSuccess)
-- checkNumber :: String -> Bool
-- checkNumber = all isDigit

-- main :: IO ()
-- main = do
--         args <- getArgs
--         print (length args)
--         -- if (checkNumber (head args) == True)
--         --     then print "OK"
--         --     else
--         --         print "NON"
-- -- main :: IO ()
-- -- main = do
-- --     args <- getArgs
-- --     checkArgs args
-- --     myLeave "" True

--     -- case head xs of
--     --     "-rule"   -> do 
--     --                     print xs
--     --                     isWrongArgs (tail xs)
--     --     "-start"  -> do 
--     --                     print xs
--     --                     isWrongArgs (tail xs)
--         -- "-lines"  -> do 
--         --                 print xs
--         --                 isWrongArgs tail xs
--         -- "-window" -> do 
--         --                 print xs
--         --                 isWrongArgs tail xs
--         -- "-move"   -> do 
--         --                 print xs
--         --                 isWrongArgs tail xs
--         -- _         -> myLeave "Wrong Arguments." False


--         insertArgs :: [String] -> ([Char], [Char], [Char], [Char], [Char]) -> Int -> ([Char], [Char], [Char], [Char], [Char])
--         insertArgs x res index
--             | index == 0 = do
--                 -- (head x) : res
--                 -- let toto = read (head x)::[Char]
--                 print (read (head x)::[Char])
--                 return (res)
--             | otherwise = insertArgs x res (index - 1)
--             -- | otherwise = (head res) : (insertArgs x (tail res) (index - 1))






-- --
-- -- EPITECH PROJECT, 2020
-- -- FUN_wolfram_2019
-- -- File description:
-- -- wolfram
-- --

-- import System.IO
-- import System.Environment
-- import System.Exit
-- import Data.Char

-- -- data Data = Args

-- -- let Data = []

-- -- checkNumber :: String -> Bool
-- -- checkNumber = all isDigit

-- -- checkArgs :: ([String], ([Char], [Char], [Char], [Char], [Char])) -> Int -> ([String], ([Char], [Char], [Char], [Char], [Char]))
-- -- checkArgs xs = xs
--     -- let nbr = read head xs
--     -- Check le next arg & le stocké dans un stockage globale

-- -- checkArgs :: [Maybe Int] -> IO()
-- -- checkArgs xs = do
-- --     print xs


-- insertArgs :: String -> [Maybe Int] -> Int -> [Maybe Int]
-- insertArgs x xs index
--     -- |  x == "" = [xs !! 0, xs !! 1, xs !! 2, xs !! 3, xs !! 4]
--     | index == 0 = [read (x)::Maybe Int, xs !! 1, xs !! 2, xs !! 3, xs !! 4]
--     | index == 1 = [xs !! 0, read (x)::Maybe Int, xs !! 2, xs !! 3, xs !! 4]
--     | index == 2 = [xs !! 0, xs !! 1, read (x)::Maybe Int, xs !! 3, xs !! 4]
--     | index == 3 = [xs !! 0, xs !! 1, xs !! 2, read (x)::Maybe Int, xs !! 4]
--     | index == 4 = [xs !! 0, xs !! 1, xs !! 2, xs !! 3, read (x)::Maybe Int]
--     -- | otherwise =


--     -- read "4"::Int
--     -- | otherwise = insertArgs x res (index - 1)
--     -- | otherwise = (head res) : (insertArgs x (tail res) (index - 1))

-- -- replaceNth :: Int -> a -> [a] -> [a]
-- -- replaceNth _ _ [] = []
-- -- replaceNth n newVal (x:xs)
-- --   | n == 0 = newVal:xs
-- --   | otherwise = x:replaceNth (n-1) newVal xs


-- isWrongArgs :: [String] -> [Maybe Int] -> IO [Maybe Int]
-- isWrongArgs xs res
--     | length xs == 0       = return res
--     | head xs == "-rule"   = do
--                             print (head xs)
--                             isWrongArgs (tail (tail xs)) $ insertArgs (head (tail xs)) res 0 
--     | head xs == "-start"  = do
--                             print (head xs)
--                             isWrongArgs (tail (tail xs)) $ insertArgs (head (tail xs)) res 1

--     | head xs == "-lines"  = do
--                             print (head xs)
--                             isWrongArgs (tail (tail xs)) $ insertArgs (head (tail xs)) res 2
--     | head xs == "-window" = do
--                             print (head xs)
--                             isWrongArgs (tail (tail xs)) $ insertArgs (head (tail xs)) res 3
--     | head xs == "-move"   = do
--                             print (head xs)
--                             isWrongArgs (tail (tail xs)) $ insertArgs (head (tail xs)) res 4
--     | otherwise            = return ([Nothing, Nothing, Nothing, Nothing])  -- myLeave "Wrong Arguments." False

-- myLeave :: [Char] -> Bool -> IO ()
-- myLeave x xs
--     | xs == False = do
--                 putStrLn x
--                 exitWith (ExitFailure 84)
--     | otherwise = exitWith (ExitSuccess)

-- main :: IO ()
-- main = do
--     args <- getArgs
--     if ((length (args) == 0) || (((length (args)) `mod` 2) /= 0))
--         then myLeave "Wrong Arguments." False
--     else do
--         toto <- isWrongArgs args [Nothing, Nothing, Nothing, Nothing, Nothing]
--         case (toto !! 0) of
--             -- Just value -> ...
--             Just p ->print "YES EE"
--                 where p = 42
--             Nothing    -> print "YES"
--         print "OK"        
--         -- checkArgs toto
--         print "Fin"
--         print toto
--         return () -- myLeave "" True
-- loopDisplay :: Int -> [Char] -> Int -> [Char] -> ()
-- loopDisplay start list count res
--     | count <= 0 = ()
--     | otherwise = do
--         putStrLn ()

-- startedIndex :: Int -> Int -> Int -> Int
-- startedIndex win seg move
--     | (((mod (seg) 2) == 0) && ((mod win 2) /= 0)) = ((((div win 2) - (div seg 2) + 1)) + move)
--     | otherwise                                    = (((div win 2) - (div seg 2)) + move)

-- initList :: Int -> [Char] -> [Char]
-- initList count res
--     | count > 0 = ('+':(initList (count - 1) res))
--     | otherwise = res

-- concatRight :: Int -> [Char] -> [Char] -> [Char] -> Int -> Int -> Int -> [Char]
-- concatRight size init res line currentIndex startedIndex endIndex --started + length line
--     | (size <= currentIndex)                                                               = res -- + un espace ?
--     | ((currentIndex >= startedIndex) && (currentIndex < endIndex) && (length line /= 0)) = concatRight (size) (tail init) ((head line):res) (tail line) (currentIndex + 1) startedIndex endIndex            --check le '<'
--     | (length init /= 0)                                                                  = concatRight (size) (tail init) ((head init):res) line (currentIndex + 1) startedIndex endIndex
--     | otherwise                                                                           = res

-- displayLine :: [Char] -> Int -> Int -> IO ()
-- displayLine str win move = do
--     let init = initList win []
--     let started = startedIndex win (length str) move
--     -- if (started < 1)
--     --     then putStrLn 
--     print (started)
--     if (started < win)
--         then putStrLn (reverse (concatRight win init [] str 0 started (started + (length str))))
--     else putStrLn init


startedIndex :: Int -> Int -> Int -> Int
startedIndex win seg move
    | (((mod (seg) 2) == 0) && ((mod win 2) /= 0)) = ((((div win 2) - (div seg 2) + 1)) + move)
    | otherwise                                    = (((div win 2) - (div seg 2)) + move)

main :: IO ()
main = do
    args <- getArgs
    let win = read (head args)::Int
    let seg = read (head (tail args))::Int
    let move = read (head (tail (tail args)))::Int
    print (startedIndex win seg move)
    -- let move = read (head (tail (tail args)))::Int
    -- let started = startedIndex win seg move -- (length seg)
    -- let init = initList win []
    -- print started
    -- putStrLn init
    -- putStrLn display


    -- -- print (div win)
    -- -- print (seg)
    -- -- print (padding)
    -- -- print "-----------"
    -- if ((mod (win) 2) == 0)
    --     then do
    --         let res = ((((div win 2) - (div seg 2)) + 1) + move)
    --         print res
    --         -- if ()
    --         --     then
    --         -- else
    -- else do
    --     let res = (((div win 2) - (div seg 2) + 1) + move)
    --     print res
    --     return () -- myLeave "" True