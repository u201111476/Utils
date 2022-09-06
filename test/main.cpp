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


int main()
{
    char str[4] = { 'a','b','1','3' };
    char str2[4] = { '2','5','r','c' };
    unsigned char p[4];
    for (int i = 0; i < 4; ++i)
    {
        p[i] = str[i] ^ str2[i];
    }
    printf("%d-%d-%d-%d\n", p[0], p[1], p[2], p[3]);
    cout<<PRODUCT_VERSION<<endl;
    return 0;
}
