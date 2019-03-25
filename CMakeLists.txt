cmake_minimum_required(VERSION 2.8.9)
project(Ping_TI)

include_directories(src/include)
file(GLOB SOURCES "src/*.cpp")

add_executable(ping_it.c ${SOURCES})

find_path( MYSQL_INCLUDE_DIR
		NAMES "mysql.h"
		PATHS "/usr/include/mysql"
			  "/usr/local/include/mysql"
			  "/usr/mysql/include/mysql" )
	
	find_library( MYSQL_LIBRARY
		NAMES "mysqlclient" "mysqlclient_r"
		PATHS "/lib/mysql"
			  "/lib64/mysql"
			  "/usr/lib/mysql"
			  "/usr/lib64/mysql"
			  "/usr/local/lib/mysql"
			  "/usr/local/lib64/mysql"
			  "/usr/mysql/lib/mysql"
			  "/usr/mysql/lib64/mysql" )
target_link_libraries (ping_it.c ${MYSQL_LIBRARY})

