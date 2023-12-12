#include <deque>
#include <raylib.h>
#include <iostream>
#include <raymath.h>

using namespace std;
class Snake
{
public:
    int cellSizeSnake = 30;
    deque<Vector2> body = {Vector2{6,10}, Vector2{5,10}, Vector2{4,10}};
    deque<Vector2> bodyStart = {Vector2{6,10}, Vector2{5,10}, Vector2{4,10}};
    deque<Vector2> body2 = {Vector2{20,18}, Vector2{21,18}, Vector2{22,18}};
    Vector2 direction2 = {-1,0};
    deque<Vector2> body2Start = {Vector2{20,18}, Vector2{21,18}, Vector2{22,18}};
    Vector2 direction2Start = {-1,0};
    Vector2 direction = {1,0};
    Vector2 directionStart = {1,0};
    bool addSegment = false;

    void drawSnake(deque<Vector2> body, Color cvet)
    {
        for (unsigned int i = 0; i < body.size(); i++)
        {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{75 + x *cellSizeSnake, 75 + y*cellSizeSnake, (float)cellSizeSnake,(float)cellSizeSnake};
            DrawRectangleRounded(segment, 0.6, 6, cvet);
            
        }
    }

    void Update(Vector2 direction)
    {
        body.push_front(Vector2Add(body[0], direction));
        if (addSegment)
        {
            addSegment = false;
        }
        else
        {
            body.pop_back();
        }
    }
     void Update2(Vector2 direction2)
    {
        body2.push_front(Vector2Add(body2[0], direction2));
        if (addSegment)
        {
            addSegment = false;
        }
        else
        {
            body2.pop_back();
        }
    }

    void reset(deque<Vector2> bodyStart, Vector2 directionStart)
    {
        body = bodyStart;
        direction = directionStart;
    }
        void reset2(deque<Vector2> bodyStart2, Vector2 directionStart2)
    {
        body2 = bodyStart2;
        direction2 = directionStart2;
    }
};