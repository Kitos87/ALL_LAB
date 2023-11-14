set(sample sample_arithmexpress) #Переменная с именем приложения
set(includessrc includessrc_arithmexpress) #Переменная с именем библиотеки
set(test test_arithmexpress)

include_directories(includessrc) 
add_subdirectory(includessrc)
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории
add_subdirectory(samples)
add_subdirectory(test)
add_subdirectory(GUI)
