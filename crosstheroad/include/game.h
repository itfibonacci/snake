#ifndef GAME_H
#define GAME_H

typedef struct Game {
	unsigned char game_is_running; // 0 for game is not running, 1 otherwise
	unsigned char current_level;
} Game;

void initialize_game(Game* game);

#endif
