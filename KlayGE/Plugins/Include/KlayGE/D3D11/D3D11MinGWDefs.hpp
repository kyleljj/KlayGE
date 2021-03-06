// D3D10MinGWDefs.hpp
// KlayGE 让MinGW能使用D3D10的一些定义 头文件
// Ver 3.8.0
// 版权所有(C) 龚敏敏, 2008
// Homepage: http://www.klayge.org
//
// 3.8.0
// 初次建立 (2008.10.10)
//
// 修改记录
/////////////////////////////////////////////////////////////////////////////////

#ifndef _D3D11MINGWDEFS_HPP
#define _D3D11MINGWDEFS_HPP

#pragma once

#if defined(KLAYGE_COMPILER_GCC) || defined(KLAYGE_COMPILER_CLANG)
	#define __bcount(size)
	#define __in
	#define __in_ecount(size)
	#define __out
	#define __out_ecount(size)
	#define __out_bcount(size)
	#define __inout
	#define __in_bcount(size)
	#define __in_opt
	#define __in_ecount_opt(size)
	#define __in_bcount_opt(size)
	#define __out_opt
	#define __out_ecount_opt(size)
	#define __out_bcount_opt(size)
	#define __inout_opt
	#define __out_ecount_part_opt(size,length)
	#define __in_xcount_opt(size) 

	#define WINAPI_INLINE  WINAPI

	typedef unsigned char UINT8;
#endif

#endif			// _D3D11MINGWDEFS_HPP
