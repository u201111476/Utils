#include <iostream>
#include <Windows.h>

#include "../src/Utils.h"

using namespace std;

#ifndef MAJOR_VERSION
#define MAJOR_VERSION   0
#endif
#ifndef MINOR_VERSION
#define MINOR_VERSION   0
#endif
#ifndef PATCH_VERSION
#define PATCH_VERSION   0
#endif
#ifndef PRODUCT_VERSION
#define PRODUCT_VERSION "0.0.0"
#endif

#define MAKE_STRING(X) #X


int main()
{
    int c = Add(1, 2);
    cout << c << endl;
    return 0;
}
