set(sample sample_queue) #Переменная с именем приложения
set(includessrc includessrc_queue) #Переменная с именем библиотеки
set(test test_queue)

include_directories(includessrc) 
add_subdirectory(includessrc)
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории
add_subdirectory(samples)
add_subdirectory(test)

