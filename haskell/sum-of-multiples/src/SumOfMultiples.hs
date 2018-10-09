module SumOfMultiples (sumOfMultiples) where

sumOfMultiples :: [Integer] -> Integer -> Integer
sumOfMultiples fs l = sum $ filter f [1..l-1] where
  f n = any ((==0) . mod n) fs
