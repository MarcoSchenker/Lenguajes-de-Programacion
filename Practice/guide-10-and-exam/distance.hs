module Distance
  ( euclidean
  , manhattan
  , chebyshev
  ) where

-- distancia euclidiana (geométrica)
euclidean :: Floating a => (a,a) -> (a,a) -> a
euclidean (x1,y1) (x2,y2) =
  sqrt ((x1 - x2) ^ 2 + (y1 - y2) ^ 2)

-- distancia de Manhattan (taxicab)
manhattan :: Num a => (a,a) -> (a,a) -> a
manhattan (x1,y1) (x2,y2) =
  abs (x1 - x2) + abs (y1 - y2)

-- distancia de Chebyshev (máximo de las diferencias)
chebyshev :: (Ord a, Num a) => (a,a) -> (a,a) -> a
chebyshev (x1,y1) (x2,y2) =
  max (abs (x1 - x2)) (abs (y1 - y2))
