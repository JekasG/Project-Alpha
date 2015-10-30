#include "BaseWindow.h"

BaseWindow::BaseWindow() {}

BaseWindow::~BaseWindow() {}

BaseWindow::BaseWindow( const TCHAR* window_name, const TCHAR* class_name ) {

	style_ex_ = NULL;
	class_name_ = class_name;
	window_name_ = window_name;
	style_ = WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
	x_ = CW_USEDEFAULT;
	y_ = CW_USEDEFAULT; CW_USEDEFAULT;
	width_ = CW_USEDEFAULT;
	height_ = CW_USEDEFAULT;
	parent_ = NULL;
	menu_ = NULL;
	instance_ = GetModuleHandle( NULL );

	Create();
	Show();

}

void BaseWindow::Show() {
	ShowWindow( hwnd_, SW_SHOW );
	UpdateWindow( hwnd_ );
}

LRESULT CALLBACK BaseWindow::WindowProcedure( HWND hwnd, UINT message, WPARAM w_param, LPARAM l_param ) {

	switch ( message ) {
		case WM_CREATE:
			box_ = new Box( 250, 250, 50, 50 );
			CreateBackBuffer(hwnd);
			return false;
		case WM_ERASEBKGND:
			return false;
		case WM_PAINT:
			return OnPaint( hwnd );
		case WM_KEYDOWN:
			return OnKeyDown( w_param );
		case WM_DESTROY:
			return OnDestroy();
		default:
			return DefWindowProc( hwnd, message, w_param, l_param );
	}
}

#pragma region Handles

bool BaseWindow::HandleMessages() {

	MSG message = { 0 };
	if ( PeekMessage( &message, NULL, 0, 0, false ) ) {
		int result = GetMessage( &message, NULL, 0, 0 );

		if ( result == -1 ) {
			// Error
			return false;
		}
		else {
			if ( message.message == WM_QUIT ) {
				return false;
			}
			TranslateMessage( &message );
			DispatchMessage( &message );
		}
	}
	return true;
}

bool BaseWindow::CreateBackBuffer( HWND hwnd ) {

	GetClientRect( hwnd, &window_rect_ );
	client_width_ = window_rect_.right;
	client_height_ = window_rect_.bottom;

	back_buffer_ = CreateCompatibleDC( NULL );	// Create Back Buffer
	hdc_ = GetDC( hwnd );	// Get the Device Context
	bitmap_ = CreateCompatibleBitmap( hdc_, client_width_, client_height_ );	// Create Bitmap
	SelectObject( back_buffer_, bitmap_ );	// Select Bitmap

	ReleaseDC( hwnd, hdc_ );	// Release

	return false;
}

bool BaseWindow::OnPaint( HWND hwnd ) {

	PAINTSTRUCT paint_struct;

	hdc_ = BeginPaint( hwnd_, &paint_struct );		// Get the Device Context

	BitBlt( back_buffer_, 0, 0, client_width_, client_height_, NULL, NULL, NULL, WHITENESS );

	// Paint
	PaintManager();

	BitBlt( hdc_, 0, 0, client_width_, client_height_, back_buffer_, 0, 0, SRCCOPY );		// Display the back buff
	InvalidateRect( hwnd, NULL, true );		// Repaint the screen

	EndPaint( hwnd, &paint_struct );

	return false;
}

bool BaseWindow::PaintManager() {

	HBRUSH brush = ( HBRUSH ) ( GetStockObject( WHITE_BRUSH ) );
	SelectObject( back_buffer_, brush );		// Select Brush

	if ( box_->InConstMode() ) {
		box_->MovementManager();
	}
	box_->DrawBox(back_buffer_);

	DeleteObject( brush );

	return false;

}

bool BaseWindow::OnKeyDown( WPARAM w_param ) {
	switch ( w_param ) {
		case VK_SPACE:
			// Set bool false so box doesnt constantly run anymore
			box_->SetInConstMode( false );
			return false;
		case VK_W:
			// W
			box_->SetConstMode( 0 );
			box_->SetInConstMode( true );
			return false;
		case VK_A:
			// A
			box_->SetConstMode( 2 );
			box_->SetInConstMode( true );
			return false;
		case VK_S:
			// S
			box_->SetConstMode( 1 );
			box_->SetInConstMode( true );
			return false;
		case VK_D:
			// D
			box_->SetConstMode( 3 );
			box_->SetInConstMode( true );
			return false;
		default:
			return false;
	}
}

bool BaseWindow::OnDestroy() {
	PostQuitMessage( 0 );
	return false;
}

#pragma endregion
