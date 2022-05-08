#file (MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/resources)
#configure_file ("my_file1.jpg" ${CMAKE_BINARY_DIR}/resources COPYONLY)
#configure_file ("my_file2.jpg" ${CMAKE_BINARY_DIR}/resources COPYONLY)


# fonts
configure_file ("fonts/YatraOne.ttf" ${CMAKE_BINARY_DIR} COPYONLY)

# textures
configure_file ("images/cat.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("images/new_game_btn.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("images/resart_btn.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("images/undo_btn.png" ${CMAKE_BINARY_DIR} COPYONLY)

configure_file ("images/win_page.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("images/lose_page.png" ${CMAKE_BINARY_DIR} COPYONLY)


#audio
configure_file ("audio/click.wav" ${CMAKE_BINARY_DIR} COPYONLY)
