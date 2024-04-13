cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(cpp_otus_professional VERSION ${PROJECT_VERSION})

add_subdirectory(homework_1)
add_subdirectory(homework_2)
