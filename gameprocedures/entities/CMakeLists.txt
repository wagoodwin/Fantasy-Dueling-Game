

add_library(entities)
target_sources(entities PRIVATE
    Computer.cpp
    Computer.h
    Dueler.cpp
    Dueler.h
    Player.cpp
    Player.h
    )


add_subdirectory(randutils)
target_link_libraries(entities PRIVATE randutils)

# target_sources(fdg PRIVATE
# "${CMAKE_CURRENT_SOURCE_DIR}/Computer.cpp"
# "${CMAKE_CURRENT_SOURCE_DIR}/Dueler.cpp"
# "${CMAKE_CURRENT_SOURCE_DIR}/Player.cpp"
# "${CMAKE_CURRENT_SOURCE_DIR}/Computer.h"
# "${CMAKE_CURRENT_SOURCE_DIR}/Dueler.h"
# "${CMAKE_CURRENT_SOURCE_DIR}/Player.h")

# target_include_directories(fdg PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")