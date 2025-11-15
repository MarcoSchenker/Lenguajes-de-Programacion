inserting_in_sorted_list :: Int -> [Int] -> [Int]
inserting_in_sorted_list x [] = [x]
inserting_in_sorted_list x (y:ys)
    | x <= y    = x : y : ys
    | otherwise = y : inserting_in_sorted_list x ys

insertion_sort :: [Int] -> [Int]
insertion_sort [] = []
insertion_sort (x:xs) = inserting_in_sorted_list x (insertion_sort xs)

main :: IO ()
main = print (insertion_sort [4, 2, 7, 1, 3])

-- Toma 4 y llama recursivamente a insertion_sort [2, 7, 1, 3].
-- Toma 2 y llama a insertion_sort [7, 1, 3].
-- Toma 7 y llama a insertion_sort [1, 3].
-- Toma 1 y llama a insertion_sort [3].
-- Toma 3 y llama a insertion_sort [], que devuelve [].
-- Ahora se empieza a reconstruir la lista ordenada:
-- Inserta 3 en [] → [3]
-- Inserta 1 en [3] → [1,3]
-- Inserta 7 en [1,3] → [1,3,7]
-- Inserta 2 en [1,3,7] → [1,2,3,7]
-- Inserta 4 en [1,2,3,7] → [1,2,3,4,7]