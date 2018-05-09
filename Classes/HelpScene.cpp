//
//  HelpScene.cpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#include "HelpScene.hpp"

#include "UIManager.hpp"
using namespace cocos2d;

Scene* HelpScene::createScene()
{
    return HelpScene::create();
}
bool HelpScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    CCLOG("HelpScene");
    m_layer = UIManager::CreateLayer(UIManager::SHUOMING);
    this->addChild(m_layer);
    
    return true;
}