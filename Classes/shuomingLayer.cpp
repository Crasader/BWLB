//
//  shuomingLayer.cpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#include "shuomingLayer.hpp"
#include "UIManager.hpp"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SceneManager.hpp"
using namespace cocos2d;
int shuomingLayer::A = 1;
void shuomingLayer::onCreate()
{
    FileUtils::getInstance()->addSearchPath("studio");
    node = CSLoader::createNode("help/bangzhu.csb");
    CCLOG("shuomingLayer");
    this->addChild(node);
    
    m_bangzhu = static_cast<ui::Button*>(node->getChildByName("Button_1"));
    m_guaiwu = static_cast<ui::Button*>(node->getChildByName("Button_2"));
    m_paota = static_cast<ui::Button*>(node->getChildByName("Button_3"));
    
    m_bangzhu->addClickEventListener(CC_CALLBACK_1(shuomingLayer::bangzhu,this));
    m_guaiwu->addClickEventListener(CC_CALLBACK_1(shuomingLayer::guaiwu,this));
    m_paota->addClickEventListener(CC_CALLBACK_1(shuomingLayer::paota,this));
    
    m_fanhui = static_cast<ui::Button*>(node->getChildByName("Button_4"));
    m_fanhui->addClickEventListener([=](Ref*){
        if (A == 1)
        {
            SceneMannger::goToFirstScene();
        }
        if (A == 2)
        {
            SceneMannger::gotoMaoxianScene();
        }
    });

}
void shuomingLayer::bangzhu(cocos2d::Ref*)
{
    node->removeFromParent();
    node = CSLoader::createNode("Layerxxread01.csb");
    this->addChild(node);
    
}
void shuomingLayer::guaiwu(cocos2d::Ref*)
{
    CCLOG("guaiwu");
    node->removeFromParent();
    node = CSLoader::createNode("Layerxxread02.csb");
    this->addChild(node);

}
void shuomingLayer::paota(cocos2d::Ref*)
{
    CCLOG("paota");
    node->removeFromParent();
    node = CSLoader::createNode("Layerxxread03.csb");
    this->addChild(node);
    
}








