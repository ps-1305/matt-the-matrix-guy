# matt-the-matrix-guy
A CLI based virtual assistant that takes you through matrix computations easily

## Dependency : Ncurses - Setup and Running the Program
### 1. MacOS installation
- First we will find out our compiler's includePath
```
gcc -x c -v -E /dev/null
```

- Then we will install ncurses using brew
```
brew install ncurses
```

- Finally we copy the ncurses file from brew path to our includePath
```
cp -R /opt/homebrew/Cellar/ncurses/6.4 /Library/Developer/CommandLineTools/usr/include
```

This will install NCurses and set it on the user path

To run the program we need to enter this in terminal (We need to link the ncurses library to our program)
```
gcc -o <filename.out> <filename.c> -lncurses && ./<filename.out>
```

### 2. Further scope and compatibility issues
- Windows support can have ``` <conio.h> ```
