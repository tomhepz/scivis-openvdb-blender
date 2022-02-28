# scivis-openvdb-sample
Template for creating and then rendering OpenVDB scientific voxel data in Blender (cycles) for beautiful visualisations.

## Requirements
1) Text editor / C++ IDE (Visual Studio, CLion, etc...)
2) C++ Compiler (g++ / clang++) (often bundled with IDE)
3) OpenVDB build from source (with python support if using python)
4) Blender
5) Linux preferred / MacOS possible / Windows Hard

## Generic Steps
1) Edit C++ file `main.cpp` to create `*.vdb` files using OpenVDB library
2) Compile code `g++ main.cpp`
3) Run to create `.vdb` files
4) Import `.vdb` files into blender
5) Shade with shader nodes
6) Render with cycles

## Installation
This section contains some useful snipets to help with installation *on specific operating systems*. These may depend on your own Operating system, and software versions. Please refer to the installation instructions by the original software provider.

### OpenVDB build on Linux with apt
See 'Building Standalone' section and then 'Building with OpenVDB' section of:
https://www.openvdb.org/documentation/doxygen/build.html

```bash
# Install Build Dependencies
# Check script! (you're sudo-ing it)
chmod +x ./dependencyinstallapt.sh
sudo ./dependencyinstall.sh
```

```bash
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

make install
```

### OpenVDB build on MacOS with homebrew
See 'Building Standalone' section and then 'Building with OpenVDB' section of:
https://www.openvdb.org/documentation/doxygen/build.html

## Useful Links
### Editors
- https://visualstudio.microsoft.com/
- https://www.jetbrains.com/clion/

### Package Managed install
- https://github.com/microsoft/vcpkg
- https://formulae.brew.sh/formula/openvdb

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
