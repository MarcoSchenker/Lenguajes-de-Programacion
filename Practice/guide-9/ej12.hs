suma' :: Num a => [a] -> a
suma' = foldl1 (+)
-- Falla si la lista es vacía
-- ya que foldl1 no tiene un valor inicial
-- para empezar la acumulación

main :: IO ()
main = do
    print (suma' [1,2,3,4])  -- 10
    print (suma' [])         -- error en tiempo de ejecución