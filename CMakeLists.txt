cmake_minimum_required(VERSION 3.12)

project(Chess)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	src/Chess.cpp
	src/Queen.cpp
	src/Bishop.cpp
	src/King.cpp
	src/Knight.cpp
	src/Pawn.cpp
	src/Rook.cpp
	src/Figure.cpp
	src/Field.cpp
	src/Player.cpp
)

add_executable("${PROJECT_NAME}" ${SOURCES})

target_include_directories("${PROJECT_NAME}"
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/headers
)

#install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
#install(FILES ${SOURCES} DESTINATION src)