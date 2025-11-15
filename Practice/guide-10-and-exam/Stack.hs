module Stack
  ( Stack
  , empty        -- constructor value for an empty stack
  , emptyStack   -- predicate: is stack empty?
  , top          -- peek top element
  , pop          -- pop top element, returning (element, newStack)
  , push         -- push element onto stack
  ) where

newtype Stack a = Stack [a]
  deriving (Show, Eq)

-- empty stack value
empty :: Stack a
empty = Stack []

-- True if stack has no elements
emptyStack :: Stack a -> Bool
emptyStack (Stack xs) = null xs

-- top element (Nothing if empty)
top :: Stack a -> Maybe a
top (Stack [])    = Nothing
top (Stack (x:_)) = Just x

-- pop: returns Nothing if empty, otherwise (topElement, newStack)
pop :: Stack a -> Maybe (a, Stack a)
pop (Stack [])     = Nothing
pop (Stack (x:xs)) = Just (x, Stack xs)

-- push element onto stack (becomes new top)
push :: a -> Stack a -> Stack a
push x (Stack xs) = Stack (x : xs)