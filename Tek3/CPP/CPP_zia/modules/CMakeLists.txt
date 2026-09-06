cmake_minimum_required(VERSION 3.10)
project(Zia)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
set(RUNTIME_OUTPUT_DIRECTORY build)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

## Path Variable
set(PATH_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/)
set(PATH_SRC ${CMAKE_CURRENT_SOURCE_DIR}/)

######################################
## All Path to CPP Header files
# INCLUDES:
include_directories(
    ${PATH_INCLUDES}
    ${PATH_INCLUDES}../modules/handler_wrapper/
    ${PATH_INCLUDES}../sources/
    ${PATH_INCLUDES}../sources/api/modules/
)


## All CPP Sources files
# SOURCES FOR EACH MODULES:
set(SOURCES_MODULE_CONNECTIONWRAPPER
    ${PATH_SRC}/connection_wrapper/sources/Main.cpp
    ${PATH_SRC}/connection_wrapper/sources/ConnectionWrapper.cpp
    ${PATH_SRC}/connection_wrapper/sources/ConnectionSSL.cpp
    ${PATH_SRC}/connection_wrapper/sources/ConnectionHttp.cpp
    ${PATH_SRC}../sources/exception/AException.cpp
    ${PATH_SRC}../sources/api/io/Connection.cpp
)

set(SOURCES_MODULE_HANDLER
    ${PATH_SRC}/handler/sources/Main.cpp
)

set(SOURCES_MODULE_LOGGER
    ${PATH_SRC}/logger/sources/Main.cpp
)

set(SOURCES_MODULE_PARSER
    ${PATH_SRC}/parser/sources/Main.cpp
    ${PATH_SRC}/parser/sources/Instance.cpp
    ${PATH_SRC}/parser/sources/Parser.cpp
    ${PATH_SRC}../sources/api/context/Request.cpp
    ${PATH_SRC}../sources/exception/AException.cpp
)

if(WIN32)
    set(SOURCES_MODULE_CONNECTIONWRAPPER
        ${SOURCES_MODULE_CONNECTIONWRAPPER}
        ${PATH_SRC}../sources/api/modules/Logger.cpp
    )
    set(SOURCES_MODULE_PARSER
        ${SOURCES_MODULE_PARSER}
        ${PATH_SRC}../sources/api/config/Conf.cpp
        ${PATH_SRC}../sources/api/config/Json.cpp
        ${PATH_SRC}../sources/api/context/Context.cpp
        ${PATH_SRC}../sources/api/context/Response.cpp
        ${PATH_SRC}../sources/api/io/Connection.cpp
        ${PATH_SRC}../sources/api/modules/Logger.cpp
        ${PATH_SRC}../sources/client/Client.cpp
        ${PATH_SRC}../sources/core/Core.cpp
        ${PATH_SRC}../sources/loader/ManagerSharedObject.cpp
        ${PATH_SRC}../sources/pipeline/PipelineHandlers.cpp
        ${PATH_SRC}../sources/server/ServerNetwork.cpp
    )
endif(WIN32)

set(SOURCES_MODULE_PHPCGI
    ${PATH_SRC}/handler_wrapper/HandlerWrapper.cpp
    ${PATH_SRC}/php_cgi/sources/Main.cpp
    ${PATH_SRC}/php_cgi/sources/PhpCgi.cpp
)

set(SOURCES_MODULE_HTMLHANDLER
    ${PATH_SRC}/handler_wrapper/HandlerWrapper.cpp
    ${PATH_SRC}/html_handler/sources/Main.cpp
    ${PATH_SRC}/html_handler/sources/HtmlHandler.cpp
)

set(SOURCES_MODULE_PNGHANDLER
    ${PATH_SRC}/handler_wrapper/HandlerWrapper.cpp
    ${PATH_SRC}/png_handler/sources/Main.cpp
    ${PATH_SRC}/png_handler/sources/PngHandler.cpp
)

set(SOURCES_MODULE_FILEEXPLORER
    ${PATH_SRC}/handler_wrapper/HandlerWrapper.cpp
    ${PATH_SRC}/file_explorer/sources/Main.cpp
    ${PATH_SRC}/file_explorer/sources/FileExplorer.cpp
)

set(SOURCES_MODULE_HEADREQUESTHANDLER
    ${PATH_SRC}/head_request_handler/sources/Main.cpp
    ${PATH_SRC}/head_request_handler/sources/HeadRequestHandler.cpp
)

set(SOURCES_MODULE_DELETEREQUESTHANDLER
    ${PATH_SRC}/handler_wrapper/HandlerWrapper.cpp
    ${PATH_SRC}/delete_request_handler/sources/Main.cpp
    ${PATH_SRC}/delete_request_handler/sources/DeleteRequestHandler.cpp
)

set(SOURCES_MODULE_POSTREQUESTHANDLER
    ${PATH_SRC}/handler_wrapper/HandlerWrapper.cpp
    ${PATH_SRC}/post_request_handler/sources/Main.cpp
    ${PATH_SRC}/post_request_handler/sources/PostRequestHandler.cpp
)

add_library(ModuleConnectionWrapper SHARED ${SOURCES_MODULE_CONNECTIONWRAPPER})
add_library(ModuleHandler SHARED ${SOURCES_MODULE_HANDLER})
add_library(ModuleLogger SHARED ${SOURCES_MODULE_LOGGER})
add_library(ModuleParser SHARED ${SOURCES_MODULE_PARSER})
add_library(ModulePhpCgi SHARED ${SOURCES_MODULE_PHPCGI})
add_library(ModuleHtmlHandler SHARED ${SOURCES_MODULE_HTMLHANDLER})
add_library(ModulePngHandler SHARED ${SOURCES_MODULE_PNGHANDLER})
add_library(ModuleFileExplorer SHARED ${SOURCES_MODULE_FILEEXPLORER})
add_library(ModuleHeadRequestHandler SHARED ${SOURCES_MODULE_HEADREQUESTHANDLER})
add_library(ModuleDeleteRequestHandler SHARED ${SOURCES_MODULE_DELETEREQUESTHANDLER})
add_library(ModulePostRequestHandler SHARED ${SOURCES_MODULE_POSTREQUESTHANDLER})

target_link_libraries(ModuleConnectionWrapper ${CONAN_LIBS})
target_link_libraries(ModuleParser ${CONAN_LIBS})
