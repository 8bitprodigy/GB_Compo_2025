#include "gamestate.h"
#include "defs.h"
#include "../res/ibm_bios.h"
#include "dungeon.h"


/*
	G L O B A L S
*/

/*
	D E F I N I T I O N
*/

enum {
	JOY_CURRENT,
	JOY_PREVIOUS,
	JOY_DIFFERENCE,
};


typedef union
JoyState
{
	byte state;
	struct {
		bool right :1;
		bool left  :1;
		bool up    :1;
		bool down  :1;
		bool a     :1;
		bool b     :1;
		bool select:1;
		bool start :1;
	};
}
JoyState;


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

	union {
		byte joystates[3];
		struct {
			JoyState joy_current;
			JoyState joy_previous;
			JoyState joy_difference;
		};
	};
	Vec2 dpad_dir;
	//Actor player;
	UVec2 camera;
}
GameState;

/*
	F O R W A R D    D E C L A R A T I O N S
*/
void handleScrolling(GameState *game_state);


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
	
	for (;;) {
		GameState_update(game_state);
		GameState_draw(game_state);
	}
}


void
GameState_update(GameState *game_state)
{
	/* Handle inputs */
	game_state->joy_previous.state   = game_state->joy_current.state;
	game_state->joy_current.state    = joypad();
	game_state->joy_difference.state = game_state->joy_current.state ^ game_state->joy_previous.state;

	game_state->dpad_dir.x     = game_state->joy_current.right - game_state->joy_current.left;
	game_state->dpad_dir.y     = game_state->joy_current.down  - game_state->joy_current.up;
	/* Update entities */
	if (game_state->joy_difference.state == 0) return;
	handleScrolling(game_state);
}


void
GameState_draw(GameState *game_state)
{
	/* Draw everything */
	
	vsync();
}

/*
	P R I V A T E    F U N C T I O N S
*/
void
handleScrolling(GameState *game_state)
{
	game_state->camera.x += game_state->dpad_dir.x;
	game_state->camera.y += game_state->dpad_dir.y;

	if (0 < game_state->dpad_dir.x) {
		Dungeon_plotTiles(
			game_state->camera.x + SCREEN_WIDTH_IN_TILES - game_state->dpad_dir.x,
			game_state->camera.y,
			game_state->dpad_dir.x,
			SCREEN_HEIGHT_IN_TILES
		);
	}
	if (game_state->dpad_dir.x < 0) {
		Dungeon_plotTiles(
			game_state->camera.x,
			game_state->camera.y,
			abs(game_state->dpad_dir.x),
			SCREEN_HEIGHT_IN_TILES
		);
	}
	if (0 < game_state->dpad_dir.y) {
		Dungeon_plotTiles(
			game_state->camera.x,
			game_state->camera.y + SCREEN_HEIGHT_IN_TILES - game_state->dpad_dir.y,
			SCREEN_WIDTH_IN_TILES,
			game_state->dpad_dir.y
		);
	}
	if (game_state->dpad_dir.y < 0) {
		Dungeon_plotTiles(
			game_state->camera.x,
			game_state->camera.y,
			SCREEN_WIDTH_IN_TILES,
			abs(game_state->dpad_dir.y)
		);
	}

	move_bkg(game_state->camera.x << 3, game_state->camera.y << 3);
}
