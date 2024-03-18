```
   __  ___     __  __    __  __                    __      _                      
  /  |/  /__ _/ /_/ /_  / /_/ /  ___   __ _  ___ _/ /_____(_)_ __  ___ ___ ____ __
 / /|_/ / _ `/ __/ __/ / __/ _ \/ -_) /  ' \/ _ `/ __/ __/ /\ \ / / _ `/ // / // /
/_/  /_/\_,_/\__/\__/  \__/_//_/\__/ /_/_/_/\_,_/\__/_/ /_//_\_\  \_, /\_,_/\_, / 
                                                                 /___/     /___/  
```
A Command Line based software which does matrix computations easily

## Features
- I/O of matrix from and to a file
- Determinant
- Minor
- Cofactor
- Adjoint
- Inverse
- Linear equation solver
- Displaying the matrix

## Installation
- MAC OS IS PREFERRED
- Install the ```main.c``` file and type on the terminal as follows
```
% gcc -o main main.c
```
- Then run the program as follows
```
% ./main
```
- The program requires input and output files in the same branch
- Ideal enviroment for the code is VS Code on a mac

## Screenshots
<p>
   <img src="https://github.com/ps-1305/matt-the-matrix-guy/blob/main/screenshots/ics-screenshot-1.png" height=700 width=1000>
   <img src="https://github.com/ps-1305/matt-the-matrix-guy/blob/main/screenshots/ics-screenshot-3.png" height=300 width=550>
   <img src="https://github.com/ps-1305/matt-the-matrix-guy/blob/main/screenshots/ics-screenshot-4.png" height=300 width=450>
   <img src="https://github.com/ps-1305/matt-the-matrix-guy/blob/main/screenshots/ics-screenshot-2.png" height=300 width=1000>
</p>


## Limitations
- Recursive determinant functions limits the dimension of the matrix upto a realistic maximum of 20x20
- Non-square matrix is not supported currently
- Linear equations possible upto only 3 variables
- Minor inconvinience, Some functions like ```system("clear")``` work for UNIX-like systems and not windows, for windows it would be ```system("cls")``` which is not present in the code; It would affect the code visually

## Dependencies
- User input during linear equations should be specific
- Constant user input required for choices
- Correct filenames should be entered

## Further scope 
- More efficient nxn determinant algorithms like LU decomposition
- A proper Command Line UI using ```<ncurses.h>```
- String tokens being used for parsing/lexing for linear equations
- Eigenvalues, Eigenvectors and Diagonalisation of matrix
- matrixScript - an interpreter language for matrix manipulations 
