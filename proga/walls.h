#include <deque>
#include <raylib.h>
#include <iostream>
#include <raymath.h>
#define V Vector2

class Walls{
    public:
    deque<V> wall;
    deque<V> map1 ={V{3,3}, V{4,3}, V{5,3}, V{6,3},
    V{2,12},V{2,13},V{2,14},V{2,15},V{2,16},V{2,17},V{2,18},V{2,19},V{2,20},
    V{11,13},V{11,14},V{11,15},V{11,16},V{11,17},
    V{7,23},V{8,23},V{9,23},V{10,23},V{10,23},V{10,22},V{10,21},
    V{11,13},V{11,14},V{11,15},V{11,16},V{11,17},
    V{11,5},V{11,6},V{10,6},V{12,5},V{13,5},
    V{16,9},V{17,9},V{18,9},V{19,9},V{19,8},V{19,7},V{19,6},V{19,5},
    V{22,12},V{23,12},V{23,12},V{23,11},V{23,13},V{23,14},V{23,15},V{23,16},
    V{17,22},V{18,22}, V{19,22}, V{20,22}, V{20,21}, V{20,20},};
    deque<V> map2 ={V{11, 2}, V{12, 2}, V{13, 2}, V{14, 2}, V{15, 2}, V{16, 2}, V{17, 2}, V{18, 2}, V{19, 2}, V{20, 2}, V{21, 2},
    V{15, 5}, V{16, 5}, V{17, 5}, V{18, 5},
    V{6, 6}, V{7, 6}, V{8, 6},
    V{14, 8}, V{14, 9},
    V{16, 11}, V{17, 11}, V{18, 11}, V{19, 11}, V{19, 11},
    V{6, 23}, V{7, 23}, V{8, 23},
    V{16, 20}, V{17, 20}, V{18, 20}, V{19, 20}, V{20, 20}, V{21, 20}, V{22, 20},
    V{10, 28}, V{11, 28}, V{12, 28}, V{13, 28}, V{14, 28},
    V{18, 28}, V{19, 28}, V{20, 28}, V{21, 28}, V{22, 28},
    V{5, 11}, V{5, 12}, V{5, 13}, V{5, 14}, V{5, 15}, V{5, 16}, V{5, 17}, V{5, 18}, V{5, 19}, V{5, 20},
    V{10, 5}, V{10, 6}, V{10, 7}, V{10, 8}, V{10, 9}, V{10, 10}, V{10, 11}, V{10, 12}, V{10, 13}, V{10, 14}, V{10, 15}, V{10, 16}, V{10, 17}, V{10, 18}, V{10, 19}, V{10, 20},
    V{10, 25}, V{10, 26}, V{10, 27},
    V{18, 25}, V{18, 26}, V{18, 27},
    V{22,5},V{22,6},V{22,7},V{22,8},V{22,9},V{22,10},V{22,11},V{22,12},
    V{22, 15}, V{22, 16}, V{22, 17},
    V{24, 6}, V{24, 7}, V{24, 8}, V{24, 9}, V{24, 10}, V{24, 11}};

int cellSizeWall = 30;
void drawWall(int i)
    {
        
        switch (i)
        {
        case 1:
        wall.clear();
        wall.insert(wall.begin(),map1.begin(),map1.end());
           for (unsigned int i = 0; i < wall.size(); i++)
        {
            float x = wall[i].x;
            float y = wall[i].y;
            Rectangle segment  =  Rectangle{ 75 + x *cellSizeWall, 75 + y*cellSizeWall, (float)cellSizeWall,(float)cellSizeWall};
            DrawRectangleRec(segment, BLACK);
        }
            break;
        case 2:
        wall.clear();
        wall.insert(wall.begin(),map2.begin(),map2.end());
           for (unsigned int i = 0; i < wall.size(); i++)
        {
            float x = wall[i].x;
            float y = wall[i].y;
            Rectangle segment  =  Rectangle{ 75 + x *cellSizeWall, 75 + y*cellSizeWall, (float)cellSizeWall,(float)cellSizeWall};
            DrawRectangleRec(segment, BLACK);
        }
        default:
            break;
        }  
        
    }
};
