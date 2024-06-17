# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/ESP32/v5.2.1/esp-idf/components/bootloader/subproject"
  "D:/Developer/Esp32_code/blink_from_scratch/build/bootloader"
  "D:/Developer/Esp32_code/blink_from_scratch/build/bootloader-prefix"
  "D:/Developer/Esp32_code/blink_from_scratch/build/bootloader-prefix/tmp"
  "D:/Developer/Esp32_code/blink_from_scratch/build/bootloader-prefix/src/bootloader-stamp"
  "D:/Developer/Esp32_code/blink_from_scratch/build/bootloader-prefix/src"
  "D:/Developer/Esp32_code/blink_from_scratch/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Developer/Esp32_code/blink_from_scratch/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Developer/Esp32_code/blink_from_scratch/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
