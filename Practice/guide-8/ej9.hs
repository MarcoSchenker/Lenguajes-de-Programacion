inserting_in_sorted_list :: Int -> [Int] -> [Int]
inserting_in_sorted_list x [] = [x]
inserting_in_sorted_list x (y:ys)
    | x <= y = x:y:ys
    | otherwise = y : inserting_in_sorted_list x ys

main :: IO ()
main = print (inserting_in_sorted_list 2 [1, 1, 3, 4, 6])