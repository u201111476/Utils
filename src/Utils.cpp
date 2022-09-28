#include "Utils.h"

#include <stdio.h>

int Add(int a, int b)
{
    return a + b;
}

void ExportClass::foo()
{
    printf("foo!\n");
}

std::string ExportClass::getName() const
{
    return "abc";
}

std::string N_diskUtils::GetDiskStringFromDiskIdx(int diskIdx)
{
    if (diskIdx < 0)
        return std::string();
    return std::string("") + char(65 + diskIdx) + ":\\";
}

unsigned long N_diskUtils::GetDiskFreeSpaceMB(int diskIdx)
{
    const std::string diskLetter = GetDiskStringFromDiskIdx(diskIdx);
    ULARGE_INTEGER freeSpace;
    const bool result = GetDiskFreeSpaceExA(diskLetter.c_str(), &freeSpace, nullptr, nullptr);
    if (result)
        return static_cast<unsigned long>(freeSpace.QuadPart / 1024 / 1024);
    return 0;
}

unsigned long N_diskUtils::GetDiskTotalSpaceMB(int diskIdx)
{
    const std::string diskLetter = GetDiskStringFromDiskIdx(diskIdx);
    ULARGE_INTEGER totalSpace;
    const bool result = GetDiskFreeSpaceExA(diskLetter.c_str(), nullptr, &totalSpace, nullptr);
    if (result)
        return static_cast<unsigned long>(totalSpace.QuadPart / 1024 / 1024);
    return 0;
}
