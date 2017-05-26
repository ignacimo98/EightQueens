cmake_minimum_required(VERSION 3.7)
project(EightQueens)

set(CMAKE_CXX_STANDARD 14)


set(SOURCE_FILES main.cpp solver.cpp solver.h GUIManager.h GUIManager.cpp screens.h screen.h menu.h menu.cpp Serial.h Serial.cpp Cell.cpp Cell.h Board.cpp Board.h)

set(EXECUTABLE_NAME "EightQueens")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(EightQueens ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

