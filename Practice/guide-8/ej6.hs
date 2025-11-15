base_number :: Int -> [Int] -> Int
base_number base digits
    | base > 10 = 0
    | otherwise = sum (zipWith (*) digits powersOfBase)
    where
        powersOfBase = [base^n | n <- [0..]]

main :: IO ()
main = print (base_number 11 [7,2,1])