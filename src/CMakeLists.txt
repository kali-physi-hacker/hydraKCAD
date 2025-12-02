file(GLOB_RECURSE MGE_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(MGE ${MGE_SOURCES})

target_include_directories(MGE PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)