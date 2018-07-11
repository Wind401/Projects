#!/usr/bin/env stack
--Question 1

-- returns the number of emirps less than, or equal to, n.

count_emirps :: Int -> Int
count_emirps n
  | n < 13    = 0
  | isEmirp n = 1 + count_emirps (n - 1)
  | otherwise = count_emirps (n - 1)

-- Helper Function
-- Returns true if n is an emirp

isEmirp :: Int -> Bool
isEmirp n = n /= r && isPrime n && isPrime r
            where r = reverseInt n

-- Helper Function
-- Returns true if n is prime

isPrime :: Int -> Bool
isPrime n
  | n < 2     = False
  | otherwise = smallestDivisor n == n

-- Helper Function
-- Returns the smallest divisor of n

smallestDivisor :: Int -> Int
smallestDivisor n
  | n == 0    = 0
  | n == 1    = 1
  | otherwise = head (dropWhile (\x -> n `mod` x /= 0) [2..n])

--Helper Function
-- Reverses a given integer

reverseInt :: Int -> Int
reverseInt x = read . reverse . show $ x

--Question 2

--returns the item in seq that maximizes function

greatest :: (a -> Int) -> [a] -> a
greatest f seq
  | singleton seq = head seq
  | otherwise     = greater f (head seq) (greatest f (tail seq))

--Helper Function
-- Returns the greater number

greater :: (a -> Int) -> a -> a -> a
greater f a b
  | f a > f b = a
  | otherwise = b

--Helper Function
-- Tests whether a list has only one element
singleton :: [a] -> Bool
singleton lst = length lst == 1

-- Question 3
-- Returns True when x is 0 or 1, and False otherwise

is_bit :: Int -> Bool
is_bit x = x == 0 || x == 1

-- Question 4

-- Returns a sequence of bits that is the same as x, except 0s become 1s and 1s become 0s
-- a

invert_bits1 :: [Int] -> [Int]
invert_bits1 seq
  | null seq      = seq
  | singleton seq = [flip_bit (head seq)]
  | otherwise     = [flip_bit (head seq)] ++ invert_bits1 (tail seq)

-- b

invert_bits2 :: [Int] -> [Int]
invert_bits2 seq = map (\x -> flip_bit x) seq

-- c

invert_bits3 :: [Int] -> [Int]
invert_bits3 seq = [flip_bit n | n <- seq]

--Helper Function

--Flips bit

flip_bit :: Int -> Int
flip_bit x
  | x == 0    = 1
  | x == 1    = 0
  | otherwise = error ("Bit must be either 0 or 1, is " ++ show x)


--Question 5

data Bit = Zero | One
    deriving (Show, Eq)

-- Flips all the bits in the input list

invert :: [Bit] -> [Bit]
invert bits = [flipBit n | n <- bits]

--Helper Function

--Flips Bit

flipBit :: Bit -> Bit
flipBit b = if b == One then Zero else One

-- Question 6

-- Returns a list of Bit lists representing all possible bit sequences of length n

all_bit_seqs :: Int -> [[Bit]]
all_bit_seqs n = [bitSeq x n | x <- [0..(2^n - 1)]]

--Helper Function

-- Returns the Bit sequence for integer n of the given length

bitSeq :: Int -> Int -> [Bit]
bitSeq n length = [bitValue (floor (realToFrac n / 2^i) `mod` 2) | i <- [length - 1, (length - 2)..0]]

-- Returns the Bit value of the integer bit
bitValue :: Int -> Bit
bitValue x = if x == 1 then One else Zero

--Question 7

data List a = Empty | Cons a (List a)
    deriving Show

-- Converts a regular Haskell list to a List a

toList :: [a] -> List a
toList s
  | null s      = Empty
  | otherwise   = Cons (head s) (toList (tail s))

--Question 8

-- Converts a List a to a regular Haskell list

toHaskellList :: List a -> [a]
toHaskellList Empty             = []
toHaskellList (Cons first rest) = [first] ++ toHaskellList rest

--Question 9

-- Returns a new List a that consists of all the elements of A followed by all the elements of B

append :: List a -> List a -> List a
append Empty b          = b
append a Empty          = a
append (Cons a Empty) b = Cons a b
append a b              = append (allButLast a) (append (lastList a) b)

--Helper Function
-- Returns the last item in the List a, e.g. (Cons 1 (Cons 2 Empty)) -> Cons 2 Empty
lastList :: List a -> List a
lastList Empty              = Empty
lastList (Cons first Empty) = Cons first Empty
lastList (Cons _ rest)      = lastList rest

--Helper Function
-- Returns all items except the last one in the List a, e.g. (Cons 1 (Cons 2 (Cons 3 Empty))) -> Cons 1 (Cons 2 Empty)
allButLast :: List a -> List a
allButLast Empty             = Empty
allButLast (Cons _ Empty)    = Empty
allButLast (Cons first rest) = Cons first (allButLast rest)

--Question 10

-- Returns a List a that is the same as L but all items satisfying f (i.e. for which f returns True) have been removed

removeAll :: (a -> Bool) -> List a -> List a
removeAll _ Empty             = Empty
removeAll f (Cons first rest) = if f first then removeAll f rest
                                else Cons first (removeAll f rest)