# industry
Little header-only library with easy factories

## Status

Just started

## License

__Industry__ is released under the terms of zlib/png license;
see full license text in LICENSE.md file or at https://opensource.org/licenses/Zlib

## Fetch/Build/Install

    git clone git@github.com:Mezozoysky/industry.git
    cd industry
    mkdir build
    cd build
    cmake ..
    make # builds ut if BUILD_UT is set to TRUE ( by default );
         # does nothing if BUILD_UT is set to FALSE ( -DBUILD_UT:BOOL=FALSE )
    make doc # builds documentation if Doxygen is found and BUILD_DOC is set to TRUE ( by default );
             # doc target doesnt exist if Doxygen isnt found and/or BUILD_DOC is set to FALSE ( -DBUID_DOC:BOOL=FALSE )
    make install # installs into /usr/local by default ( -DCMAKE_INSTALL_PREFIX="/custom/install/prefix" )

## Use

### Way 1 (easiest)

Just grab the `Factory.hpp` and `Industry.hpp` files from industry project and put into your project's sources.

### Way 2

Include in your `CMakeLists.txt`:

    set( Industry_HOME "/path/to/industry" )
    find_package( Industry REQUIRED )

This will define following variables:

* `Industry_FOUND` - TRUE if industry is found
* `Industry_INCLUDE_DIR` - path to industry includes

## Documentation ##

One can build CMake target `doc` to generate Doxygen-based documentation.
