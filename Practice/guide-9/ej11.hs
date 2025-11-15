elem' :: Eq a => a -> [a] -> Bool
elem' x = foldr (\y acc -> (y == x) || acc) False
-- f 1 (f 2 (f 3 (f 4 z)))
-- f1 (f2 (f3 (4==3 || False)))
-- f1 (f2 (3==3 || 4==3 || False))
-- f1 (2==3 || 3==3 || 4==3 || False)
-- (1==3) || ((2==3) || ((3==3) || ((4==3) || False)))


main :: IO()
main = do
    print (elem' 3 [1,2,3,4])
    print (elem' 5 [1,2,3,4])