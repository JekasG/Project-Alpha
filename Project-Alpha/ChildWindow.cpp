#include "ChildWindow.h"

ChildWindow::ChildWindow() {}

ChildWindow::~ChildWindow() {}

ChildWindow::ChildWindow( HINSTANCE h_instance, const TCHAR* class_name ) {

	cbSize = sizeof( WNDCLASSEX );
	style = NULL;
	lpfnWndProc = AbstractWindow::MessageHandler;
	cbClsExtra = NULL;
	cbWndExtra = NULL;
	hInstance = h_instance;
	hIcon = LoadIcon( NULL, IDI_APPLICATION );
	hCursor = LoadCursor( NULL, IDC_ARROW );
	//hbrBackground = ( HBRUSH ) ( GetStockObject( DKGRAY_BRUSH ) );
	hbrBackground = ( HBRUSH ) NULL;
	lpszMenuName = NULL;
	lpszClassName = class_name;
	hIconSm = LoadIcon( NULL, IDI_APPLICATION );

	Register();
	
}

bool ChildWindow::Register() {
	return ( ( RegisterClassEx( this ) ) ? true : false );
}

const TCHAR* ChildWindow::ClassName() const {
	return lpszClassName;
}