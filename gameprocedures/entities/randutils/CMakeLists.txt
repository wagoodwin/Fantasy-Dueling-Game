

add_library(randutils)
target_sources(randutils PRIVATE randUtils.cpp randUtils.h)



# target_sources(fdg PRIVATE
# "${CMAKE_CURRENT_SOURCE_DIR}/randUtils.cpp"
# "${CMAKE_CURRENT_SOURCE_DIR}/randUtils.h")

# target_include_directories(fdg PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")