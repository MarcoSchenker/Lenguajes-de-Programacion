fibonacci :: Int -> Int
fibonacci n
    | n == 0 = 0
    | n == 1 = 1
    | otherwise = fibonacci (n-2) + fibonacci (n-1)

writing_fibonacci :: Int -> [Int]
writing_fibonacci n = list_fibonacci
    where
        list_fibonacci = map fibonacci [0..n]

main :: IO ()
main = print (writing_fibonacci 5)