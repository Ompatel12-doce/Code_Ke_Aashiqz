#include <bits/stdc++.h>
#include <conio.h>    // for kbhit(), getch()
#include <windows.h>

using namespace std;

#define MAX_LENGTH 1000

// Directions
const char DIR_UP = 'U';
const char DIR_DOWN = 'D';
const char DIR_LEFT = 'L';
const char DIR_RIGHT = 'R';

// This variable declaration is to determine the console width.It is defined globally to avoid any variable overlapping.
int consoleWidth, consoleHeight;

void initScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

struct Point
{
    int xCoord;
    int yCoord;
    Point() {}
    Point(int x, int y) : xCoord(x), yCoord(y) {}
};

class Snake
{
    int length;
    char direction;

public:
    Point body[MAX_LENGTH];

    Snake(int x, int y)
    {
        length = 3;
        body[0] = Point(x, y);
        direction = DIR_RIGHT;
    }

    int getLength()
    {
        return length;
    }

    void changeDirection(char newDirection)
    {
        if (newDirection == DIR_UP && direction != DIR_DOWN)
            direction = newDirection;
        else if (newDirection == DIR_DOWN && direction != DIR_UP)
            direction = newDirection;
        else if (newDirection == DIR_LEFT && direction != DIR_RIGHT)
            direction = newDirection;
        else if (newDirection == DIR_RIGHT && direction != DIR_LEFT)
            direction = newDirection;
    }

    bool move(Point food, Point &oldTail, bool &ateFood)
    {
        oldTail = body[length - 1];


        for (int i = length - 1; i > 0; i--)
        {
            body[i] = body[i - 1];
        }
        switch (direction)
        {
        case DIR_UP:
            body[0].yCoord--;
            break;
        case DIR_DOWN:
            body[0].yCoord++;
            break;
        case DIR_RIGHT:
            body[0].xCoord++;
            break;
        case DIR_LEFT:
            body[0].xCoord--;
            break;
        }

        for (int i = 1; i < length; i++)
        {
            if (body[0].xCoord == body[i].xCoord && body[0].yCoord == body[i].yCoord)
                return false;
        }

        ateFood = false;
        
        if (food.xCoord == body[0].xCoord && food.yCoord == body[0].yCoord)
        {
            body[length] = oldTail;
            length++;
            ateFood = true;
        }

        return true;
    }
};

class Board
{
    Snake *snake;
    const char SNAKE_BODY = 'O';
    Point food;
    const char FOOD = 'X';
    int score;

public:
    Board()
    {
        spawnFood();
        int startX = consoleWidth / 2;
        int startY = consoleHeight / 2;
        if(startX <= 0) startX = 1;
        if(startY <= 1) startY = 2;
        snake = new Snake(startX, startY);
        score = 0;

        drawBorder();

        gotoxy(snake->body[0].xCoord, snake->body[0].yCoord);
        cout << SNAKE_BODY;
        gotoxy(food.xCoord, food.yCoord);
        cout << FOOD;
        displayCurrentScore();
    }

    ~Board()
    {
        delete snake;
    }

    int getScore()
    {
        return score;
    }

    void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    void drawBorder()
    {
       
        for (int x = 0; x < consoleWidth; x++)
        {
            
            gotoxy(x, 1);
            cout << "#";
        
            gotoxy(x, consoleHeight - 2);
            cout << "#";
        }

       
        for (int y = 1; y < consoleHeight - 1; y++)
        {
            
            gotoxy(0, y);
            cout << "#";
            
            gotoxy(consoleWidth - 1, y);
            cout << "#";
        }
    }

    void spawnFood()
    {

        int x = 1 + rand() % (consoleWidth - 2);
        int y = 2 + rand() % (consoleHeight - 4);
        food = Point(x, y);
    }

    void displayCurrentScore()
    {
        string scoreStr = "Current Score: " + to_string(score);
        int pos = (consoleWidth - scoreStr.size()) / 2;
        gotoxy(pos, 0);
        cout << scoreStr;
    }

   
    bool update()
    {
        Point oldTail;
        bool ateFood;
        bool isAlive = snake->move(food, oldTail, ateFood);
        if (!isAlive)
            return false;

    
        Point head = snake->body[0];
        if (head.xCoord <= 0 || head.xCoord >= consoleWidth - 1 ||
            head.yCoord <= 1 || head.yCoord >= consoleHeight - 2)
        {
            return false;
        }

       
        if (!ateFood)
        {
            gotoxy(oldTail.xCoord, oldTail.yCoord);
            cout << " ";  // Overwrite with blank space
        }
        
        gotoxy(head.xCoord, head.yCoord);
        cout << SNAKE_BODY;

       
        if (ateFood)
        {
            score += 10;
            spawnFood();
            gotoxy(food.xCoord, food.yCoord);
            cout << FOOD;
        }

        
        displayCurrentScore();

        return true;
    }

    
    void getInput()
    {
        if (kbhit())
        {
            int key = getch();
            if (key == 'w' || key == 'W')
                snake->changeDirection(DIR_UP);
            else if (key == 'a' || key == 'A')
                snake->changeDirection(DIR_LEFT);
            else if (key == 's' || key == 'S')
                snake->changeDirection(DIR_DOWN);
            else if (key == 'd' || key == 'D')
                snake->changeDirection(DIR_RIGHT);
        }
    }
};

int main()
{
    srand(time(0));
    initScreen();

    bool restart = false;
    do {
        
        system("cls");

        Board *board = new Board();

        
        while (board->update())
        {
            board->getInput();
            Sleep(100);  // Adjust speed as necessary
        }

       
        board->gotoxy(0, consoleHeight - 1);
        cout << "Game Over! Press R to restart or any other key to exit.";
        char key = getch();
        if (key == 'r' || key == 'R')
            restart = true;
        else
            restart = false;

        delete board;
    } while (restart);

    return 0;
}
