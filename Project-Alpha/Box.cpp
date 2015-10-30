#include "Box.h"

#pragma region Accessor
bool Box::InConstMode() const {
	return in_const_mode_;
}
#pragma endregion
#pragma region Mutator
void Box::SetConstMode( int const_mode ) {
	const_mode_ = const_mode;
}
void Box::SetInConstMode( bool in_const_mode ) {
	in_const_mode_ = in_const_mode;
}
#pragma endregion


Box::Box() {}

Box::~Box() {}

Box::Box( int x, int y, int width, int height ) {
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
}

void Box::MovementManager() {
	switch ( const_mode_ ) {
		case UP:
			MoveUp();
			break;
		case DOWN:
			MoveDown();
			break;
		case LEFT:
			MoveLeft();
			break;
		case RIGHT:
			MoveRight();
			break;
		default:
			break;
	}
}

void Box::MoveUp() {
	y_ -= 1;
}

void Box::MoveDown() {
	y_ += 1;
}

void Box::MoveLeft() {
	x_ -= 1;
}

void Box::MoveRight() {
	x_ += 1;
}

void Box::DrawBox(HDC hdc) {
	Rectangle( hdc, x_, y_, x_ + width_, y_ + height_ );
}