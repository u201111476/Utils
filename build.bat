cmake.exe -S ./ -B ./build -G "Visual Studio 16 2019" -A Win32 -DMAJOR_VERSION=1
REM  cmake.exe -S ./ -B ./build -G "Visual Studio 16 2019" -A Win32 -DMAJOR_VERSION=1 -DMINOR_VERSION=2 -DPATCH_VERSION=7

cmake --build ./build --config Release