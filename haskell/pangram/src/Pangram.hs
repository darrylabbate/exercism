module Pangram (isPangram) where

import           Data.Char

isPangram :: String -> Bool
isPangram x = all (`elem` (map toLower x)) ['a'..'z']
