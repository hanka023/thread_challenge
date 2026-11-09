
# THREAD CHALLENGE

*this project is a II.(and final) part of my recovery from minishell*


## Challenge

you have to take one task - whitch take a lot of time to computing - and divide the work to multiple threads

[i choose n_queen problem]


you have to write your code with no AI usage as possible !



## Usage

compile: make


start: ./queen [number > 3]


example: queen 10


!!! writes only computing time + number of results for every single thread !!!


### Comparision


n_queen_reference.c  - n_queen task working with only 1 thread 

[https://github.com/tdanielsousa/42_school_new_exams_2026/tree/main/Rank_3/level2/n_queens]

compile: gcc n_queen_reference.c -o nq 

use: ./nq [number > 3]

example: ./nq 5

writes only computing time + count results, takes a little more time for computing


## Ai usage

Ai used in final state of my coding - for finding bugs: 


- Race conditions: [board] is a single shared global array overwritten concurently by all threads without per-thread isolation
- Inicialization bug - pointer (data -> i) modified only first element instead of indexing data[i]










# THREAD CHALLENGE

this project is a part of my recovery from minishell

compilation: make 


start: ./queen [number]


example: queen 10


reference: n_queen_reference.c [n_queen with only one thread]