#include "food.h"
#include "walls.h"
#include <cmath>
#include "snakeBot.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool toggle= 1;
int ichecker;
bool Paused2 = false;
class Game
{
    int i;
    friend class Snake;
    friend class Food;
    public:
    Snake snake;
    Snake snake2;
    Walls wall;
    Food food = Food(snake.body, wall.wall);
    bool running = true;
    int score = 0;
    int score2 = 0;
    Sound eatFoodSound;
    Sound wallCollideSound;
    Color darkGreen = {43, 51, 24, 255};
    Color customRed = {255,0,0 ,255};


    Game()
    {
        InitAudioDevice();
        eatFoodSound = LoadSound("EatFood.wav");
        wallCollideSound = LoadSound("WallCollide.wav");
    }

    ~Game()
    {
        UnloadSound(eatFoodSound);
        UnloadSound(wallCollideSound);
        CloseAudioDevice();
    }
    void changeFoodPos()
    {
        food.position = food.GenerateRandomPos(snake.body,  wall.wall);
    }
    void Draw(int i)
    {
        snake.drawSnake(snake.body, customRed);
        snake2.drawSnake(snake2.body2, darkGreen);
        wall.drawWall(i);
        food.drawFood();
    }

    void Update()
    {
        if(running){
        snake.Update(snake.direction);
        snake2.Update2(snake2.direction2);
        checkCollisionWithFood();
        checkCollisionWithEdges();
        checkCollisionWithTail();
        checkCollisionWithWalls();
        checkCollisionWithFood2();
        checkCollisionWithEdges2();
        checkCollisionWithTail2();
        checkCollisionWithWalls2();
        checkCollisionWithSnake();
        snakeAI();
        win();
        }
    }

    void checkCollisionWithFood()
    {
        if(Vector2Equals(snake.body[0], food.position))
        {
            food.position = food.GenerateRandomPos(snake.body,  wall.wall);
            snake.addSegment = true;
            score ++;
            if(toggle)
        {
            PlaySound(eatFoodSound);
        }
        }
    }
        void checkCollisionWithFood2()
    {
        if(Vector2Equals(snake2.body2[0], food.position))
        {
            food.position = food.GenerateRandomPos(snake2.body2,  wall.wall);
            snake2.addSegment = true;
            score2 ++;
            if(toggle)
        {
            PlaySound(eatFoodSound);
        }
        }
    }
    void checkCollisionWithEdges()
    {
        if(snake.body[0].x == cellCount || snake.body[0].x == -1)
        {
            resetSnake();
        }
        if(snake.body[0].y == cellCount || snake.body[0].y == -1) 
        {
            resetSnake();
        }
    }
        void checkCollisionWithEdges2()
    {
        if(snake2.body2[0].x == cellCount || snake2.body2[0].x == -1)
        {
            resetSnake2();
        }
        if(snake2.body2[0].y == cellCount || snake2.body2[0].y == -1) 
        {
            resetSnake2();
        }
    }

    void gameOver()
    {

        snake.reset(snake.bodyStart, snake.directionStart);
        snake2.reset2(snake2.body2Start, snake2.direction2Start);
        food.position = food.GenerateRandomPos(snake.body, wall.wall);
        running = false;
        score = 0;
        score2 = 0;
        if(toggle)
        {
        PlaySound(wallCollideSound);
        }
    }
    void resetSnake()
    {
                snake.reset(snake.bodyStart, snake.directionStart);
                      if(toggle)
        {
        PlaySound(wallCollideSound);
        }
    }
    void resetSnake2()
    {
                snake2.reset2(snake2.body2Start, snake2.direction2Start);
                      if(toggle)
        {
        PlaySound(wallCollideSound);
        }
    }
    void win()
    {
        if (score == 20 or score2 == 20)
         {
            running = false;
            Paused2 = 1;        
         }

    }
    void checkCollisionWithSnake()
    {
        if (snake.body[0].x == snake2.body2[0].x and snake.body[0].y == snake2.body2[0].y)  
        { 
            resetSnake();
            resetSnake2();
        }
        else if (elementInDeque(snake.body[0], snake2.body2))
        {
            resetSnake();
        }
        else if(elementInDeque(snake2.body2[0], snake.body))
        {
            resetSnake2();
        }
    }
    void checkCollisionWithTail()
    {
        deque<Vector2> headlessBody  = snake.body;
        headlessBody.pop_front();
        if (elementInDeque(snake.body[0], headlessBody))
        {
            resetSnake();
        }
    }
        void checkCollisionWithTail2()
    {
        deque<Vector2> headlessBody  = snake2.body2;
        headlessBody.pop_front();
        if (elementInDeque(snake2.body2[0], headlessBody))
        {
            resetSnake2();
        }
    }

    void checkCollisionWithWalls() {

        if (elementInDeque(snake.body[0], wall.wall))
        {
            resetSnake();
        }
        }
         void checkCollisionWithWalls2() {

        if (elementInDeque(snake2.body2[0], wall.wall))
        {
            resetSnake2();
        }
        }
        void snakeAI()
        {
            if(ichecker == 2)
            {
            bool used[30][30] = {}; 
            queue<pair<int,int>> q; 
            int x0 = snake2.body2[0].x;
            int y0 = snake2.body2[0].y; 
            int x1 = food.get().x; 
            int y1 = food.get().y; 

            q.push(make_pair(x0, y0));
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 30; ++j) {
                    used[i][j] = 0;
                 }
            }
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 30; ++j) {
                    if(elementInDeque({i,j}, wall.wall))
                    used[i][j] = 1;
                }
            }            
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 30; ++j) {
                    if(elementInDeque({i,j}, snake2.body2))
                    used[i][j] = 1;
                }
            }
                         for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 30; ++j) {
                    if(elementInDeque({i,j}, snake.body))
                    used[i][j] = 1;
                }
            }

            pair<int, int> p[30][30];
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == x1 && y == y1) { 
                    break;
                }
                const int dx[4] = {-1, 1, 0, 0}; 
                const int dy[4] = {0, 0, -1, 1};
                for(int dir = 0; dir < 4; ++dir) { 
                    int new_x = x + dx[dir];
                    int new_y = y + dy[dir];
                    if(new_x >= 0 && new_x < 30 && new_y >= 0 && new_y < 30 && !used[new_x][new_y]) {
                        p[new_x][new_y] = {x, y};
                        q.push(make_pair(new_x, new_y));
                        used[new_x][new_y] = true;
                    }
                }
            }
            vector<pair<int, int>> path; 
            int xq = x1, yq = y1;
            while(!(xq == x0 && yq == y0)) { 
                path.push_back(make_pair(xq, yq));
                int px = p[xq][yq].first;
                int py = p[xq][yq].second;
                xq = px;
                yq = py;
            }
            reverse(path.begin(), path.end());


            if(path[0].first or path[0].second)
            {
            snake2.direction2.x = path[0].first - snake2.body2[0].x;
            snake2.direction2.y = path[0].second - snake2.body2[0].y;
            }
            }
        }
};