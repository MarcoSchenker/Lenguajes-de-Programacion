mcd :: Int -> Int -> Int
mcd b 0 = b
mcd a b
    | a < b = 0
    | otherwise = mcd b resto
    where 
        resto = a `mod` b

main :: IO()
main = print (mcd 48 36) -- 12