#ifndef __HELLOWORLD_LAYER_H__
#define __HELLOWORLD_LAYER_H__

#include "cocos2d.h"

class HelloWorldLayer : public cocos2d::Layer
{
public:
    bool init();

    CREATE_FUNC(HelloWorldLayer);
};

#endif // __HELLOWORLD_LAYER_H__