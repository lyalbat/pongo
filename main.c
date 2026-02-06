#include "include/raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "pongo"); //title

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    const int characters_radius = 25;
    const int characters_spacing_side = 10;
    const int ball_radius = 5;
    int ball_colided = 0;
    const float ball_speed = 2.5f;
    const float alien_speed = 2.5f;
    int alien_direction = 1;

    Vector2 humanPosition = {(float)characters_radius + characters_spacing_side, (float)screenHeight/2};
    Vector2 alienPosition = {(float)screenWidth-characters_radius - characters_spacing_side, (float)screenHeight/2};
    Vector2 ballPosition     = {(float)screenWidth/2 , (float)screenHeight/2};

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Checks if ball has collided with either human or the alien -> changes direction
        if( CheckCollisionCircles(humanPosition,characters_radius, ballPosition,ball_radius) ||
            CheckCollisionCircles(alienPosition,characters_radius, ballPosition,ball_radius)) ball_colided = !ball_colided;
        
        if(alienPosition.y - screenHeight == characters_radius) alien_direction = -1;
        if(alienPosition.y - screenHeight == screenHeight-characters_radius) alien_direction = 1;

        //alienPosition.y += alien_speed;
        //if ((alienPosition.y >= (screenHeight - ball_radius)) || (alienPosition.y <= ball_radius)) alienPosition.y *= -alien_speed;

        alienPosition.y = alienPosition.y + (alien_direction)*alien_speed;

        if(!ball_colided) ballPosition.x -= ball_speed;
        else ballPosition.x += ball_speed;

        if (IsKeyDown(KEY_UP)) humanPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) humanPosition.y += 2.0f;

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("PONGO!", (int)screenWidth/2-100, 10, 50, BLACK);

            DrawCircleV(humanPosition,characters_radius,BLUE);
            DrawCircleV(alienPosition,characters_radius,GREEN);
            DrawCircleV(ballPosition,ball_radius,ORANGE);


        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
   
    return 0;
}