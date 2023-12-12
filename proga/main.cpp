#include "addFunct.h"
#include "game.h"
#include <cstring>
bool Paused = false;


string  sound = "on";


int main () { 

   InitWindow(cellSize*cellCount - 50, cellSize*cellCount - 150, "Select map");
   SetTargetFPS(60);
    while(WindowShouldClose() == false)
{
BeginDrawing();
ClearBackground(BLUE);
DrawText("Select map", offset - 5, 50, 60, darkGreen);
DrawText("Press 1 for PvP", offset - 5, 170, 60, darkGreen);
DrawText("Press 2 for PvE", offset - 5, 290, 60, darkGreen);
DrawText(("Press P " + sound + " sound").c_str(), offset - 5, 410, 60, darkGreen);
DrawText("Press ESC to exit", offset - 5, 530, 60, darkGreen);
EndDrawing();

if(IsKeyPressed(KEY_ONE))
{
   ichecker=1;
   CloseWindow();
}
if(IsKeyPressed(KEY_TWO))
{
   ichecker=2;
   CloseWindow();
}

if(IsKeyPressed(KEY_P))
{
    toggle =!toggle;
    if (toggle){
    sound ="on";
    }
    else
    sound = "off";
}
if (IsKeyPressed(KEY_ESCAPE)){
    exit(0);
}
}

InitWindow(2*offset + cellSize*cellCount, 2*offset + cellSize*cellCount, "Slizario");
SetTargetFPS(60);

Game game = Game();
game.changeFoodPos();
game.running = false;


while(WindowShouldClose() == false)
{
    if (IsKeyPressed(KEY_SPACE)){
        Paused = !Paused;
    }
        if (IsKeyPressed(KEY_R)){
            if(Paused2 )
        Paused2 = !Paused2;
        game.resetSnake2();
        game.resetSnake();
        game.score2 = 0;
        game.score = 0;
        game.changeFoodPos();
    }

BeginDrawing();

if(eventTriggered(0.15))
{
    if (!Paused and !Paused2) {
    game.Update();
    }
}

if(IsKeyPressed(KEY_W) && (!Paused) && game.snake.direction.y != 1)
{
    game.snake.direction = {0,  -1};
    game.running = true;
}
if(IsKeyPressed(KEY_S) && (!Paused) && game.snake.direction.y != -1)
{
    game.snake.direction = {0, 1};
    game.running = true;
}
if(IsKeyPressed(KEY_D) && (!Paused) && game.snake.direction.x != -1)
{
    game.snake.direction = {1, 0};
    game.running = true;
}
if(IsKeyPressed(KEY_A) && (!Paused) && game.snake.direction.x != 1)
{
    game.snake.direction = {-1, 0};
    game.running = true;
}
if(ichecker == 1)
{
    if(IsKeyPressed(KEY_UP) && (!Paused) && game.snake2.direction2.y != 1)
    {
        game.snake2.direction2= {0,  -1};
        game.running = true;
    }
    if(IsKeyPressed(KEY_DOWN) && (!Paused) && game.snake2.direction2.y != -1)
    {
        game.snake2.direction2 = {0, 1};
        game.running = true;
    }
    if(IsKeyPressed(KEY_RIGHT) && (!Paused) && game.snake2.direction2.x != -1)
    {
        game.snake2.direction2 = {1, 0};
        game.running = true;
    }
    if(IsKeyPressed(KEY_LEFT) && (!Paused) && game.snake2.direction2.x != 1)
    {
        game.snake2.direction2= {-1, 0};
        game.running = true;
    }
}
if (Paused){
    DrawText("Paused", 430, 10, 60, BLACK);
}
if (Paused2)
{
    if(game.score == 20)
    {
            DrawText("Player 1 won", 430, 10, 60, BLACK);
    }
    else if(game.score2 == 20)
    {
            DrawText("Player 2 won", 430, 10, 60, BLACK);
    }
}



ClearBackground(BLUE);
DrawRectangleLinesEx(Rectangle{(float)offset-5, (float)offset-5, (float)cellSize*cellCount+10, (float)cellSize*cellCount+10}, 5, darkGreen);
DrawText("Slizario", offset - 5, 20, 40, darkGreen);
DrawText(TextFormat("%i",game.score), offset -5, offset+cellSize*cellCount+10, 40, darkGreen);
DrawText(TextFormat("%i",game.score2), offset +885, offset+cellSize*cellCount+10, 40, darkGreen);
game.Draw(ichecker);

EndDrawing(); 
}

CloseWindow();

    return 0;
}