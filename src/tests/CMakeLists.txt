set(SOURCE_FILES
	stdlib/math.cpp
	stdlib/boolean.cpp
	stdlib/containers.cpp
	stdlib/string.cpp
	stdlib/tuple.cpp
	stdlib/core.cpp
	stdlib/function.cpp
	stdlib/types.cpp
	evaluate.cpp
	enviroment.cpp
	data.cpp
	parser.cpp
	main.cpp
)



add_executable(unit_tests ${SOURCE_FILES})
target_link_libraries(unit_tests xigua_core xigua_stdlib gtest)

add_test(unit_tests ${CMAKE_BINARY_DIR}/unit_tests)
