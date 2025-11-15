module NotasPorAlumnos where
import qualified Data.Map as Map

data Student = Student
  { idNumber :: Int
  , name     :: String
  } deriving (Show, Eq)

moe :: Student
moe = Student { idNumber = 1, name = "Moe" }

averageScores:: [(Int, Int)] -> Map.Map Int Double
averageScores [] = Map.empty
averageScores scores = Map.map average groupedScores
  where
    groupedScores = foldr insertScore Map.empty scores

    insertScore (studentId, score) acc =
      Map.insertWith (++) studentId [score] acc

average:: [Int] -> Double
average xs = fromIntegral (sum xs) / fromIntegral (length xs)

main :: IO ()
main = print (averageScores [(1, 8), (2, 9), (2, 8), (1, 9)])