//
//  GoLayer.cpp
//  luobo
//
//  Created by student on 18/5/10.
//
//

#include "GoLayer.hpp"
#include "CocoStudio.h"
#include "SceneManager.hpp"
using namespace cocos2d;

void GoLayer::onCreate()
{
    FileUtils::getInstance()->addSearchPath("mystudio");
    auto node = CSLoader::createNode("ChapterLayer_01.csb");
    CCLOG("GoLayer");
    this->addChild(node);
    
    auto action = CSLoader::createTimeline("ChapterLayer_01.csb");
    action->gotoFrameAndPlay(0,180,true);
    node->runAction(action);
    
    m_sp3 = Sprite::create("countdown_01.png");
    m_sp3->setPosition(Vec2(240,180));
    this->addChild(m_sp3);
    int i = 1;
    this->schedule([=](float dt)mutable{
        char str[50];
        sprintf(str,"countdown_%02d.png",++i);
        m_sp3->setTexture(str);
        if(i == 5)
        {
            SceneMannger::gotoLevel1Scene();
        }
    },1.0,3,1,"3");

}
void GoLayer::onDestroy()
{
    this->unschedule("3");
}