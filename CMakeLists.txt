
cmake_minimum_required(VERSION 3.13)

# project name
project (fdg) 


# add_library(fdg main.cpp)

# add_subdirectory(computer)
# add_subdirectory(dueler)
# add_subdirectory(gameprocedures)
# add_subdirectory(player)
# add_subdirectory(randutils)


set(HEADERS
    GameProcedures.h
    Dueler.h
    Player.h
    Computer.h
    randUtils.h
)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    main.cpp
    GameProcedures.cpp
    Dueler.cpp
    Player.cpp
    Computer.cpp
    randUtils.cpp
)



add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS}) # ${PROJECT_NAME} = fdg 


# target_include_directories(fdg
#     PUBLIC
#         GameProcedures.h
#         Dueler.h
#         Player.h
#         Computer.h
#         randUtils.h
# )