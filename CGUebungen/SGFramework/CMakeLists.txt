cmake_minimum_required(VERSION 3.8)
project("SGFrameworkLib")

set(CMAKE_PREFIX_PATH  "C:/Qt/6.2.0/msvc2019_64/lib/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build the doxygen library? TODO
option(BUILD_DOC "Build documentation" OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets OpenGL Multimedia Xml Concurrent OpenGLWidgets REQUIRED)

file(GLOB src_project "${PROJECT_SOURCE_DIR}/*.cpp")
#VPN Quellen fuer DTrack entfernen
list(FILTER src_project EXCLUDE REGEX ".*trackinginput.cpp$")
list(FILTER src_project EXCLUDE REGEX ".*flystickinput.cpp$")
list(FILTER src_project EXCLUDE REGEX ".*dtrackcameracontroller.cpp$")

file(GLOB header_project "${PROJECT_SOURCE_DIR}/*.h")
file(GLOB ui_project "*${PROJECT_SOURCE_DIR}/.ui")
file(GLOB qrc_project "${PROJECT_SOURCE_DIR}/*.qrc")
qt_add_resources(qrcfiles ${qrc_project})
#qt_wrap_ui(uifiles ${ui_project})

message("CMAKE: ${CMAKE_SOURCE_DIR}")
message("CMAKE: ${PROJECT_SOURCE_DIR}")

#Zielordner finden und setzen, CMAKE Ordner ausschlie�en, sonst findet man unter Windows im build-Dir
find_path(where_is_lib NAMES "SGFrameworkLib" 
PATHS 
"${CMAKE_SOURCE_DIR}/../../../"
"${CMAKE_SOURCE_DIR}/../.."
"${CMAKE_SOURCE_DIR}/.." 
"${CMAKE_SOURCE_DIR}" 
NO_CACHE
REQUIRED
NO_DEFAULT_PATH
NO_PACKAGE_ROOT_PATH
NO_CMAKE_PATH
NO_CMAKE_ENVIRONMENT_PATH
NO_SYSTEM_ENVIRONMENT_PATH
NO_CMAKE_SYSTEM_PATH)

message("Found Lib path in ${where_is_lib}/SGFrameworkLib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${where_is_lib}/SGFrameworkLib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${where_is_lib}/SGFrameworkLib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${where_is_lib}/SGFrameworkLib")

file(GLOB header_physics "${where_is_lib}/PhysicPackage/physics/*.h")
file(GLOB header_sgf "${where_is_lib}/SGFramework/*.h")
file(GLOB header_bullet "${where_is_lib}/PhysicPackage/BulletPhysics/*.h")
file(GLOB header_audio "${where_is_lib}/AudioPackage/audio/*.h")
file(GLOB_RECURSE header_openal "${where_is_lib}/AudioPackage/OpenALSoft/*.h")

file(GLOB header_bullet "${where_is_lib}/PhysicPackage/BulletPhysics/*.h")
include_directories("${where_is_lib}/PhysicPackage/physics" 
        "${where_is_lib}/PhysicPackage/BulletPhysics"
        "${where_is_lib}/AudioPackage/audio"
        "${where_is_lib}/AudioPackage/OpenALSoft/include"
        "${where_is_lib}/AudioPackage/OpenALSoft/include/AL"
        "${where_is_lib}/SGFramework" )

file(GLOB_RECURSE src_physics "${where_is_lib}/PhysicPackage/physics/*.cpp")
file(GLOB_RECURSE src_bullet "${where_is_lib}/PhysicPackage/BulletPhysics/*.cpp")
list(FILTER src_bullet EXCLUDE REGEX ".*/GpuSoftBodySolvers/.*")

file(GLOB src_audio "${where_is_lib}/AudioPackage/audio/*.cpp")

add_library(SGFrameworkLib ${src_project} ${header_project} ${uifiles}   ${qrcfiles}
        ${header_physics} ${header_bullet} ${header_audio} ${header_openal} ${src_physics} ${src_bullet} ${src_audio} )
target_link_libraries(SGFrameworkLib Qt6::Widgets Qt6::Core Qt6::Gui Qt6::OpenGL Qt6::Multimedia Qt6::Xml Qt6::Concurrent Qt6::OpenGLWidgets)

#Kein VRPN verwenden
target_compile_definitions(SGFrameworkLib PUBLIC SG_NO_VRPN)

#OpenAL Library-Pfad
if(MSVC)
        target_compile_definitions(SGFrameworkLib PUBLIC LIBDIR="${where_is_lib}/AudioPackage/OpenALSoft/dll/Win64/")
        target_compile_definitions(SGFrameworkLib PUBLIC __BT_SKIP_UINT64_H)
else()
        target_compile_definitions(SGFrameworkLib PUBLIC LIBDIR="/usr/lib/x86_64-linux-gnu")
endif()

message("Copy headers to lib directory ... ${where_is_lib}/SGFrameworkLib/")
add_custom_command(
        TARGET SGFrameworkLib  PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${header_project} ${header_physics} ${header_audio} ${header_openal}
                ${where_is_lib}/SGFrameworkLib/)
