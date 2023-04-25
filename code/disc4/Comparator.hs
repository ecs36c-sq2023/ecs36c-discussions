module Comparator where

import Data.Default (Default, def)

isDefault :: forall a. (Eq a, Default a) => a -> Bool
isDefault x = x == (def :: a)

isDefaultKey :: forall a b. (Eq a, Default a) => (a, b) -> Bool
isDefaultKey = isDefault . fst

main :: IO ()
main = do
  print $ isDefault (0 :: Int)
  print $ isDefault (1 :: Int)
  print $ isDefaultKey (0 :: Int, "hello")
  print $ isDefaultKey (1 :: Int, "world")
  print $ isDefaultKey ("hello", 2)
  print $ isDefaultKey ("", 3)
