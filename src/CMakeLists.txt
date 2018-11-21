set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
include_directories(.)
aux_source_directory(. SRC)

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)
find_package(Qt5OpenGL CONFIG REQUIRED)
find_package(Qt5PrintSupport CONFIG REQUIRED)
find_package(Qt5TextToSpeech CONFIG REQUIRED)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)
set(DEFINES "-DUNICODE -D_UNICODE -DWIN32 -DQT_DEPRECATED_WARNINGS")
set(CMAKE_C_FLAGS "-fno-keep-inline-dllexport -fopenmp -march=i686 -mtune=core2 -Wa,-mbig-obj -O2 -Wall -W -Wextra ${DEFINES}")
set(CMAKE_CXX_FLAGS "-fno-keep-inline-dllexport -fopenmp -O2 -g -Wall -W -Wextra -fexceptions -mthreads ${DEFINES}")

set(FONTS ${PROJECT_SOURCE_DIR}/res/fonts.qrc)

add_executable(serial ${SRC})
target_link_libraries(serial
        Qt5Core
        Qt5Widgets
        Qt5Gui)