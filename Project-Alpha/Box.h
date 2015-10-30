#ifndef __BOX_H__
#define __BOX_H__
#pragma once

#include <Windows.h>

class Box {
	#pragma region Methods
		public:
			#pragma region Accessor
				bool InConstMode() const;
			#pragma endregion
			#pragma region Mutator
				void SetConstMode( int );
				void SetInConstMode( bool );
			#pragma endregion

			Box();
			~Box();
			Box( int, int, int, int );

			void MovementManager();
			void DrawBox( HDC );
		private:
			void MoveUp();
			void MoveDown();
			void MoveLeft();
			void MoveRight();
	#pragma endregion
	#pragma region Variables
		private:
		int x_;
		int y_;
		int width_;
		int height_;

		enum ConstMode {
			UP,
			DOWN,
			LEFT,
			RIGHT
		};
		int const_mode_;
		bool in_const_mode_;
	#pragma endregion
};
#endif // !__BOX_H__