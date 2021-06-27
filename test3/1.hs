trunRoot :: Int -> Int
trunRoot 0 = 0
trunRoot 1 = 1
trunRoot x = truncate(sqrt(fromIntegral x))



lister :: Int -> [Int]
lister x = trunRoot x : trunRoot ( x - (trunRoot x)^2 ) : trunRoot(( x - (trunRoot x) ) - (trunRoot ( x - (trunRoot x) ))^2 ) : trunRoot ( ( trunRoot ( x - (trunRoot x) ) ) - (trunRoot( trunRoot ( x - (trunRoot x) ) ))^2) : []
