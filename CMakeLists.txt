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

# Source files to be linked with OS library parts to form bootable image
set(SOURCES
  service.cpp # ...add more here
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

# STATIC LIBRARIES:
set(LIBRARIES
  # path to full library
    /Users/knatten/code/lammps/build/liblammps.a
    /Users/knatten/code/lammps/build/libmpi_stubs.a
  )


# include service build script
include($ENV{INCLUDEOS_PREFIX}/includeos/post.service.cmake)

target_include_directories(service PRIVATE /Users/knatten/code/lammps/src  /Users/knatten/code/lammps/src/STUBS)
# target_link_libraries(service /Users/knatten/code/lammps/build/liblammps.a /Users/knatten/code/lammps/build/libmpi_stubs.a)

# Create in-memory filesystem from folder
#diskbuilder(my_folder)
