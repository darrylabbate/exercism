module Hamming (distance) where

distance :: String -> String -> Maybe Integer
distance xs ys | length xs /= length ys = Nothing
               | xs == ys               = Just 0
               | otherwise              = diff 0 xs ys

diff :: Integer -> String -> String -> Maybe Integer
diff d (x:xs) (y:ys) | x == y    = diff d xs ys
                     | x /= y    = diff (succ d) xs ys
                     | otherwise = Just d
diff d _ _           = Just d
