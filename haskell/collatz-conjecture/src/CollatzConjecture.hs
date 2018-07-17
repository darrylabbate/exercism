module CollatzConjecture (collatz) where

collatz :: Integer -> Maybe Integer
collatz n = if n <= 0 then Nothing else step 0 n

step :: Integer -> Integer -> Maybe Integer
step s n | n == 1    = Just s
         | even n    = step (succ s) (div n 2)
         | otherwise = step (succ s) (n*3 + 1)
