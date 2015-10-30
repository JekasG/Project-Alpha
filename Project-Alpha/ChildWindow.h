#ifndef __CHILDWINDOW_H__
#define __CHILDWINDOW_H__
#pragma once

#include "AbstractWindow.h"
#include "BaseWindow.h"

class ChildWindow : protected WNDCLASSEX {

	#pragma region Methods
		public:
			ChildWindow();
			~ChildWindow();

			ChildWindow( HINSTANCE, const TCHAR* );
			bool Register();
			const TCHAR* ClassName() const;
	#pragma endregion

};
#endif // !__CHILDWINDOW_H__
