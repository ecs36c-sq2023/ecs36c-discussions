-- https://wiki.haskell.org/The_Fibonacci_sequence

fibs :: [Int]
fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

fib :: Int -> Int
fib n = fibs' !! n

-- with direct self-reference
fibs' :: [Int]
fibs' = 0 : 1 : next fibs
  where
    next (a : t@(b : _)) = (a + b) : next t
