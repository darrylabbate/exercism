module Bob (responseFor) where

import           Data.Char

data Address = Question
             | Yell
             | YellQuestion
             | Silence
             | Normal

classify :: String -> Address
classify a | all isSpace a    = Silence
           | yell && question = YellQuestion
           | yell             = Yell
           | question         = Question
           | otherwise        = Normal
           where yell     = any isAlpha a && all isUpper (filter isAlpha a)
                 question = '?' == last (filter (not . isSpace) a)

response :: Address -> String
response Silence      = "Fine. Be that way!"
response YellQuestion = "Calm down, I know what I'm doing!"
response Yell         = "Whoa, chill out!"
response Question     = "Sure."
response Normal       = "Whatever."

responseFor :: String -> String
responseFor = response . classify
