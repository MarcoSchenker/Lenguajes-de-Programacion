intersection :: [Int] -> [Int] -> [Int]
intersection [] _ = []
intersection (x:xs) ys
    | x `elem` ys = x : intersection xs ys
    | otherwise = intersection xs ys

main :: IO ()
main = print (intersection [1,5,2,7,7] [3..8])

other_intersection :: [Int] -> [Int] -> [Int]
other_intersection xs ys = [y | y <- ys, y `elem` xs] 