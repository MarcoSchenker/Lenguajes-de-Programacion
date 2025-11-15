encode :: String -> [(Int, Char)]
encode [] = []
encode (c:cs) = (count, c) : encode rest
  where
    (same, rest) = span (== c) cs
    count = 1 + length same


data Element = One    Char
             | Repeat Char Int
             deriving (Show)

encode2 :: String -> [Element]
encode2 x = [ if n == 1 then One c else Repeat c n
            | (n, c) <- encode x ]

main :: IO()
main = print (encode2 "aaabbbccdaa")