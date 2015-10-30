#include "AbstractWindow.h"

AbstractWindow::AbstractWindow() {}

AbstractWindow::~AbstractWindow() {}

bool AbstractWindow::Create() {
	// Default Create Method

	hwnd_ = CreateWindowEx(
		style_ex_,
		class_name_,
		window_name_,
		style_,
		x_,
		y_,
		width_,
		height_,
		parent_,
		menu_,
		instance_,
		this
		);

	return ( hwnd_ ? true : false );

}

LRESULT CALLBACK AbstractWindow::MessageHandler( HWND hwnd, UINT message, WPARAM w_param, LPARAM l_param ) {

	AbstractWindow* abstract_window = 0;

	if ( message == WM_NCCREATE ) {
		abstract_window = ( AbstractWindow* ) ( ( LPCREATESTRUCT( l_param ) )->lpCreateParams );
		SetWindowLong( hwnd, GWL_USERDATA, long( abstract_window ) );
	}

	abstract_window = ( AbstractWindow * ) ( GetWindowLong( hwnd, GWL_USERDATA ) );

	if ( abstract_window ) {
		return abstract_window->WindowProcedure( hwnd, message, w_param, l_param );
	}
	else {
		return DefWindowProc( hwnd, message, w_param, l_param );
	}

}