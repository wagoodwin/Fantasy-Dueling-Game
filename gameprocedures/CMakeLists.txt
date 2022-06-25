

add_library(gameprocedures)
target_sources(gameprocedures PRIVATE GameProcedures.cpp GameProcedures.h)

add_subdirectory(entities)

target_link_libraries(gameprocedures PRIVATE entities)

# target_sources(fdg PRIVATE
# "${CMAKE_CURRENT_SOURCE_DIR}/GameProcedures.cpp"
# "${CMAKE_CURRENT_SOURCE_DIR}/GameProcedures.h")

# target_include_directories(fdg PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")