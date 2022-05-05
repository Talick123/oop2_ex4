#file (MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/resources)
#configure_file ("my_file1.jpg" ${CMAKE_BINARY_DIR}/resources COPYONLY)
#configure_file ("my_file2.jpg" ${CMAKE_BINARY_DIR}/resources COPYONLY)


# fonts
configure_file ("fonts/YatraOne.ttf" ${CMAKE_BINARY_DIR} COPYONLY)

# textures
configure_file ("undo.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("new-game.png" ${CMAKE_BINARY_DIR} COPYONLY)