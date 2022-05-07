#include "SnakeGame.h"

void main(int argc, void** argv[])
{
	SnakeGame game; // Creating game object
	while (!game.GetWindow()->IsDone())
	{
		// Game loop.
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
}



