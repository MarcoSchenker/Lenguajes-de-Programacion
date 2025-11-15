module Books
  ( Books
  , Book(..)
  , emptyBooks
  , add
  , showBooks
  , showAuthor
  , delete
  ) where

-- Registro para un libro
data Book = Book
  { author :: String
  , title  :: String
  , pages  :: Int
  } deriving (Eq, Show)

-- Colección simple de libros
newtype Books = Books [Book]

emptyBooks :: Books
emptyBooks = Books []

-- agrega un libro (se coloca al frente)
add :: Book -> Books -> Books
add b (Books bs) = Books (b : bs)

-- formato de salida para un libro
formatBook :: Book -> String
formatBook (Book a t p) = t ++ " - " ++ a ++ " (" ++ show p ++ " pp)"

-- devuelve una cadena con todos los registros (una línea por libro)
showBooks :: Books -> String
showBooks (Books bs) = unlines (map formatBook bs)

-- devuelve una cadena con todos los libros de un autor
showAuthor :: String -> Books -> String
showAuthor auth (Books bs)
  | null matches = "No hay libros de " ++ auth
  | otherwise    = unlines (map formatBook matches)
  where
    matches = filter (\(Book a _ _) -> a == auth) bs

-- elimina todas las entradas cuyo título coincide con el dado
delete :: String -> Books -> Books
delete t (Books bs) = Books (filter (\(Book _ title' _) -> title' /= t) bs)

-- permitimos mostrar Books directamente con 'show'
instance Show Books where
  show = showBooks

main :: IO ()
main = do
  let b1 = Book "Orwell" "1984" 328
      b2 = Book "Orwell" "Animal Farm" 112
      b3 = Book "Tolkien" "The Hobbit" 310
      bs = add b3 (add b2 (add b1 emptyBooks))
  putStrLn "All books:"
  putStrLn (showBooks bs)
  putStrLn "Books by Orwell:"
  putStrLn (showAuthor "Orwell" bs)
  let bs2 = delete "1984" bs
  putStrLn "After deleting 1984:"
  putStrLn (showBooks bs2)