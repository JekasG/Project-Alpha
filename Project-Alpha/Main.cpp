#include "BaseWindow.h"
#include "ChildWindow.h"

int APIENTRY WinMain( HINSTANCE h_instance, HINSTANCE h_prev_instance, LPSTR lp_cmd_line, int n_cmd_show ) {

	ChildWindow child_window( h_instance, TEXT( "Child Window" ) );
	BaseWindow base_window( TEXT( "Base Window" ), child_window.ClassName() );

	while ( base_window.HandleMessages() );
	return 0;
}