myMap :: (a -> b) -> [a] -> [b]
myMap f xs = [ f x | x <- xs ]

main :: IO ()
main = do
    print (myMap length ["Hola", "mundo"])
    print (map length ["Hola", "mundo"])