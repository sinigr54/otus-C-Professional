cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(homework_2 VERSION ${PROJECT_VERSION})

option(WITH_TESTS "Whether to build tests" ON)

configure_file(version.h.in version.h)

add_executable(homework_2_cli main.cpp)
add_library(homework_2 ipaddress.h ipaddress.cpp IPAddressReader.cpp IPAddressReader.h)

set_target_properties(homework_2_cli homework_2 PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

target_include_directories(homework_2
        PRIVATE "${CMAKE_BINARY_DIR}"
        )

target_link_libraries(homework_2_cli PRIVATE
        homework_2
        )

if (WITH_TESTS)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_executable(test_homework_2 tests.cpp)

    target_link_libraries(
            test_homework_2
            GTest::gtest_main
            homework_2
    )

    include(GoogleTest)
    gtest_discover_tests(test_homework_2)
endif ()

if (MSVC)
    target_compile_options(homework_2_cli PRIVATE
            /W4
            )
    target_compile_options(homework_2 PRIVATE
            /W4
            )
    if (WITH_BOOST_TEST)
        target_compile_options(tests PRIVATE
                /W4
                )
    endif ()
else ()
    target_compile_options(homework_2_cli PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(homework_2 PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    if (WITH_BOOST_TEST)
        target_compile_options(tests PRIVATE
                -Wall -Wextra -pedantic -Werror
                )
    endif ()
endif ()

install(TARGETS homework_2_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if (WITH_TESTS)
    enable_testing()
    add_test(test_ip_address_reader test_homework_2)
endif ()
