-----------------
-- exercio0102.hs
-----------------
import Data.Char 

{- 1 -}

vendas :: Int -> Int
vendas x
  | x == 0 = 12
  | x == 1 = 20
  | x == 2 = 18
  | x == 3 = 25
  | otherwise = 0

semZeroNoPeriodo :: Int -> Bool
semZeroNoPeriodo x
  | x == 0 && not (vendas x == 0) = True
  | x == 0 && (vendas x == 0) = True
  | vendas x == 0 = False
  | otherwise = semZeroNoPeriodo( x - 1) 

{- 2 -}
functx :: Int -> Int -> Int -> Bool
functx x y z
  | x > z = True
  | y >= x = False
  | otherwise = True

funct :: Int -> Int -> Int -> Bool
funct x y z
  | x <= z && y >= x = False
  | otherwise = True

{- 3 -}
dels = ord 'A' - ord 'a'
converte :: Char -> Char
converte x
  | isLower x = chr (ord x + dels)
  | otherwise = x

{- 4 -}
infix 8 &-
{- 10 &- 5 &- 2  = 4 (infixl 6) -}
{- 10 &- 5 &- 2  = 8 (infixr 6) -}
{- 10 &- 3 * 2  = 12 (infix 6) -}
{- 10 &- 3 * 2  = 12 (infix 8) -}
(&-) :: Int -> Int -> Int
x &- y = 2*y  

{- 5 -}
maxVenda :: [Int] -> [Int]
maxVenda [a] = [a] 
maxVenda [a:x]