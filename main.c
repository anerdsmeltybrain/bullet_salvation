#include "raylib.h"

//global stuff
#define MAX_BULLETS 100

typedef struct Player { 
	Vector2 pos;
	Vector2 size;
       	Color color; 
	} Player;

typedef struct Bullet { 
	Vector2 pos;
	Vector2 size;
       	Color color; 
	int speed;
	bool isActive;
	} Bullet;
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	
    Player starship = { 0 };
    Bullet bullet[MAX_BULLETS] = { 0 };

    starship.pos.x = 100;
    starship.pos.y = 100;
    starship.size.x = 100;
    starship.size.y = 100;
    starship.color = GREEN;

    for (int i = 0; i < MAX_BULLETS; i++) {
    bullet[i].pos.x = starship.pos.x;
    bullet[i].pos.y = starship.pos.y;
    bullet[i].size.x = starship.pos.x / 4;
    bullet[i].size.y = starship.pos.y / 4;
    bullet[i].color = YELLOW;
    bullet[i].speed = 5;
    bullet[i].isActive = false;
    }

    Bullet *bulletp = &bullet[MAX_BULLETS - 1];

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
	if(IsKeyDown(KEY_RIGHT)) starship.pos.x += 1;
	if(IsKeyDown(KEY_LEFT)) starship.pos.x -= 1;
	if(IsKeyDown(KEY_UP)) starship.pos.y -= 1;
	if(IsKeyDown(KEY_DOWN)) starship.pos.y += 1;

	int maxbulletacum = 0;
	if(IsKeyDown(KEY_SPACE)) {
		bulletp[maxbulletacum].isActive = true;
		maxbulletacum++;
		if(IsKeyReleased(KEY_SPACE)) { 
			maxbulletacum++;
			}
	};

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground((Color){21, 29, 33, 255});
	    
	    DrawRectangleV(starship.pos, starship.size, starship.color);

	    if(bulletp->isActive == true) {
		for (int i = 0; i < MAX_BULLETS; i++) {
		    DrawRectangleV(bulletp[maxbulletacum].pos, bulletp->size, bullet->color);
		    bulletp[i].pos.y -= bulletp[i].speed;
		}
	    }

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}
