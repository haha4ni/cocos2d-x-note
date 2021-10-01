#ifndef __HELLOWORLD_LAYER_H__
#define __HELLOWORLD_LAYER_H__

#include "cocos2d.h"

class HelloWorldLayer : public cocos2d::Layer
{
public:
    bool init();
    CREATE_FUNC(HelloWorldLayer);

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void update(float delta);

	enum DIRECTION
	{
		UP = 0,
		RIGHT,
		DOWN,
		LEFT,
		DIRECTION_NUM
	};

	cocos2d::Sprite* sprite;
	int sprite_velocity_x = 0;
	int sprite_velocity_y = 0;
	cocos2d::Animation* animation[DIRECTION_NUM];
	cocos2d::Animate* animate[DIRECTION_NUM];
};

#endif // __HELLOWORLD_LAYER_H__