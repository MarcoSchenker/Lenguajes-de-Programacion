module IsContained where

import Data.List (tails, isPrefixOf)

-- Devuelve True si la lista 'sub' está contenida completamente en 'xs'
isContained :: Eq a => [a] -> [a] -> Bool
isContained sub xs = any (isPrefixOf sub) (tails xs)
-- any recibe una funcion que recibe un elemento y devuelve Bool
-- y una lista del mismo tipo que el elemento
-- se aplica la funcion a cada elemento de la lista

-- Ejemplos rápidos
main :: IO ()
main = do
  print $ isContained [2,3] [1,2,3,4,5]   -- True
  print $ isContained [1,3] [1,2,3,4,5]   -- False
  print $ isContained "ello" "hello!"     -- True