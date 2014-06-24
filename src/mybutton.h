#pragma once
#include "ofMain.h"
//Í¼Æ¬°´Å¥
class MyButton
{
public:
	MyButton();
	void init_button(string pic_path_down,string pic_path_move,string pic_path_normal,void (*button_event)());
	void update_button(int,int);
	void draw();
	void set_position(int __x,int __y);
	inline void set_mouse_state(int mx,int my,int _state)
	{
		_mouse_state = _state;
		_mx = mx;
		_my = my;
	}

private:
	bool _binit;
	ofImage _image_down;
	ofImage _image_move;
	ofImage _image_normal;
	void (*_button_event)();
	int _gw;
	int _gh;
	int _mouse_state;
	int _button_state;
	int _mx;
	int _my;
	int _x;
	int _y;

};

