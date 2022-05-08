﻿OOP2 ex3 - Set Calculator Exceptions

Written by: Tali Kalev (טלי כלב), ID:208629691
            Noga Levy (נוגה לוי), ID:315260927

General Description of the Assignment:
    In this assignment we implemented the game "Circle the Cat", where the goal is to enclose
    the cat by clicking and blocking out tiles. If the cat reaches the edge, the user loses.
    If the user is able to enclose the cat such that it can not continue to move, then the 
    user wins.
    
Design:
    
    Classes: Animation, Audio, Board, Button, Cat, DataDisplay, GameBoard, GameController, 
            Tile, Resources

    Animation:
        - responsible for the cats animation on the board
    Audio:
        - deals with audio used during game
    Board:
        - responsible for board itself, the tiles on the board, and the types of levels generated 
    Button:
        - responsible for the buttons on the data display
    Cat:
        - responible for cat, moving cat and finding best position on board
    DataDisplay:
        - responsible for displaying data about game and handling buttons
    GameBoard
        - responsible for all aspects of a running game, the board, the cat
    GameController:
        - responsible for running the game, receiving input and dealing with it
        accordingly, as well as switching between different game states
    Tile:
        - represents one tile on board
    Resources:
        - singleton that loads and access different media files

Files:
    - Animation.h/Animation.cpp: contains Animation class
    - Audio.h/Audio.cpp: contains Audio class
    - Board.h/Board.cpp: contains Board class
    - Button.h/Button.cpp: contains Button class
    - Cat.h/Cat.cpp: contains Cat class
    - DataDisplay.h/DataDisplay.cpp: contains DataDisplay class
    - GameBoard.h/GameBoard.cpp: contains GameBoard class
    - GameController.h/GameController.cpp: contains GameController class
    - macros.h: contains macros needed throughout code
    - Resources.h/Resources.cpp: contains Resources class
    - Tile.h/Tile.cpp: contains Tile class

Main Data Structures and their Jobs:
    - vector of pairs contain pair locations and tiles that keep track
    of the game moves (for undo/reset button/move counter)
    - queue of pairs used for bfs algorithm in order to contain locations
    on 2 board
    - all other main data structures and their jobs: see Design above

Notable Algorithms:
    - BFS algorithm for finding shortest path from cat to edge of board:
        https://www.geeksforgeeks.org/breadth-first-traversal-bfs-on-a-2d-array/
        https://www.geeksforgeeks.org/breadth-first-traversal-bfs-on-a-2d-array/
        - we used this algoritm as it doesn't require another data structure like
        a graph that needs to be updated. Uses the matrix represented as the board.

Known Bugs:
    - no known bugs

Other General Notes:
    - game creates an infinite number of levels with number of blocked tiles being 
    between 4 and 14 based on difficulty
    - The controller divides the game loop into three distinct functions, one that deals
    with the game play, one that updates the required data, one that renders the game (via SFML)
    - when the BFS algorithm fails at finding the shortest path to the edge of the game board,
    the program finds the longest path within the enclosed area that the cat is in, in order to 
    move it as far away as possible