#include "gamestate.h"
#include "defs.h"
#include "../res/ibm_bios.h"


/*
	G L O B A L S
*/
static byte Joy_State;

/*
	D E F I N I T I O N
*/
typedef struct
GameState
{
	union {
		byte flags;
		struct {
			bool paused:1;
			bool done  :1;
			bool flag_2:1;
			bool flag_3:1;
			bool flag_4:1;
			bool flag_5:1;
			bool flag_6:1;
			bool flag_7:1;
		};
	};
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
    DISPLAY_OFF;
	init_bkg(0);
	set_bkg_data(0, 255, ibm_bios_tiles);
	SHOW_BKG;
	Dungeon_generate(0, 0);
	Dungeon_plotTiles(0, 0, SCREEN_WIDTH_IN_TILES, SCREEN_HEIGHT_IN_TILES);
	DISPLAY_ON;
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
	GameState_init(game_state);
	
	for (;;) {
		GameState_update(game_state);
		GameState_draw(game_state);
	}
}


void
GameState_update(GameState *game_state)
{
	/* Handle inputs */
	Joy_State = joypad();
	/* Update entities */
	//printf("Hello World!\n");
}


void
GameState_draw(GameState *game_state)
{
	/* Draw everything */
	
	vsync();
}
