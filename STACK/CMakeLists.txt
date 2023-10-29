set(sample sample_stack) #Переменная с именем приложения
set(includessrc includessrc_stack) #Переменная с именем библиотеки
set(test test_stack)

include_directories(includessrc) 
add_subdirectory(includessrc)
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории
add_subdirectory(samples)
add_subdirectory(test)

