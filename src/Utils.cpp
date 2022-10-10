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

unsigned long N_diskUtils::GetDiskFreeSpaceMB(const std::string& drive)
{
    ULARGE_INTEGER freeSpace;
    const bool result = GetDiskFreeSpaceExA(drive.c_str(), &freeSpace, nullptr, nullptr);
    if (result)
        return static_cast<unsigned long>(freeSpace.QuadPart / 1024 / 1024);
    return 0;
}

unsigned long N_diskUtils::GetDiskTotalSpaceMB(const std::string& drive)
{
    ULARGE_INTEGER totalSpace;
    const bool result = GetDiskFreeSpaceExA(drive.c_str(), nullptr, &totalSpace, nullptr);
    if (result)
        return static_cast<unsigned long>(totalSpace.QuadPart / 1024 / 1024);
    return 0;
}

int N_diskUtils::IsUSBDrive(const std::string& drive)
{
    HANDLE hDevice{NULL};
    BOOL result{0};
    DWORD readed{0};
    STORAGE_DESCRIPTOR_HEADER* pDevDescHeader{nullptr};
    STORAGE_DEVICE_DESCRIPTOR* pDevDesc{nullptr};
    DWORD devDescLength{0};
    STORAGE_PROPERTY_QUERY query{};
    int retCode{ 0 };

    char volumeName[8] = "";
    char* volumeFormat = "\\\\.\\%c:";
    sprintf(volumeName, volumeFormat, drive[0]);
    hDevice = CreateFile(volumeName, NULL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
        OPEN_EXISTING, 0, NULL);
    if (hDevice == INVALID_HANDLE_VALUE)
    {
        retCode = -1;
        goto end;
    }
    query.PropertyId = StorageDeviceProperty;
    query.QueryType = PropertyStandardQuery;
    pDevDescHeader = (STORAGE_DESCRIPTOR_HEADER*)malloc(sizeof(STORAGE_DESCRIPTOR_HEADER));
    if (nullptr == pDevDescHeader)
    {
        retCode = -2;
        goto end;
    }

    result = DeviceIoControl(hDevice, IOCTL_STORAGE_QUERY_PROPERTY, &query, sizeof(query), pDevDescHeader,
        sizeof(STORAGE_DESCRIPTOR_HEADER), &readed, NULL);

    if (!result)
    {
        retCode = -3;
        goto end;
    }
    devDescLength = pDevDescHeader->Size;
    pDevDesc = (STORAGE_DEVICE_DESCRIPTOR*)malloc(devDescLength);
    if (NULL == pDevDesc)
    {
        retCode = -4;
        goto end;
    }

    result = DeviceIoControl(hDevice, IOCTL_STORAGE_QUERY_PROPERTY, &query, sizeof(query), pDevDesc,
        devDescLength, &readed, NULL);
    if (!result)
    {
        retCode = -5;
        goto end;
    }
    WORD type = (WORD)pDevDesc->BusType;
    if (type == BusTypeUsb)
        retCode = 1;
end:
    if(pDevDesc)
        free(pDevDesc);
    if(pDevDescHeader)
        free(pDevDescHeader);
    if(hDevice!=INVALID_HANDLE_VALUE)
        CloseHandle(hDevice);
    return retCode;
}

unsigned long N_diskUtils::GetDiskFreeSpaceMB(int diskIdx)
{
    const std::string drive = GetDiskStringFromDiskIdx(diskIdx);
    return GetDiskFreeSpaceMB(drive);
}

unsigned long N_diskUtils::GetDiskTotalSpaceMB(int diskIdx)
{
    const std::string drive = GetDiskStringFromDiskIdx(diskIdx);
    return GetDiskTotalSpaceMB(drive);
}
