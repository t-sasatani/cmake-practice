add_library(greetings
    SHARED
    good_morning.cpp
    hello.cpp
    )

target_include_directories(greetings
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    )