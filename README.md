# Code_Ke_Aashiqz
Group project Developed by 🚀 Code_Ke_Aashiqz.. The respective group members are : 1) Pranamya Sanghvi 2) Kirtan Kamani 3) Om Patel 4) Konark Dixit



# Snake Game 

This is a console-based Snake Game implemented in C++ with an additional bomb feature. The snake moves in a confined area, consumes food to grow in size, and avoids self-collisions and border collisions. 

## Features

- Classic snake movement (up, down, left, right)
- Food spawns randomly to increase the snake's length and score
- Bomb spawns randomly and ends the game upon collision
- Borders to contain gameplay
- Score display and game restart functionality

## Controls

- `W` - Move Up
- `S` - Move Down
- `A` - Move Left
- `D` - Move Right
- `R` - Restart game after Game Over

## Installation & Usage

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/snake-game-with-bomb.git
   cd snake-game-with-bomb
   ```
2. Compile the code using a C++ compiler (MinGW recommended for Windows):
   ```sh
   g++ snake_game.cpp -o snake_game.exe
   ```
3. Run the game:
   ```sh
   ./snake_game.exe
   ```

## Dependencies

- Windows OS (uses `<windows.h>` for console manipulation)
- C++ Standard Library

## Notes

- The game runs in a Windows command prompt.
- Uses `conio.h` for non-blocking keyboard input.
- `windows.h` is required for cursor movement and screen updates.
