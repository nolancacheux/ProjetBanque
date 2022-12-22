cmake_minimum_required(VERSION 3.20)

project(json)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)

if(MSVC)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options($<$<CONFIG:Release>:/MT> # Runtime library: Multi-threaded
                      $<$<CONFIG:Debug>:/MTd> # Runtime library: Multi-threaded Debug
                      )
    set(Boost_USE_STATIC_RUNTIME ON)
	set(Boost_DIR "C:/tools/Boost/lib/cmake/Boost-1.80.0")

elseif(MSVC)
    set(Boost_DIR /usr/local/lib/cmake/Boost-1.80.0)
endif (MSVC)

find_package(Boost 1.80.0 COMPONENTS json serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(bank1_src bank1.cpp)
add_executable(bank1 ${bank1_src} "bank1.cpp")
target_link_libraries (bank1 LINK_PUBLIC customer ${Boost_LIBRARIES})

set(bank2_src bank2.cpp)
add_executable(bank2 ${bank2_src} "bank2.cpp")
target_link_libraries (bank2 LINK_PUBLIC customer ${Boost_LIBRARIES})

set(bank3_src bank3.cpp)
add_executable(bank3 ${bank3_src} "bank3.cpp")
target_link_libraries (bank3 LINK_PUBLIC customer ${Boost_LIBRARIES})

set(bank4_src bank4.cpp)
add_executable(bank4 ${bank4_src} "bank4.cpp")
target_link_libraries (bank4 LINK_PUBLIC customer ${Boost_LIBRARIES})

set(central_src central.cpp)
add_executable(central ${central_src} "central.cpp")
target_link_libraries (central LINK_PUBLIC customer ${Boost_LIBRARIES})

#set(client_src client.cpp)
#add_executable(client ${client_src} "client.cpp")
#target_link_libraries (client LINK_PUBLIC customer ${Boost_LIBRARIES})

set(SRCS "client.cpp")

add_library (client ${SRCS})
target_include_directories (client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
