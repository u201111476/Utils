#include <iostream>
#include <Windows.h>

#include "../src/Utils.h"

#include <vector>

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
    //int c = Add(1, 2);
    //unsigned long freeSpace = N_diskUtils::GetDiskFreeSpaceMB(2);            //A盘符index为0，B盘符为1，依次类推
    //cout << freeSpace << endl;
    //unsigned long totalSpace = N_diskUtils::GetDiskTotalSpaceMB(2);
    //cout << totalSpace << endl;
    //cout << c << endl;

    char buf[MAX_PATH] = {};
    DWORD size = GetLogicalDriveStringsA(MAX_PATH - 1, buf);
    vector<std::string> diskDrives;
    int idx = 0;
    while (idx < size)
    {
        std::string drive = buf + idx;
        diskDrives.push_back(drive);
        idx += drive.length() + 1;
    }
    for (int i = 0; i < diskDrives.size(); ++i)
    {
        cout << diskDrives[i][0] << "disk's total space is:" << N_diskUtils::GetDiskTotalSpaceMB(diskDrives[i][0] - 'A') << "MB" << endl;
    }
    //ExportClass ec;
    //ec.foo();
    //cout << ec.getName() << endl;
    return 0;
}
