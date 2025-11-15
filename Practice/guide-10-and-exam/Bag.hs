module Bag
  ( Bag
  , empty
  , isEmpty
  , multiplicity
  , add
  , deleteOne
  , deleteAll
  , choose
  , fromList
  ) where

-- Representación simple: lista de pares (elemento, multiplicidad)
newtype Bag a = Bag [(a, Int)]
  deriving (Show, Eq)

empty :: Bag a
empty = Bag []

isEmpty :: Bag a -> Bool
isEmpty (Bag xs) = null xs

multiplicity :: Eq a => a -> Bag a -> Int
multiplicity x (Bag xs) = go xs
  where
    go [] = 0
    go ((y,n):ys)
      | x == y    = n
      | otherwise = go ys

add :: Eq a => a -> Bag a -> Bag a
add x (Bag xs) = Bag (go xs)
  where
    go [] = [(x,1)]
    go ((y,n):ys)
      | x == y    = (y, n+1) : ys
      | otherwise = (y, n) : go ys

deleteOne :: Eq a => a -> Bag a -> Bag a
deleteOne x (Bag xs) = Bag (go xs)
  where
    go [] = []
    go ((y,n):ys)
      | x == y && n > 1 = (y, n-1) : ys
      | x == y          = ys            
      | otherwise       = (y, n) : go ys

deleteAll :: Eq a => a -> Bag a -> Bag a
deleteAll x (Bag xs) = Bag (filter (\(y,_) -> y /= x) xs)

choose :: Bag a -> Maybe a
choose (Bag [])        = Nothing
choose (Bag ((y,_):_)) = Just y

-- Conveniencia: construir Bag desde lista con ocurrencias
fromList :: Eq a => [a] -> Bag a
fromList = foldr add empty