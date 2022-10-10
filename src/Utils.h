#pragma once

#ifndef _WEIJUN_UTILS_H_
#define _WEIJUN_UTILS_H_

#include <string>
#include <Windows.h>


#ifdef WJ_EXPORT_DLL

#define WJ_UTILS_API __declspec(dllexport)
#ifdef __cplusplus
extern "C" {
#endif

#else

#define WJ_UTILS_API
#include <vector>

#endif


	WJ_UTILS_API int Add(int a, int b);
	namespace N_diskUtils
	{
		/*!
		* @function GetDiskFreeSpaceMB
		* @brief 获取某个驱动磁盘的剩余可用空间，单位为MB
		* @param diskIdx 磁盘号对应的下标，A盘对应0，B盘对应1，C盘对应2，以此类推
		* @return diskIdx所对应的驱动盘的剩余可用空间，单位为MB
		*/
		WJ_UTILS_API unsigned long GetDiskFreeSpaceMB(int diskIdx);

		/*!
		* @function GetDiskTotalSpaceMB
		* @brief 获取某个驱动磁盘的总空间，单位为MB
		* @param diskIdx 磁盘号对应的下标，A盘对应0，B盘对应1，C盘对应2，以此类推
		* @return diskIdx所对应的驱动盘的总空间，单位为MB
		*/

		WJ_UTILS_API unsigned long GetDiskTotalSpaceMB(int diskIdx);

#ifdef WJ_EXPORT_DLL
#else
		std::string GetDiskStringFromDiskIdx(int diskIdx);
		unsigned long GetDiskFreeSpaceMB(const std::string& drive);
		unsigned long GetDiskTotalSpaceMB(const std::string& drive);
		int IsUSBDrive(const std::string& drive);
#endif
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

#ifdef WJ_EXPORT_DLL
#ifdef __cplusplus
}
#endif
#endif



#endif
