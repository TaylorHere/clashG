cmake_minimum_required(VERSION 3.23)
project(clashG C)

find_package(PkgConfig REQUIRED)

#gtk4
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER})

#libadwaita
pkg_check_modules(ADW REQUIRED libadwaita-1)

include_directories(${ADW_INCLUDE_DIRS})
link_directories(${ADW_LIBRARY_DIRS})
add_definitions(${ADW_CFLAGS_OTHER})

#glib-compile-resources
find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)

set(GRESOURCE_C clashgapp.gresource.c)
set(GRESOURCE_XML resources/clashgapp.gresource.xml)

file(GLOB GRESOURCES
        "resources/ui/*.xml"
        )

add_custom_command(
        OUTPUT ${GRESOURCE_C}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${GLIB_COMPILE_RESOURCES}
        ARGS
        ${GRESOURCE_XML}
        --target=${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
        --generate-source
        VERBATIM
        MAIN_DEPENDENCY ${GRESOURCE_XML}
        DEPENDS ${GRESOURCES}
)

add_custom_target(
        clashgapp-resource
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
)

#
##glib-compile-schemas
#find_program(GLIB_COMPILE_SCHEMAS NAMES glib-compile-schemas REQUIRED)
#
#set(GSCHEMA_COMPILED_INSTALL /home/taylor/.local/share/glib-2.0/schemas)
#set(GSCHEMAS_COMPILED gchemas.compiled)
#
#file(GLOB GSCHEMAS
#        "resources/schema"
#        )
#
#add_custom_command(
#        OUTPUT ${GSCHEMAS_COMPILED}
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#        COMMAND ${GLIB_COMPILE_SCHEMAS}
#        ARGS
#        ${GSCHEMAS}
#        --targetdir=${GSCHEMA_COMPILED_INSTALL}
#        VERBATIM
#        MAIN_DEPENDENCY ${GSCHEMAS}
#        DEPENDS ${GSCHEMAS}
#)
#
#add_custom_target(
#        clashgapp-schemas
#        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${GSCHEMAS_COMPILED}
#)

set(CMAKE_C_STANDARD 99)
add_subdirectory(vendors/librequests)

include_directories(src/app src/window src/prefs)

add_executable(${PROJECT_NAME}
        ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
        src/main.c src/app/clashgapp.h src/app/clashgapp.c src/window/clashgappwin.c src/window/clashgappwin.h
        src/prefs/clashgappprefs.c src/prefs/clashgappprefs.h)

target_link_libraries(${PROJECT_NAME} librequests ${ADW_LIBRARIES} ${GTK4_LIBRARIES})

set_source_files_properties(
        ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
        PROPERTIES GENERATED TRUE
)
#set_source_files_properties(
#        ${CMAKE_CURRENT_BINARY_DIR}/${GSCHEMAS_COMPILED}
#        PROPERTIES GENERATED TRUE
#)

add_dependencies(${PROJECT_NAME} clashgapp-resource)
#add_dependencies(${PROJECT_NAME} clashgapp-schemas)