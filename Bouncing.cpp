#include "Game.h"

void main(int argc, void** argv[])
{
	Game game; // Creating game object
	while (!game.GetWindow()->IsDone())
	{
		// Game loop.
		//game.HandleInput();
		game.Update();
		game.Render();
	}
}



