# scivis-openvdb-sample
Template for creating and then rendering OpenVDB scientific voxel data in Blender (cycles) for beautiful visualisations.

## Requirements
1) Text editor / C++ IDE (Visual Studio, CLion, etc...)
2) C++ Compiler (g++ / clang++) (often bundled with IDE)
3) OpenVDB build (with python support if using python)
4) Blender

## Generic Steps
1) Edit C++ file `main.cpp` to create `*.vdb` files using OpenVDB library
2) Compile code `g++ main.cpp`
3) Run to create `*.vdb` files
4) Import `*.vdb` files into blender
5) Shade with shader nodes
6) Render with cycles

## Using helper tools
### Easy raytrace plot for debugging
Adjusting parameters as necessary
```bash
vdb_render myvoxels.vdb out.exr \
  -translate 160,0,0 -absorb 0.0001,0.0001,0.0001 \
  -gain 0.01 -scatter 0.003,0.004,0.006 \
  -light 0.5,0.5,0,1,1,1
```

### Voxel viewer with x,y,z endpoint shifts to look into volume
```bash
# View controls
vdb_view -h 
vdb_view myvoxels.vdb
```

## Installation
This section contains some useful snipets to help with installation *on specific operating systems*. These may depend on your own Operating system, and software versions. Please refer to the installation instructions by the original software provider.

### OpenVDB Package Managed Install on Linux
```bash
sudo apt-get update
sudo apt-get libopenvdb-dev
sudo apt-get libopenvdb-tools
sudo apt-get python3-openvdb
```

### OpenVDB Package Managed Install on Mac
Caveat: This does not come with the helper viewing tools, or python package. If needed, build from source.
```bash
brew update
brew install openvdb
```

### Manual OpenVDB build
See 'Building Standalone' section and then 'Building with OpenVDB' section of:
https://www.openvdb.org/documentation/doxygen/build.html

```bash
# Install Build Dependencies
sudo apt-get update
# Core library
sudo apt-get install cmake                   # CMake
sudo apt-get install libtbb-dev              # TBB
sudo apt-get install zlibc                   # zlib
sudo apt-get install libboost-system-dev     # Boost::system
sudo apt-get install libboost-iostreams-dev  # Boost::iostream
sudo apt-get install libblosc-dev            # Blosc
# Python
sudo apt-get install libboost-python-dev     # Boost::python
sudo apt-get install libboost-numpy-dev      # Boost::numpy
sudo apt-get install python-dev              # Python
sudo apt-get install python-numpy            # NumPy
# Optional
sudo apt-get install libpng-dev              # libpng
sudo apt-get install libilmbase-dev          # IlmBase
sudo apt-get install libopenexr-dev          # OpenEXR
# vdb_view
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev #OpenGL
sudo apt-get install libglfw3-dev            # GLFW
sudo apt-get install libglew-dev

# To build OpenVDB (and python module, and helper binaries)
# after downloading from https://github.com/AcademySoftwareFoundation/openvdb/releases
# and extracting and cd'ing into folder...
mkdir build
cd build

cmake -D OPENVDB_BUILD_VDB_PRINT=ON \
      -D OPENVDB_BUILD_VDB_RENDER=ON \
      -D OPENVDB_BUILD_VDB_VIEW=ON \
      -D OPENVDB_BUILD_PYTHON_MODULE=ON \
      ../

make -j4

sudo make install
```

### Manual OpenVDB build on Mac
See 'Building Standalone' section and then 'Building with OpenVDB' section of:
https://www.openvdb.org/documentation/doxygen/build.html

```bash
# Install Build Dependencies
# Core library
brew install cmake                     # CMake
brew install ilmbase                   # IlmBase
brew install openexr                   # OpenEXR
brew install tbb                       # TBB
brew install zlib                      # zlib
brew install boost                     # Boost
# Python
brew install boost-python3              # Boost-python
brew install python                    # Python
brew install numpy                     # NumPy
# vdb_view
brew install glfw                      # GLFW
brew install glew

# To build OpenVDB (and python module, and helper binaries)
# after downloading from https://github.com/AcademySoftwareFoundation/openvdb/releases
# and extracting and cd'ing into folder...
mkdir build
cd build

cmake -D OPENVDB_BUILD_VDB_PRINT=ON \
      -D OPENVDB_BUILD_VDB_RENDER=ON \
      -D OPENVDB_BUILD_VDB_VIEW=ON \
      -D OPENVDB_BUILD_PYTHON_MODULE=ON \
      ../

make -j4

sudo make install
```

## Useful Links
### Editors
- https://visualstudio.microsoft.com/
- https://www.jetbrains.com/clion/

### Package Managed install
#### Windows (vcpkg)
- https://github.com/microsoft/vcpkg
- https://vcpkg.info/port/openvdb
#### Mac (homebrew)
- https://brew.sh
- https://formulae.brew.sh/formula/openvdb
#### Linux (apt)
- https://packages.ubuntu.com/
- https://packages.ubuntu.com/jammy/libopenvdb-dev
- https://packages.ubuntu.com/jammy/libopenvdb8.1
- https://packages.ubuntu.com/jammy/libopenvdb-tools
- https://packages.ubuntu.com/jammy/python3-openvdb

### OpenVDB
- https://www.openvdb.org/
- https://github.com/AcademySoftwareFoundation/openvdb/
- https://github.com/AcademySoftwareFoundation/openvdb/releases
- https://academysoftwarefoundation.github.io/openvdb/

### Blender
- https://www.blender.org/

### Past work
- https://www.researchgate.net/publication/282981374_Visualization_of_molecular_properties_at_the_qantum_mechanical_level_using_blender

### Original Question
- https://blender.stackexchange.com/questions/139632/visualizing-3d-voxel-data-in-blender-2-8?noredirect=1&lq=1

### History of blender volumes
- https://www.youtube.com/watch?v=4w8_SBxCOxo
