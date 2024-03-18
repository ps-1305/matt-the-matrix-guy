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
- Install the ```main.c``` file and type on the terminal as follows
```
% gcc -o main main.c
```
- Then run the program as follows
```
% ./main
```
- Ideal enviroment for the code is VS Code on a mac

## Limitations
- Recursive determinant functions limits the dimension of the matrix upto a realistic maximum of 20x20
- Non-square matrix is not supported currently
- Linear equations possible upto only 3 variables

## Dependencies
- User input during linear equations should be specific
- Constant user input required for choices
- Correct filenames should be entered

## Further scope 
- More efficient nxn determinant algorithms like LU decomposition
- A proper Command Line UI using ```<ncurses.h>```
- String tokens being used for parsin/lexing for linear equations
- Eigenvalues, Eigenvectors and Diagonalisation of matrix
