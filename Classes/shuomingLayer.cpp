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
    FileUtils::getInstance()->addSearchPath("studio/help");
    node = CSLoader::createNode("bangzhu.csb");
    CCLOG("shuomingLayer");
    this->addChild(node);
    
    
//    m_bangzhu  = static_cast<ui::Button*>(node->getChildByTag());
    m_guaiwu = static_cast<ui::Button*>(node->getChildByTag(301));
    m_paota = static_cast<ui::Button*>(node->getChildByTag(302));
//
//    m_bangzhu->addClickEventListener(CC_CALLBACK_1(shuomingLayer::bangzhu,this));
    m_guaiwu->addClickEventListener(CC_CALLBACK_1(shuomingLayer::guaiwu,this));
    m_paota->addClickEventListener(CC_CALLBACK_1(shuomingLayer::paota,this));
    
    m_fanhui = static_cast<ui::Button*>(node->getChildByTag(299));
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
    node = CSLoader::createNode("bangzhu.csb");
    this->addChild(node);
    
    m_guaiwu = static_cast<ui::Button*>(node->getChildByTag(301));
    m_paota = static_cast<ui::Button*>(node->getChildByTag(302));
    
    //    m_bangzhu->addClickEventListener(CC_CALLBACK_1(shuomingLayer::bangzhu,this));
    m_guaiwu->addClickEventListener(CC_CALLBACK_1(shuomingLayer::guaiwu,this));
    m_paota->addClickEventListener(CC_CALLBACK_1(shuomingLayer::paota,this));
    
    m_fanhui = static_cast<ui::Button*>(node->getChildByTag(299));
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
void shuomingLayer::guaiwu(cocos2d::Ref*)
{
    CCLOG("guaiwu");
    node->removeFromParent();
    node = CSLoader::createNode("guaiwu.csb");
    this->addChild(node);
    
//    node = CSLoader::createNode("guaiwu.csb");
//    CCLOG("shuoming-guaiwu");
//    this->addChild(node);
    
    
    m_bangzhu = static_cast<ui::Button*>(node->getChildByTag(205));
//    m_guaiwu = static_cast<ui::Button*>(node->getChildByName("Button_3"));
    m_paota = static_cast<ui::Button*>(node->getChildByTag(107));
    
    m_bangzhu->addClickEventListener(CC_CALLBACK_1(shuomingLayer::bangzhu,this));
//    m_guaiwu->addClickEventListener(CC_CALLBACK_1(shuomingLayer::guaiwu,this));
    m_paota->addClickEventListener(CC_CALLBACK_1(shuomingLayer::paota,this));
    
    m_fanhui = static_cast<ui::Button*>(node->getChildByTag(180));
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
void shuomingLayer::paota(cocos2d::Ref*)
{
    CCLOG("paota");
    node->removeFromParent();
    node = CSLoader::createNode("paota.csb");
    this->addChild(node);
    
    m_bangzhu = static_cast<ui::Button*>(node->getChildByTag(244));
    m_guaiwu = static_cast<ui::Button*>(node->getChildByTag(255));
//    m_paota = static_cast<ui::Button*>(node->getChildByName("Button_4"));
    
    m_bangzhu->addClickEventListener(CC_CALLBACK_1(shuomingLayer::bangzhu,this));
    m_guaiwu->addClickEventListener(CC_CALLBACK_1(shuomingLayer::guaiwu,this));
//    m_paota->addClickEventListener(CC_CALLBACK_1(shuomingLayer::paota,this));
    
    m_fanhui = static_cast<ui::Button*>(node->getChildByTag(243));
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
    
   auto pageview = static_cast<ui::PageView*>(node->getChildByTag(255));
//    int i = pageview->getCurrentPageIndex();
    auto m_label = Label::create();
    char str[50];
    sprintf(str,"%02d/17",1);
    m_label->setString(str);
    m_label->setPosition(Vec2(230,30));

    this->addChild(m_label);
    pageview->addEventListener([=](Ref* pSender,ui::PageView::EventType type){
                switch (type) {
                    case ui::PageView::EventType::TURNING:
                    {
//                        m_label->removeFromParent();
                        auto pageview = dynamic_cast<ui::PageView*>(pSender);
                        int i = pageview->getCurrentPageIndex()+1;
//                        auto label = Label::create();
                        char str[50];
                        sprintf(str,"%02d/17",i);
                        m_label->setString(str);
//                        this->addChild(m_label);
                    }
                        break;
        
                    default:
                        break;
                }
            });
    
}








