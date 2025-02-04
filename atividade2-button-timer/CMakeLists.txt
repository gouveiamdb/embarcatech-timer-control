# Generated CMake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(atividade2-button-timer C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(atividade2-button-timer atividade2-button-timer.c)

# Definir nome e versão do programa
pico_set_program_name(atividade2-button-timer "atividade2-button-timer")
pico_set_program_version(atividade2-button-timer "0.1")

# Habilitar saída serial USB e UART para debug
pico_enable_stdio_uart(atividade2-button-timer 1)
pico_enable_stdio_usb(atividade2-button-timer 1)

# Linkando as bibliotecas padrão do Pico SDK
target_link_libraries(atividade2-button-timer pico_stdlib hardware_gpio hardware_timer)

# Adicionando diretórios de inclusão
target_include_directories(atividade2-button-timer PRIVATE ${CMAKE_CURRENT_LIST_DIR})

# Gerar arquivos binários adicionais para upload
pico_add_extra_outputs(atividade2-button-timer)

# Adicionando suporte para gerar o firmware em .hex para o Wokwi
add_custom_command(
    TARGET atividade2-button-timer POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:atividade2-button-timer> ${CMAKE_BINARY_DIR}/atividade2-button-timer.hex
    COMMENT "Generating HEX firmware for Wokwi"
)
