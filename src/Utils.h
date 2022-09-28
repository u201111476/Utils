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
	namespace N_diskUtils
	{
		WJ_UTILS_API unsigned long GetDiskFreeSpaceMB(int diskIdx);
		WJ_UTILS_API unsigned long GetDiskTotalSpaceMB(int diskIdx);
		std::string GetDiskStringFromDiskIdx(int diskIdx);
	}
	class WJ_UTILS_API ExportClass
	{
	private:
		int x;
		std::string name;
	public:
		void foo();
		std::string getName() const;
	};
#ifdef __cplusplus
}
#endif



#endif
