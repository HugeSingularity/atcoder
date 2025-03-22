# CMakeList.txt: 385 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
set (SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
file(GLOB CPP_FILES "${SOURCE_DIR}/*.cpp")

get_filename_component(PROJ_NAME ${SOURCE_DIR} NAME)

# 将源代码添加到此项目的可执行文件。

foreach (CPP_FILE ${CPP_FILES})
	get_filename_component(EXECUTABLE_NAME ${CPP_FILE} NAME_WE)
	get_filename_component(CPP_NAME ${CPP_FILE} NAME)
	add_executable ("${PROJ_NAME}_${EXECUTABLE_NAME}" "${CPP_NAME}")

	if (CMAKE_VERSION VERSION_GREATER 3.12)
	  set_property(TARGET ${PROJ_NAME}_${EXECUTABLE_NAME} PROPERTY CXX_STANDARD 20)
	endif()
endforeach()



# TODO: 如有需要，请添加测试并安装目标。
