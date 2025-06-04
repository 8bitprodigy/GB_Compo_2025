#include "dungeon.h"
#include "common.h"
#include "defs.h"


/****************
	T Y P E S
****************/

typedef enum {
	CORRIDOR,
	ROOM,
}
SectorKind;


typedef struct
Sector
{
	union {
		byte flags;
		struct {
			SectorKind kind      :1;
			bool       split_axis:1;
			bool       flag_2    :1; /* These are subject to change */
			bool       flag_3    :1;
			bool       flag_4    :1;
			bool       flag_5    :1;
			bool       flag_6    :1;
			bool       flag_7    :1;
		};
	};
	byte       middle;
	Rectangle  zone;
	Rectangle  feature;
}
Sector;


struct
{
	byte    level;
	word    seed;
	Sector sectors[MAX_NUM_SECTORS];
}
Dungeon;


/********************
	M E T H O D S
********************/

Rectangle *
generateRoom(
	byte       Index, 
	byte       Depth, 
	Rectangle *Zone
)
{
	byte 
		max_room_width  = Zone->w-2,
		max_room_height = Zone->h-2,
		width           = randRange(MIN_ROOM_SIZE, max_room_width),
		height          = randRange(MIN_ROOM_SIZE, max_room_height),
		position_x      = randRange(Zone->x, Zone->x + (Zone->w - width)),
		position_y      = randRange(Zone->y, Zone->y + (Zone->h - height));
	Rectangle room = {
		.x = position_x,
		.y = position_y,
		.w = width,
		.h = height,
	};
	Dungeon.sectors[Index].kind = ROOM;
	Dungeon.sectors[Index].feature = room;

	return &Dungeon.sectors[Index].feature;
} /* generateRoom */



Rectangle *
generateSector(
	byte       Index, 
	byte       Depth, 
	Rectangle *Zone
)
{
	byte    
		random = rand(),
		width  = Zone->x2 - Zone->x1,
		height = Zone->y2 - Zone->y1;
	Sector *sector = &Dungeon.sectors[Index];
	
	sector->zone   = *Zone;
	sector->flags  = random;

	if (
		4 <= Depth
		|| (
			   width >>1 <= MIN_SECTOR_SIZE 
			&& height>>1 <= MIN_SECTOR_SIZE
		)
	) {
		return generateRoom(Index, Depth, Zone);
	}
	
	sector->kind = CORRIDOR;

	byte
		left  = 2 * Index + 1,
		right = 2 * Index + 1,
		middle = (sector->split_axis) 
			? randRange(
				Zone->y + MIN_SECTOR_SIZE, 
				Zone->y + height - MIN_SECTOR_SIZE
			)
			: randRange(
				Zone->x + MIN_SECTOR_SIZE, 
				Zone->x + width  - MIN_SECTOR_SIZE
			);

	Rectangle
		sect_left = (sector->split_axis)
			? (Rectangle){
				.x1 = Zone->x1,
				.y1 = Zone->y1,
				.x2 = middle,
				.y2 = Zone->y2,
			}
			: (Rectangle){
				.x1 = Zone->x1,
				.y1 = Zone->y1,
				.x2 = Zone->x2,
				.y2 = middle,
			},
		sect_right = (sector->split_axis)
			? (Rectangle){
				.x1 = middle + 1,
				.y1 = Zone->y1,
				.x2 = Zone->x2,
				.y2 = Zone->y2,
			}
			: (Rectangle){
				.x1 = Zone->x1,
				.y1 = middle + 1,
				.x2 = Zone->x2,
				.y2 = Zone->y2,
			},

		*feature_left  = generateSector(left,  Depth+1, &sect_left),
		*feature_right = generateSector(right, Depth+1, &sect_right);

	/*
		Todo:
			- generate corridor
			- randomly decide which feature to return.
	*/
	
} /* generateSector */


void
Dungeon_generate(word Seed, byte Level)
{
	Dungeon.seed  = Seed;
	Dungeon.level = Level;
	initrand(Seed);
	
	Rectangle zone = {
		.x = 0,
		.y = 0,
		.x2 = MAX_LEVEL_SIZE,
		.y2 = MAX_LEVEL_SIZE,
	};
	
	generateSector(0, 0, &zone);
} /* Dungeon_generate */


byte
Dungeon_getTile(byte x, byte y)
{
	
} /* Dungeon_getTile */
