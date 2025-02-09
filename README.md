# Code_Ke_Aashiqz
Group project of 'Snake Game' developed by Code_Ke_Aashiqz.. The respective group members are : 1) Pranamya Sanghvi 2) Kirtan Kamani 3) Om Patel 4) Konark Dixit



# Snake Game 

This is a console-based Snake Game implemented in C++ (with Object Oriented Programming) .The snake moves in a defined boundary, consumes food to grow in size such that the speed decreases on increasing size. On encountering collision with the boundary, the game ends. 

## Features

- Snake movement using W(Forward), S(Downwards), A(Leftwards) and D(Rightwards)
- Random food generation is done with the help of srand() function.
- Area is confined and not the full terminal.
- Score is displayed after every defeat such that pressing R restarts the game.

## Controls

- *W* - Move Up
- *S* - Move Down
- *A* - Move Left
- *D* - Move Right
- *R* - Restart game after Game Over

## Installation & Usage

1. Clone the repository:
   (https://github.com/Ompatel12-doce/Code_Ke_Aashiqz.git)
   
2. Compile the code using a C++ compiler:
   g++ finalgame.cpp -o finalgame.exe
3. Run the game:
   .\finalgame.exe

## Dependencies

- Windows OS (uses `<windows.h>` for console manipulation)
- C++ Standard Library

## Notes

- The game runs only on a Windows command prompt.
- Uses `conio.h` for real time keyboard input.
- `windows.h` is required for cursor movement and screen updates.

## Difficulties

- While making game, it was very diificult for us to have a background.
- We wanted to have an obstacle 'bomb' such that on encountering it, the snake dies and the game ends.

## Steps to make this game

- After having a detailed talk with Ankush sir regarding how to tackle this problem since it was our first time making a game, he suggested that how we should tackle this problem.
- The first step was to make a point move on a horizontal line.
- The next step was how to move the point on a 2D matrix.
- The next step was how we can take the input from the user in real time.
- After doing that, it was the time we spawn food randomly in the grid(we used srand() function for that).
- After that, we tackled how we could increase the size of the snake after it ate food.
- The last and the perhaps the most important step was that our snake dies and the game ends once it collides with the wall.
