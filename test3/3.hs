data Nat = Zero | Succ Nat

power :: Float -> Nat -> Float
power x Zero = 1.0
power x (Succ n) 
    | n > 0 = x * power x n
    | n < 0 = power x n / x 

plus :: Nat -> Nat -> Nat
plus m Zero = m 
plus m (Succ (n)) = Succ (plus m n)

substract :: Nat -> Nat -> Nat
substract m Zero = m
substract m (Succ (n)) = Succ (substract m n)


mult :: Nat -> Nat -> Nat 
mult m Zero = Zero
mult m (Succ n) = plus m (mult m n) 
