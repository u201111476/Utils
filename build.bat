cmake.exe -S ./ -B ./build -G "Visual Studio 16 2019" -A Win32 -DPRODUCT_VERSION="\"9.9.9.9\""

cmake --build ./build --config Release