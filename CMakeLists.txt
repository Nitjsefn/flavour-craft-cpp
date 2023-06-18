cmake_minimum_required(VERSION 3.16)

project(FlavorCraft VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

set(RESOURCES assets.qrc)
qt6_add_resources(QT_RESOURCES ${RESOURCES})

qt_standard_project_setup()

qt_add_executable(appFlavorCraft
    main.cpp

    cpp_components/dish/dish.h
    cpp_components/dish/dish.cpp

    cpp_components/localSearchManager/localsearchmanager.h
    cpp_components/localSearchManager/localsearchmanager.cpp

    cpp_components/systemManager/systemManager.h
    cpp_components/systemManager/systemManager.cpp

    cpp_components/recipeRestHandler/recipeRestHandler.cpp
    cpp_components/recipeRestHandler/recipeRestHandler.h

    cpp_components/webRecipeSearch/webRecipeSearch.cpp
    cpp_components/webRecipeSearch/webRecipeSearch.h

    cpp_components/webRecipeScraper/webRecipeScraper.cpp
    cpp_components/webRecipeScraper/webRecipeScraper.h

    cpp_components/stringBuilder/stringBuilder.cpp
    cpp_components/stringBuilder/stringBuilder.h

    cpp_components/webRecipeGetter/webRecipeGetter.cpp
    cpp_components/webRecipeGetter/webRecipeGetter.h

    ${QT_RESOURCES}
)

qt_add_qml_module(appFlavorCraft
    URI FlavorCraft
    VERSION 1.0
    QML_FILES Main.qml
)

set_target_properties(appFlavorCraft PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appFlavorCraft
    PRIVATE Qt6::Quick
)

install(TARGETS appFlavorCraft
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
#silent credits: febru, tatiana, krzak
