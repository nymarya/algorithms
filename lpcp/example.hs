-------------
-- example.hs
-------------

{- aula 1 -}

answer :: Int
answer = 42

square :: Int -> Int
square x = x * x

allEqual :: Int -> Int -> Int -> Bool
allEqual m n p = (m==n) && (n==p)

maxi :: Int -> Int -> Int
maxi m n
  | m >= n = m
  | otherwise = n

{- aula 2-}
vendas :: Int -> Int
vendas x
  | x == 0 = 12
  | x == 1 = 20
  | x == 2 = 18
  | x == 3 = 25
  | otherwise = 0

totalvendas :: Int -> Int
totalvendas x
  | x == 0 = vendas 0 
  | otherwise = totalvendas (x-1) + vendas x

maxvendas :: Int -> Int
maxvendas n
  | n == 0 = vendas 0
  | otherwise = maxi (maxvendas (n-1)) (vendas n)
