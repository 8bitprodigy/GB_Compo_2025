#include "common.h"
#include "gamestate.h"

void
main(void)
{
	GameState *gs = GameState_new();

	GameState_run(gs);
}
