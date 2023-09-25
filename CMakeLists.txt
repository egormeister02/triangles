cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.



project(triangle LANGUAGES CXX)				# Название проекта

#set(CMAKE_CXX20_STANDARD_COMPILE_OPTION  "-std=c++2a") 

#set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION  "-std=gnu++2a")

add_compile_options(-c -Wall -Wshadow -O2 -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE
)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

set(SOURCE_EXE main.cpp triangle.cpp)			# Установка переменной со списком исходников

#include_directories(firewall)			# Расположение заголовочных файлов

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

#add_subdirectory(firewall)				# Добавление подпроекта, указывается имя дирректории

#target_link_libraries(main Onegin)	