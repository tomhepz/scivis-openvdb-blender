#!/bin/bash
apt-get update
# Core library
apt-get install cmake                   # CMake
apt-get install libtbb-dev              # TBB
apt-get install zlibc                   # zlib
apt-get install libboost-system-dev     # Boost::system
apt-get install libboost-iostreams-dev  # Boost::iostream
apt-get install libblosc-dev            # Blosc
# Python
apt-get install libboost-python-dev     # Boost::python
apt-get install libboost-numpy-dev      # Boost::numpy
apt-get install python-dev              # Python
apt-get install python-numpy            # NumPy
# Optional
apt-get install libpng-dev              # libpng
apt-get install libilmbase-dev          # IlmBase
apt-get install libopenexr-dev          # OpenEXR
# vdb_view
apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev #OpenGL
apt-get install libglfw3-dev            # GLFW
apt-get install libglew-dev

