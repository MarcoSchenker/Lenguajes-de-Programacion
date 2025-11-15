module Set
  ( Set
  , empty        -- constructor value for an empty set
  , isIn         -- predicate: is element in set?
  , add         -- insert element into set
  , delete       -- delete element from set
  , choose       -- choose an arbitrary element from set
  ) where

newtype Set a = Set [a]
  deriving (Show, Eq)

empty :: Set a
empty = Set []

isIn :: Eq a => a -> Set a -> Bool
isIn x (Set xs) = x `elem` xs

add :: Eq a => a -> Set a -> Set a
add x (Set xs)
  | isIn x (Set xs) = Set xs
  | otherwise   = Set (x:xs)

delete :: Eq a => a -> Set a -> Set a
delete x (Set xs) = Set deleted
    where deleted = filter (/= x) xs

choose :: Set a -> Maybe a
choose (Set [])    = Nothing
choose (Set (x:_)) = Just x