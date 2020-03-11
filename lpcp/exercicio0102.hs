-----------------
-- exercio0102.hs
-----------------

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
funct :: Int -> Int -> Int -> Bool
funct x y z
  | not (y >= x) = True