making_triplets :: [[Int]]
making_triplets = [[p,q,r] | p <- [1..10], q <- [1..10], r <- [1..10]]

main :: IO()
main = print (making_triplets)