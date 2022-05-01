#pragma once


//Window
const int WINDOW_HEIGHT = 900;
const int WINDOW_LENGTH = 1450;

//Board
const int TILE_RADIUS = 30;
const int PADDING = 10;
const int TOTAL_TILE_SIZE = TILE_RADIUS * 2 + PADDING;

const float BOARD_OFFSET_Y = (WINDOW_HEIGHT - TOTAL_TILE_SIZE * 11 - PADDING) / 2;

const int BOARD_AREA_LENGTH = WINDOW_LENGTH * (0.7);
const int BOARD_OFFSET_X = (BOARD_AREA_LENGTH - (TOTAL_TILE_SIZE * 11 + TILE_RADIUS))/2;
