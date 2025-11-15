collatz :: Int -> [Int]
collatz x
    | x==1 = [x]
    | (x `mod` 2) == 0 = x : collatz (x`div`2)
    | otherwise = x : collatz (3*x+1)

making_list_of_bigger_than_ten :: [Int]
making_list_of_bigger_than_ten = [ n | n <- [1..100], length (collatz n) > 10 ]

main :: IO()
main = print(making_list_of_bigger_than_ten)