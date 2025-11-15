making_triplets :: [[Int]]
making_triplets = [[p,q,r] | p <- [1..10], q <- [1..10], r <- [1..10]]

rectangle_triangles :: [[Int]] -> [[Int]]
rectangle_triangles list = 
      [ [p,q,r] | [p,q,r] <- list,
       let p2 = p*p,
       let q2 = q*q,
       let r2 = r*r,
       p2 + q2 == r2 || p2 + r2 == q2 || q2 + r2 == p2
  ]

perimeter :: [[Int]] -> [[Int]]
perimeter triangles = filter(\t -> sum t == 24) triangles

main :: IO()
main = print (perimeter(rectangle_triangles making_triplets))
