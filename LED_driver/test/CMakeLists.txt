add_executable(LEDDriverTest
    AllTests.c
)

target_sources(LEDDriverTest PRIVATE
    LEDDriverTest.c
    LEDDriverTestRunner.c
    LEDDriver.c
    ../mocks/RuntimeErrorStub.c
)

target_include_directories(LEDDriverTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../mocks
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/util
)

target_link_libraries(LEDDriverTest
    Unity
)

add_test(LEDDriverTest LEDDriverTest)
