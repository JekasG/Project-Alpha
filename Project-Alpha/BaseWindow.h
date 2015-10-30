#ifndef __BASEWINDOW_H__
#define __BASEWINDOW_H__
#pragma once

#include "AbstractWindow.h"
#include "ChildWindow.h"
#include "Common.h"
#include "Box.h"

class BaseWindow : public AbstractWindow {

	#pragma region Test Methods
		private:
			void Update();
			void Render();
	#pragma endregion

	#pragma region Methods
		public:
			BaseWindow();
			~BaseWindow();

			bool HandleMessages();
			BaseWindow( const TCHAR*, const TCHAR* );
			void Show();
			virtual LRESULT CALLBACK WindowProcedure( HWND, UINT, WPARAM, LPARAM );
			#pragma region Handles
				private:
					bool CreateBackBuffer( HWND );
					bool OnPaint( HWND );
					bool PaintManager();
					bool OnKeyDown( WPARAM );
					bool OnDestroy();
			#pragma endregion
	#pragma endregion

	#pragma region Variables
		private:
			RECT window_rect_;				// Structure for window width and height
			int client_width_;
			int client_height_;
			POINT mouse_pos_;
			#pragma region Back Buffer
				HDC hdc_;					// Handle to Device Context
				HDC back_buffer_;			// Back Buffer
				HBITMAP bitmap_;				// Current bitmap
			#pragma endregion
			#pragma region Box
				Box* box_;
			#pragma endregion

	#pragma endregion

};
#endif // !__BASEWINDOW_H__


