# libtcod

libtcod is a free, fast, portable and uncomplicated API for roguelike developers providing a true color console, pathfinding, field-of-view, and a few other utilities frequently used in roguelikes.

[![Documentation Status](https://readthedocs.org/projects/libtcod/badge/?version=latest)](https://libtcod.readthedocs.io/en/latest/?badge=latest)
[![codecov](https://codecov.io/gh/libtcod/libtcod/branch/main/graph/badge.svg?token=pmHy3jXemj)](https://codecov.io/gh/libtcod/libtcod)

# Getting Started

## Using Vcpkg

This is the easiest way setup a libtcod program for a new project.
[Use this template project](https://github.com/HexDecimal/libtcod-vcpkg-template) to create a new repo with a good starting point.

From there you can modify it to suite your needs.
This template invokes [Vcpkg](https://github.com/microsoft/vcpkg) in [Manifest Mode](https://vcpkg.readthedocs.io/en/latest/users/manifests/).
The nature of Manifest Mode means that the template is always stable and portable.

Libtcod is included as a port in [Vcpkg](https://github.com/microsoft/vcpkg).
You can install libtcod via Vcpkg and then link the library using a [CMake](https://cmake.org/) script as you normally do for that package manager.

## Using a pre-built binary

This is not recommend as these releases are unwieldy, are more difficult to update, and are less cross-platform.
*Do not upload binary files to your projects source repository.*

If you are programming in C or C++ then
Windows and MacOS binaries are available from the
[GitHub Releases page](https://github.com/libtcod/libtcod/releases).

Keep in mind that as a C++ library, you may need to distribute the
appropriate runtime with your program such as the
[Visual Studio 2015 runtimes](https://www.microsoft.com/en-us/download/details.aspx?id=53587)
or else the program will fail to run.

## Compiling from source

This is only recommended for libtcod developers.
See [CONTRIBUTING.md](CONTRIBUTING.md).

# Documentation and Tutorials

The latest documentation is [here](https://libtcod.readthedocs.io/en/latest).
It is incomplete, so most people will want to read the [1.6.4 documentation](https://libtcod.github.io/docs/index2.html?c=true&cpp=true&cs=false&py=false&lua=false) instead.
Python users should use the [python-tcod documentation](http://python-tcod.readthedocs.io).

libtcod comes with a sample application, implementations of which are provided in each of
C ([samples_c.c](https://github.com/libtcod/libtcod/blob/master/samples/samples_c.c)),
C++ ([samples_cpp.cpp](https://github.com/libtcod/libtcod/blob/master/samples/samples_cpp.cpp)),
and Python ([samples_py.py](https://github.com/libtcod/python-tcod/blob/master/examples/samples_tcod.py)).
This provides a decent overview of the basic features, in an interactive fashion.
Each should be identical for the most part, so if you are using Windows, downloading the pre-compiled binaries and running the included `samples.exe` which is compiled from the C source code, should be representative of the other versions.

# Contact / Community

For reporting bugs or requesting features you should use the [GitHub Issues page](https://github.com/libtcod/libtcod/issues).
For smaller questions or help with a tutorial or project you can join ``#libtcod`` on the [Roguelikes Discord](https://discord.gg/jEgZtqB) or on the [Libera.​Chat](https://libera.chat/) IRC.

## Sponsors

[Sponsors donating $25 or more per month](https://github.com/sponsors/HexDecimal) will have their names or logos listed here.

* [q00u](https://github.com/q00u)
* [amaya30](https://github.com/amaya30)
