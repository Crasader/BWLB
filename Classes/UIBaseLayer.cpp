//
//  UIBaseLayer.cpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#include "UIBaseLayer.hpp"
using namespace cocos2d;

bool UIBaseLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    this->onCreate();
    return true;
}
void UIBaseLayer::onEnter()
{
    Layer::onEnter();
    this->onActive();
}
void UIBaseLayer::onExit()
{
    this->onDestroy();
    Layer::onExit();
}








