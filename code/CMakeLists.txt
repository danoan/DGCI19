cmake_minimum_required(VERSION 3.2)
project(binocs-experiments)

link_directories(ext/lib)


find_package(DGtal REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(main
        src/main.cpp
        src/Application/utils.cpp
        src/Application/modes/Interactive.cpp
        )

target_compile_definitions(main PRIVATE -DPROJECT_DIR=\"${CMAKE_SOURCE_DIR}\")

target_compile_features(main PRIVATE cxx_auto_type)
target_compile_options(main PRIVATE -fext-numeric-literals)

target_include_directories(main PRIVATE
        ${DGTAL_INCLUDE_DIRS}
        ext/include
        include
        )

target_link_libraries(main
        -lbinocs-application
        -lscabolic-energy
        -lscabolic-core
        -lscabolic-optimization
        -ldipacus-derivates
        -ldipacus-components
        -ldipacus-base
        -lboost_filesystem
        -lboost_system
        ${DGTAL_LIBRARIES}
        ${OpenCV_LIBS})



#------------Illustrations---------------

add_executable(illustration
        src/illustration.cpp
        src/Illustration/AroundBoundaryReasoning.cpp
        )

target_compile_definitions(illustration PRIVATE -DPROJECT_DIR=\"${CMAKE_SOURCE_DIR}\")

target_compile_features(illustration PRIVATE cxx_auto_type)
target_compile_options(illustration PRIVATE -fext-numeric-literals)

target_include_directories(illustration PRIVATE
        ${DGTAL_INCLUDE_DIRS}
        ext/include
        include
        )

target_link_libraries(illustration
        -lbinocs-application
        -lscabolic-energy
        -lscabolic-core
        -lscabolic-optimization
        -ldipacus-derivates
        -ldipacus-components
        -ldipacus-base
        -lboost_filesystem
        -lboost_system
        ${DGTAL_LIBRARIES}
        ${OpenCV_LIBS})