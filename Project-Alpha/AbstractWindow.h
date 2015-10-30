#ifndef __ABSTRACTWINDOW_H__
#define __ABSTRACTWINDOW_H__
#pragma once

#include <Windows.h>

class AbstractWindow {

	#pragma region Methods
		public:
			AbstractWindow();
			~AbstractWindow();

			virtual bool Create();
				static LRESULT CALLBACK MessageHandler( HWND, UINT, WPARAM, LPARAM );
			protected:
				virtual LRESULT CALLBACK WindowProcedure( HWND, UINT, WPARAM, LPARAM ) = 0;
	#pragma endregion

	#pragma region Variables
		protected:
			HWND hwnd_;
			DWORD style_ex_;
			LPCTSTR class_name_;
			LPCTSTR window_name_;
			DWORD style_;
			int x_;
			int y_;
			int width_;
			int height_;
			HWND parent_;
			HMENU menu_;
			HINSTANCE instance_;

	#pragma endregion

};
#endif // !__ABSTRACTWINDOW_H__

