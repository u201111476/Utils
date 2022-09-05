#include "Utils.h"

#include <iostream>

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

void foo();

int main()
{
    cout<<PRODUCT_VERSION<<endl;
    return 0;
}
