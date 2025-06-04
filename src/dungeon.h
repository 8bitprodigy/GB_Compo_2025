#ifndef DUNGEON_H
	#define DUNGEON_H

	#include "common.h"


/* Initializer */
void     Dungeon_generate(word seed, byte level);

/* Dungeon Methods */
byte     Dungeon_getTile(byte x, byte y);


#endif /* DUNGEON_H */
