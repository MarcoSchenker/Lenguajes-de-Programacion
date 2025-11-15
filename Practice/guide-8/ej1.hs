union :: [Int] -> [Int] -> [Int]
union [] ys = ys
union (x:xs) ys
    | x `elem` ys = union xs ys
    | otherwise   = x : union xs ys

main :: IO ()
main = print (union [1, 2, 3] [3, 1, 4, 5])