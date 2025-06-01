#include "gamestate.h"

/*
	D E F I N I T I O N
*/
typedef struct
GameState
{
	//Actor player;
	UVec2 camera;
}
GameState;


/*
	I N I T I A L I Z E R
*/
void
GameState_init(GameState *game_state)
{
	
}


/*
	C O N S T R U C T O R
*/
GameState *
GameState_new(void)
{
	GameState *game_state = malloc(sizeof(GameState));
	if (!game_state) {
		printf("Could not allocate game_state!");
		return NULL;
	}

	GameState_init(game_state);

	return game_state;
}


/*
	D E S T R U C T O R
*/
void
GameState_free(GameState *game_state)
{
	free(game_state);
}


/*
	M E T H O D S
*/
void
GameState_run(GameState *game_state)
{
	/* Initialize GameBoy resources */
	while (1) {
		GameState_update(game_state);
		GameState_draw(game_state);
	}
}


void
GameState_update(GameState *game_state)
{
	/* Handle inputs */
	/* Update entities */
}


void
GameState_draw(GameState *game_state)
{
	/* Draw everything */
}
