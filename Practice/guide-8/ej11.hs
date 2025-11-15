merge_sort :: [Int] -> [Int] -> [Int]
merge_sort [] b = b
merge_sort a [] = a
merge_sort (a:as) (b:bs)
    | a >= b = b : merge_sort (a:as) bs
    | otherwise = a : merge_sort as (b:bs)

main :: IO ()
main = print(merge_sort [1,4,7,9] [2,5,6,8])