#pragma once

#ifndef _WEIJUN_UTILS_H_
#define _WEIJUN_UTILS_H_

#include <Windows.h>

#define WJ_UTILS_API __declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

WJ_UTILS_API int Add(int a, int b);


#ifdef __cplusplus
}
#endif

#endif