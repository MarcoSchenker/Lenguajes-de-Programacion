difference :: [Int] -> [Int] -> [Int]
difference [] _ = []
difference (x:xs) ys
    | x `elem` ys = difference xs ys
    | otherwise = x : difference xs ys

main :: IO()
main = print (difference [1,5,2,7,7] [3..8])