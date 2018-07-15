module PerfectNumbers (classify, Classification(..)) where

data Classification = Deficient
                    | Perfect
                    | Abundant
                    deriving (Eq, Show)

classify :: Int -> Maybe Classification
classify n | n < 1        = Nothing
           | n == aliSums = Just Perfect
           | n < aliSums  = Just Abundant
           | otherwise    = Just Deficient
           where aliSums = sum $ filter ((==0) . rem n) [1..(div n 2)]
