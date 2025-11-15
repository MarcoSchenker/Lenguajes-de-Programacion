simetric_diference :: [Int] -> [Int] -> [Int]
simetric_diference _ [] = []
simetric_diference xs (y:ys) 
    | y `elem` xs = simetric_diference xs ys
    | otherwise = y: simetric_diference xs ys

main :: IO()
main = print (simetric_diference [1,5,2,7,7] [3..8])

-- [3,4,5,6,7,8] - [1,5,2,7,7] = [3,4,6,8]