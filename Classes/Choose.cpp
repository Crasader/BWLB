//
//  Choose.cpp
//  luobo
//
//  Created by student on 18/5/9.
//
//

#include "Choose.hpp"
#include "UIManager.hpp"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SceneManager.hpp"
#include "GoLayer.hpp"
using namespace cocos2d;
int ChooseLayer::A = 1;
void ChooseLayer::onCreate()
{
    FileUtils::getInstance()->addSearchPath("studio/chapter1");
    
    auto node = CSLoader::createNode("level1xuanze.csb");
    CCLOG("ChooseLayer");
    this->addChild(node);
    
    m_node = node->getChildByName("Node_1");
    
//    auto sp = Sprite::create("bird.png");
//    sp->setPosition(Vec2(10,20));
//    this->addChild(sp);
    //开始按钮
    auto btn1 = static_cast<ui::Button*>(m_node->getChildByName("Button_3"));
    btn1->addClickEventListener([=](Ref*){
//        SceneMannger::gotoLevel1Scene();
       auto layer = GoLayer::create();
        this->addChild(layer);
    });
    
    auto btn_fanhui = static_cast<ui::Button*>(node->getChildByName("Button_1"));
    btn_fanhui->addClickEventListener([=](Ref*){
        auto layer = UIManager::CreateLayer(UIManager::MAOXIAN);
        this->addChild(layer);
    });
    
    
    m_sp = Sprite::create("ss_towers_01.png");
    m_sp->setPosition(Vec2(240, 90));
    this->addChild(m_sp);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [=](Touch* touch,Event* event)->bool{
        m_touchPos = touch->getLocation();
        if (m_touchPos.x > 240 )
        {
            ++A;
            m_node->setPositionX(m_node->getPosition().x-200);
        }
        if (m_touchPos.x < 240 )
        {
            --A;
            m_node->setPositionX(m_node->getPosition().x+200);
        }

        towers();
        return true;
    };
    auto director = Director::getInstance();
    auto dispatcher = director->getEventDispatcher();
    
    dispatcher->addEventListenerWithSceneGraphPriority(listener,this);

}
void ChooseLayer::towers()
{
    m_sp->removeFromParent();
    char str[50];
    sprintf(str,"ss_towers_%02d.png",A);
    m_sp = Sprite::create(str);
    m_sp->setPosition(Vec2(240, 90));
    this->addChild(m_sp);
}
void ChooseLayer::onDestroy()
{
    A = 0;
}
