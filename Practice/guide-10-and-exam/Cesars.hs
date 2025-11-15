module Cesars (cifrar, descifrar) where

import Data.Char (ord, chr, isLower)

-- desplaza un carácter solo si es lowercase; no altera mayúsculas ni otros chars
shiftChar :: Int -> Char -> Char
shiftChar n c
  | isLower c = shiftBase 'a' n c
  | otherwise = c

shiftBase :: Char -> Int -> Char -> Char
shiftBase base n c =
  let m = 26
      offset = (ord c - ord base + n) `mod` m
  in chr (ord base + offset)

-- cifrar recibe un desplazamiento y una palabra/cadena (solo afecta minúsculas)
cifrar :: Int -> String -> String
cifrar n = map (shiftChar (n `mod` 26))
-- El n `mod` 26 es para tener un desplazamiento dentro del alfabeto

-- descifrar aplica el desplazamiento inverso
descifrar :: Int -> String -> String
descifrar n = cifrar ((-n) `mod` 26)
-- Por ejemplo, si n = 3 entonces (-3) `mod` 26 = 23