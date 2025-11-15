import Data.List (group, sort)

-- Devuelve lista de (palabra, frecuencia)
wordFreq :: String -> [(String, Int)]
wordFreq = map (\g -> (head g, length g)) . group . sort . words

-- Ejemplo rápido
main :: IO ()
main = print $ wordFreq "ab aa bb aa cc ab aa"