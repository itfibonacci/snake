#include "utils.h"

// Constants for the grid size
const int GRID_ROWS = 3;
const int GRID_COLS = 3;
const int CELL_SIZE = 5;

WINDOW* initialize_screen() {
	// Initialize ncurses
	initscr();
	noecho();
	cbreak();
	curs_set(0); // Make the cursor invisible

	// Create a window
	WINDOW *win = newwin(WINDOW_HEIGHT, WINDOW_LENGTH, 0, 0);

	// Enable non-blocking input
	nodelay(stdscr, TRUE);

	// Enable keypad
	keypad(stdscr, TRUE);

	// Display the window
	refresh();
	box(win, 0, 0);
	wrefresh(win);

	return win;
}

void draw_x(WINDOW *win, unsigned char row, unsigned char col, unsigned char START_X, unsigned char START_Y) {
	for (unsigned char i = 0; i <= GRID_COLS; i++) {
		mvwaddch(win, START_Y + CELL_SIZE*(row - 1) + i + 1, START_X + (col - 1)*CELL_SIZE + i, '\\');
	}

	for (unsigned char i = 0; i <= GRID_ROWS; i++) {
		mvwaddch(win, START_Y + CELL_SIZE*(row - 1) + i + 1, START_X - 2 + (col)*CELL_SIZE - i, '/');
	}
}

void draw_o(WINDOW *win, unsigned char row, unsigned char col, unsigned char START_X, unsigned char START_Y) {
	for (unsigned char i = 0; i <= GRID_COLS; i++) {
		mvwaddch(win, START_Y + CELL_SIZE*(row - 1) + i + 1, START_X + (col - 1)*CELL_SIZE, '[');
		mvwaddch(win, START_Y + CELL_SIZE*(row - 1) + i + 1, START_X - 2 + (col)*CELL_SIZE, ']');
	}
}

void draw_board(WINDOW *win) {
	unsigned char START_X = (getmaxx(win) - GRID_COLS * CELL_SIZE) / 2;
	unsigned char START_Y = (getmaxy(win) - GRID_ROWS * CELL_SIZE) / 2;

	for (unsigned char i = 0; i <= GRID_ROWS; i++) {
		wmove(win, START_Y + i*CELL_SIZE, START_X);
		whline(win, ACS_HLINE, CELL_SIZE*GRID_COLS);
	}

	for (unsigned char i = 1; i < CELL_SIZE*GRID_ROWS; i++) {
		for (unsigned char j = 0; j <= GRID_COLS; j++) {
			wmove(win, START_Y + i, START_X + j*CELL_SIZE - 1);
			whline(win, ACS_VLINE, 1);
		}
	}
	draw_x(win, 1, 3, START_X, START_Y);
	draw_x(win, 2, 3, START_X, START_Y);
	draw_x(win, 1, 1, START_X, START_Y);
	draw_o(win, 3, 3, START_X, START_Y);
	draw_o(win, 2, 2, START_X, START_Y);
	wrefresh(win);
}