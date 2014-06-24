#include "mybutton.h"

MyButton::MyButton()
{
	_binit = false;

}

void MyButton::init_button(string pic_path_down,string pic_path_move,string pic_path_normal,void (*button_event)())
{
	_button_event = button_event;
	_image_down.loadImage(pic_path_down);
	_image_move.loadImage(pic_path_move);
	_image_normal.loadImage(pic_path_normal);
	_mouse_state = 0;//normal
	_button_state = 0;//normal
	_mx = _my = 0;
	_x = _y = 0;
	_gh = _image_normal.getHeight();
	_gw = _image_normal.getWidth();
	_binit = true;
}

void MyButton::update_button(int __x,int __y)
{
	_mx = __x;
	_my = __y;
	//static bool _bpressed = false;

	if(_mx>=_x&&_mx<=_x+_gw&&_my>=_y&&_my<=_y+_gh)
	{
		/*鼠标状态机 _mouse_state:
		 *0：已经弹起；
		 *1：正在按下；
		 *2：正在弹起
		 *3：已经按下
		 ------------
		 *按钮状态机 _button_state:
		 *0:Nomal
		 *1:Move
		 *2:Down
		 */
		if(_mouse_state==1)//pressing
		{
			_button_state = 2;//down
			_mouse_state = 3;//pressed
		}
		else if(_mouse_state==2)
		{
			_button_event();
			_button_state = 1;//move
			_mouse_state = 0;
		}
		else
			if(_mouse_state!=3)
				_button_state = 1;
	}
	else
	{
		_button_state = 0;
		_mouse_state = 0;
		
	}
	
}

void MyButton::draw()
{
	//未初始化返回
	if(!_binit)
		return;

	switch(_button_state)
	{
	case 0:
		_image_normal.draw(_x,_y,_gw,_gh);
		break;
	case 1:
		_image_move.draw(_x,_y,_gw,_gh);
		break;
	case 2:
		_image_down.draw(_x,_y,_gw,_gh);
		break;
	}
}

void MyButton::set_position(int __x,int __y)
{
	_x = __x;
	_y = __y;
}
