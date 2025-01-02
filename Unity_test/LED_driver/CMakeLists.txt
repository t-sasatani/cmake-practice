add_executable(LEDDriverTest
    Tests.c
)

target_sources(LEDDriverTest PRIVATE
    LEDDriverTest.c
    LEDDriverTestRunner.c
)

target_link_libraries(LEDDriverTest
    Unity
)

add_test(LEDDriverTest LEDDriverTest)
