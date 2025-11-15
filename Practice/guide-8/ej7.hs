hexadecimal_number :: [Int] -> Int
hexadecimal_number digits = sum (zipWith (*) digits powersOf16)
  where
    powersOf16 = [16^n | n <- [0..]]

main :: IO ()
main = print (hexadecimal_number [7,2,1])