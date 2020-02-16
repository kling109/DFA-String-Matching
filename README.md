# String Classifiers

Trevor Kling

CPSC 402: Compiler Construction

Assignment 1

## Introduction

Contains implementations of DFA's to recognize various string patterns in C++.
Program takes a file as input and identifies the matching locations in constant
time.

## Running Instructions

To run the programs, navigate to the relevant directory and run `g++ *.cpp`.
Then, run `./a.out` and input a path to the desired file when prompted.  The
program includes an `example_*.txt` for each DFA to demonstrate functionality.

## Known Issues

Tested on Ubuntu Subsystem for Windows and OnlineGDB web compiler.  Can segment
fault in response to improper file path inputs.  If the program segment faults,
try moving the desired file into the folder and using the explicit name of the
file, i.e. `example.txt`.
