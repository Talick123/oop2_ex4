#pragma once

#include <utility>
#include <string>

//Window
const std::string GAME_TITLE = "Circle the Cat";
const int WINDOW_HEIGHT = 900;
const int WINDOW_LENGTH = 1450;

//Board
const int SIZE = 11;
const int TILE_RADIUS = 30;
const int PADDING = 10;
const int TOTAL_TILE_SIZE = TILE_RADIUS * 2 + PADDING;

const float BOARD_OFFSET_Y = (WINDOW_HEIGHT - TOTAL_TILE_SIZE * SIZE - PADDING) / 2;

const int BOARD_AREA_LENGTH = WINDOW_LENGTH * (0.7);
const int BOARD_OFFSET_X = (BOARD_AREA_LENGTH - (TOTAL_TILE_SIZE * SIZE + TILE_RADIUS))/2;


//Direction Vectors

// for even rows             N,  E, S,  W,  NW, SW
const int D_VEC_ROW_E[] = {  1, 0, -1,  0,  1, -1 };
const int D_VEC_COL_E[] = {  0, 1,  0, -1, -1, -1 };

// for odd rows             N, E,  S,  W,  NE, SE
const int D_VEC_ROW_O[] = { 1, 0, -1,  0,  1, -1 };
const int D_VEC_COL_O[] = { 0, 1,  0, -1,  1,  1 };


const int NUM_OF_BTNS = 3;
enum class Btns {NewGame, Undo, Reset, None};


//for bfs
const std::pair<int, int> NO_PARENT{ -1,-1 };

const int MAX_BLOCK_TILES = 14;
const int MIN_BLOCK_TILES = 4;

enum class GameStatus
{
	Playing,
	Won,
	Lose
};
