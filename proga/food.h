#include <iostream>
#include <raylib.h>

int cellSize = 30;
int cellCount = 30;
int offset = 75;
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};
class Food {
    friend  class Snake;
    friend class Walls;
    public:
    Vector2 position;
    Texture2D texture;
    Food (deque<Vector2> snakeBody, deque<Vector2> wall)
    {
        Image image = LoadImage("food_apple.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    } 
    ~Food()
    {
        UnloadTexture(texture);
    }
    Vector2 get()
    {
        return position;
    }
void drawFood()
{
    DrawTexture(texture, offset+ position.x * cellSize, offset+ position.y *cellSize, WHITE);
}

Vector2 GenerateRandomCell()
{
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x,y};
}

Vector2 GenerateRandomPos(deque<Vector2> snakeBody, deque<Vector2> wall)
{
    Vector2 position = GenerateRandomCell();
    while(elementInDeque(position, snakeBody) || elementInDeque(position, wall))
    {
        position = GenerateRandomCell();
    }
    return position;
}
};