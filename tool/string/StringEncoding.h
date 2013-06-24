#ifndef UTIL_STRINGENCODING_H
#define UTIL_STRINGENCODING_H

#include <string>
#include <stdio.h>



namespace Util
{
	class  StringEncoding
	{
	public:
		static void unicodeToUtf8(const wchar_t* wstr,std::string& outstr);
		static void utf8ToUnicode(const char* utf8,std::wstring& woutstr);

		/** Convert  utf8 to microsoft unicode
		*/
		static std::wstring utf8ToUnicode(const char *zFilename);

		/*
		** Convert microsoft unicode to UTF-8.  Space to hold the returned string is
		** obtained from malloc().
		*/
		static std::string unicodeToUtf8(const wchar_t *zWideFilename);


		/*
		** Convert an ansi string to microsoft unicode, based on the
		** current codepage settings for file apis.
		** 
		** Space to hold the returned string is obtained
		** from malloc.
		*/
		static std::wstring mbcsToUnicode(const char *zFilename);

		/*
		** Convert microsoft unicode to multibyte character string, based on the
		** user's Ansi codepage.
		**
		** Space to hold the returned string is obtained from
		** malloc().
		*/
		static std::string unicodeToMbcs(const wchar_t *zWideFilename);


		/*
		** Convert multibyte character string to UTF-8.  Space to hold the
		** returned string is obtained from malloc().
		*/
		static std::string mbcsToUtf8(const char *zFilename);

		/*
		** Convert UTF-8 to multibyte character string.  Space to hold the 
		** returned string is obtained from malloc().
		*/
		static std::string utf8ToMbcs(const char *zFilename);

		/**
		* 把UNICODE 串输出成 转义符 " \uxxxx "
		*
		*/
		static void unicodeTransfer(std::string& out,const wchar_t* unicode , size_t buffLen );

		/**
		* 把" \uxxxx " 转义符 串输出成  unicode
		*
		*/
		static void transferUicode(std::string& out,const char* transfer , size_t buffLen );
	};
}
#endif