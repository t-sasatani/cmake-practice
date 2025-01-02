add_executable(LEDDriverTest
    AllTests.c
)

target_sources(LEDDriverTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/LEDDriver.c
    LEDDriverTestRunner.c
    LEDDriverTest.c
    ${CMAKE_CURRENT_SOURCE_DIR}/mocks/RuntimeErrorStub.c
)

target_include_directories(LEDDriverTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/mocks
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/util
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(LEDDriverTest
    Unity
)

add_test(LEDDriverTest LEDDriverTest)
