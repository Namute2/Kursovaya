#include <iostream>
#include <raylib.h>
#include "snake.h"
using namespace std;

double lastUpdateTime = 0;
bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}
bool  elementInDeque(Vector2 element, deque<Vector2> deque)
{
    for(unsigned int i=0; i < deque.size(); i++)
    {
        if(Vector2Equals(deque[i], element))
        {
            return true;
        }
    }
    return false;
}
// bool  elementInDeque1(Vector2 element, deque<Vector2> deque)
// {
//     element.x++;
//     for(unsigned int i=0; i < deque.size(); i++)
//     {
//         if(Vector2Equals(deque[i], element))
//         {
//             return true;
//         }
//     }
    
//     return false;
// }
// bool  elementInDeque2(Vector2 element, deque<Vector2> deque)
// {
//     element.x--;
//     for(unsigned int i=0; i < deque.size(); i++)
//     {
//         if(Vector2Equals(deque[i], element))
//         {
//             return true;
//         }
//     }
//     return false;
// }
// bool  elementInDeque3(Vector2 element, deque<Vector2> deque)
// {
//     element.y++;
//     for(unsigned int i=0; i < deque.size(); i++)
//     {
//         if(Vector2Equals(deque[i], element))
//         {
//             return true;
//         }
//     }
//     return false;
// }
// bool  elementInDeque4(Vector2 element, deque<Vector2> deque)
// {
//     element.y--;
//     for(unsigned int i=0; i < deque.size(); i++)
//     {
//         if(Vector2Equals(deque[i], element))
//         {
//             return true;
//         }
//     }
//     return false;
// }