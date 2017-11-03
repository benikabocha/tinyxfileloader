if(TINYXFILELOADER_ENABLE_TEST)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/googletest/include)
    file(GLOB SOURCES *.cpp)
    file(GLOB HEADERS *.h)

    add_executable(tests
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest/src/gtest-all.cc
        ${SOURCES}
        ${HEADERS}
    )
    target_include_directories(tests
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/googletest
    )
    if (UNIX)
        find_package(Threads REQUIRED)
        target_link_libraries(tests ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
    endif ()
    set(SAMPLE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/sample")
    target_compile_definitions(
        tests
        PRIVATE SAMPLE_DATA_PATH="${SAMPLE_DIRECTORY}"
    )
    add_test(
        NAME all_test
        COMMAND $<TARGET_FILE:tests>
    )
endif()
