rotateLeft :: Int -> [a] -> [a]
rotateLeft _ [] = []
rotateLeft n list =
  let len = length list
      delta = n `mod` len
  in drop delta list ++ take delta list
  -- drop delta devuelve la lista sin los 
  -- primeros delta elementos, y take delta
  -- devuelve los primeros delta elementos

main :: IO ()
main = putStrLn (rotateLeft 3 "abcdefghijklmnop")