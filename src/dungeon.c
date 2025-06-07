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
			bool       leaf      :1;
			SectorKind kind      :1;
			bool       split_axis:1;
			byte       depth     :3;
			bool       flag_6    :1;
			bool       flag_7    :1; /* These are subject to change */
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

Sector *
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
	Rectangle room;
	
	room.x = Zone->x+1,
	room.y = Zone->y+1,
	room.w = max_room_width,
	room.h = max_room_height;

	Dungeon.sectors[Index].leaf    = true;
	Dungeon.sectors[Index].kind    = ROOM;
	Dungeon.sectors[Index].depth   = Depth;
	Dungeon.sectors[Index].feature = room;

	return &Dungeon.sectors[Index];
} /* generateRoom */


Sector *
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
	sector->depth  = Depth;

	if (
		4 <= Depth
		|| (
			   width >>1 <= MIN_SECTOR_SIZE 
			&& height>>1 <= MIN_SECTOR_SIZE
		)
	) {
		return generateRoom(Index, Depth, Zone);
	}

	sector->leaf = false;

	bool split_axis = sector->split_axis;
	
	byte
		left  = 2 * Index + 1,
		right = 2 * Index + 1,
		middle = (split_axis) 
			? randRange(
				Zone->y + MIN_SECTOR_SIZE, 
				Zone->y + height - MIN_SECTOR_SIZE
			)
			: randRange(
				Zone->x + MIN_SECTOR_SIZE, 
				Zone->x + width  - MIN_SECTOR_SIZE
			);

	Rectangle
		zone_left,
		zone_right,
		*feature_left,
		*feature_right;

	
	if (split_axis) {
		zone_left.x1 = Zone->x1;
		zone_left.y1 = Zone->y1;
		zone_left.x2 = middle;
		zone_left.y2 = Zone->y2;
		
		zone_right.x1 = middle + 1;
		zone_right.y1 = Zone->y1;
		zone_right.x2 = Zone->x2;
		zone_right.y2 = Zone->y2;
		
	} else {
		zone_left.x1 = Zone->x1;
		zone_left.y1 = Zone->y1;
		zone_left.x2 = Zone->x2;
		zone_left.y2 = middle;
		
		zone_right.x1 = Zone->x1;
		zone_right.y1 = middle + 1;
		zone_right.x2 = Zone->x2;
		zone_right.y2 = Zone->y2;
		
	}

	Sector
		*sector_left  = generateSector(left,  Depth+1, &zone_left),
		*sector_right = generateSector(right, Depth+1, &zone_right);

	feature_left  = &sector_left->feature;
	feature_right = &sector_right->feature;
	
	byte
		left_range_lo,
		left_range_hi,
		right_range_lo,
		right_range_hi;

	if (split_axis) {
		if (feature_left->y1 < feature_right->y1) {
			left_range_lo  = feature_left ->y1;
			right_range_lo = feature_right->y1;
		} else {
			left_range_lo  = feature_right->y1;
			right_range_lo = feature_left ->y1;
		}
		if (feature_left->y2 < feature_right->y2) {
			left_range_hi  = feature_left ->y2;
			right_range_hi = feature_right->y2;
		} else {
			left_range_hi  = feature_right->y2;
			right_range_hi = feature_left ->y2;
		}
	}
	else {
		if (feature_left->x1 < feature_right->x1) {
			left_range_lo  = feature_left ->x1;
			right_range_lo = feature_right->x1;
		} else {
			left_range_lo  = feature_right->x1;
			right_range_lo = feature_left ->x1;
		}
		if (feature_left->x2 < feature_right->x2) {
			left_range_hi  = feature_left ->x2;
			right_range_hi = feature_right->x2;
		} else {
			left_range_hi  = feature_right->x2;
			right_range_hi = feature_left ->x2;
		}
	}
	
	if (split_axis) {
		sector->feature.x1 = feature_left->x2,
		sector->feature.y1 = randRange(left_range_lo, left_range_hi),
		sector->feature.x2 = feature_right->x1,
		sector->feature.y2 = randRange(right_range_lo, right_range_hi);
		
		sector->feature.x1 = randRange(left_range_lo, left_range_hi),
		sector->feature.y1 = feature_left->y2,
		sector->feature.x2 = randRange(right_range_lo, right_range_hi),
		sector->feature.y2 = feature_right->y1;
	}

	
	switch (randRange(0,2)) {
	case LEFT:
		return (sector_left->depth - Depth) <= 1
			? sector_left
			: sector;
	case RIGHT:
		return (sector_right->depth - Depth) <= 1
			? sector_right
			: sector;
	default:
		return sector;
	}
} /* generateSector */


void
Dungeon_generate(word Seed, byte Level)
{
	Dungeon.seed  = Seed;
	Dungeon.level = Level;
	initrand(Seed);
	
	Rectangle zone;
	zone.x1 = 0,
	zone.y1 = 0,
	zone.x2 = MAX_LEVEL_SIZE,
	zone.y2 = MAX_LEVEL_SIZE;
	
	generateSector(0, 0, &zone);
} /* Dungeon_generate */


byte
getSectorTile(byte Index, byte x, byte y)
{
	if (Index > 32) {
		return 0;
	}
	
	Sector *sector = &Dungeon.sectors[Index];
	
	if (!isInRect(x, y, &sector->zone)) { 
		return 0;
	}
	if (
		sector->leaf
		&& isInRect(x, y, &sector->feature)
	) {
		return 1;
	}
	if (sector->depth >= 4) {
		return 0;
	}
	
	byte
		tile_left  = getSectorTile( 2 * Index + 1, x, y),
		tile_right = getSectorTile( 2 * Index + 2, x, y);

	if (tile_left) return tile_left;
	if (tile_right) return tile_right;
	
	return isInRect(x, y, &sector->feature);
} /* getSectorTile */


inline byte
Dungeon_getTile(byte x, byte y)
{
	return getSectorTile(0, x, y);
} /* Dungeon_getTile */

inline void
Dungeon_plotTile(byte x, byte y)
{
	set_bkg_tile_xy(
		x, 
		y, 
		Dungeon_getTile(x, y)
	);
}

inline void
Dungeon_plotTiles(
	byte x,
	byte y,
	byte w,
	byte h
)
{
	byte
		i,
		j;
	for (i = 0; i < w; i++) 
		for (j = 0; j < h; j++)
			Dungeon_plotTile(x+i, y+j);
}
