octal_number :: [Int] -> Int
octal_number digits = sum (zipWith (*) digits powersOf8)
  where
    powersOf8 = [8^n | n <- [0..]]

main :: IO ()
main = print (octal_number [7,2,1])  -- 7*8^0 + 2*8^1 + 1*8^2 = 87