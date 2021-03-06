cmake_minimum_required(VERSION 2.8.9)
if (NOT DEFINED ENV{INCLUDEOS_PREFIX})
  set(ENV{INCLUDEOS_PREFIX} /usr/local)
endif()
include($ENV{INCLUDEOS_PREFIX}/includeos/pre.service.cmake)
project (service)

# Human-readable name of your service
set(SERVICE_NAME "IncludeOS lammps-os")

# Name of your service binary
set(BINARY       "lammps-os")

set(LAMMPS_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lammps/src)
file(GLOB LIB_SOURCES ${LAMMPS_SOURCE_DIR}/*.cpp)

# Source files to be linked with OS library parts to form bootable image
set(SOURCES
  service.cpp # ...add more here
  #${LIB_SOURCES}
  )

# To add your own include paths:
# set(LOCAL_INCLUDES ".")

# DRIVERS / PLUGINS:
set(DRIVERS
  # virtionet   # Virtio networking driver
  # virtioblk   # Virtio block device driver
  #boot_logger   # Enable lots of logging from boot stage

  # Use "boot --drivers ." to see other drivers
  )

set(PLUGINS
  # syslogd    # Syslog over UDP

  # Use "boot --plugins ." to see other plugins
  )

set(LIBRARIES /repos/lammps-os/build/lammps/cmake/liblammps.a)
# STATIC LIBRARIES:
#set(LIBRARIES
  # path to full library
#  )

# include service build script
include($ENV{INCLUDEOS_PREFIX}/includeos/post.service.cmake)
add_subdirectory(lammps/cmake)
target_include_directories(service PUBLIC lammps/src lammps/src/STUBS)

#target_link_libraries(service PUBLIC lammps)

# add_subdirectory(testlib)
# target_include_directories(service PRIVATE testlib)
# target_link_libraries(service PRIVATE testlib)

# Create in-memory filesystem from folder
#diskbuilder(my_folder)
