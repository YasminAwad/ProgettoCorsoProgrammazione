add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(EXECUTABLE_NAME runAllTests)

set(TEST_SOURCE_FILES runAllTests.cpp MapTest.cpp GameCharacterTest.cpp MonsterTest.cpp PickUpTest.cpp ProjectileTest.cpp)
add_executable(${EXECUTABLE_NAME} ${TEST_SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} gtest gtest_main core)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULES_PATH})
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()