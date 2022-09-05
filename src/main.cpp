#include "Utils.h"

#include <iostream>

using namespace std;

#ifndef PRODUCT_VERSION
#define PRODUCT_VERSION "0.0.0.0"
#endif

int main()
{
    cout<<"Hello world "<< PRODUCT_VERSION << "!" <<endl;
    return 0;
}