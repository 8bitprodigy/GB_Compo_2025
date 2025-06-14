#ifndef GAMESTATE_H
	#define GAMESTATE_H

	#include "common.h"


/* Constructor */
GameState *GameState_new(void);
/* Initializer */
void       GameState_init(GameState *game_state);
/* Destructor */
void       GameState_free(GameState *game_state);

/* GameState Methods */
/*    Run */
void GameState_run(GameState *game_state);
/*    Update */
void GameState_update(GameState *game_state);
/*    Draw */
void GameState_draw(GameState *game_state);
	
#endif /* GAMESTATE_H */
