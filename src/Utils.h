#pragma once

#ifndef _WEIJUN_UTILS_H_
#define _WEIJUN_UTILS_H_

#include <string>
#include <Windows.h>

#define WJ_UTILS_API __declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

	WJ_UTILS_API int Add(int a, int b);
	WJ_UTILS_API unsigned long GetDiskFreeSpaceMB(int diskIdx);
	WJ_UTILS_API unsigned long GetDiskTotalSpaceMB(int diskIdx);
#ifdef __cplusplus
}
#endif
std::string GetDiskStringFromDiskIdx(int diskIdx);
#endif
