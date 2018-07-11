#!/usr/bin/env stack


-- Name: Siddharth Chugh
-- Student Number: 301236542
-- CMPT 383 Assignment 4
-- This program takes a json file as an input and spits out an html document
-- Steps to load a file
-- :main filename.json

import System.Environment
import System.IO
import System.Directory
import System.FilePath
import Data.List




main = do
    args <- getArgs
    case args of 
      [file] -> do
        x <- openFile file ReadMode
        contents <- hGetContents x
        y <- openFile "temp.html" WriteMode
        hPutStrLn y (contents)
        hClose x
        hClose y
      _ -> putStrLn "Wrong number of arguments"

