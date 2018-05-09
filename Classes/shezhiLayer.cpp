//
//  shezhiLayer.cpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#include "shezhiLayer.hpp"
#include "UIManager.hpp"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SceneManager.hpp"
#include "MusicManager.hpp"
using namespace cocos2d;

void shezhiLayer::onCreate()
{
    FileUtils::getInstance()->addSearchPath("studio");
    node = CSLoader::createNode("Layerxxread01.csb");
    CCLOG("shuomingLayer");
    this->addChild(node);
    
    m_xuanxiang = static_cast<ui::Button*>(node->getChildByName("Button_1"));
    m_shujutongji = static_cast<ui::Button*>(node->getChildByName("Button_2"));
    m_bangzhu = static_cast<ui::Button*>(node->getChildByName("Button_3"));
    
    m_xuanxiang->addClickEventListener(CC_CALLBACK_1(shezhiLayer::xuanXiang,this));
    m_shujutongji->addClickEventListener(CC_CALLBACK_1(shezhiLayer::shuju,this));
    m_bangzhu->addClickEventListener(CC_CALLBACK_1(shezhiLayer::bangZhu,this));
    
    m_fanhui = static_cast<ui::Button*>(node->getChildByName("Button_4"));
    m_fanhui->addClickEventListener([=](Ref*){
        SceneMannger::goToFirstScene();
    });
    
    m_yinyue = static_cast<ui::CheckBox*>(node->getChildByName("CheckBox_1"));
    m_yinyue->addEventListener([](Ref* sender,ui::CheckBox::EventType type){
        switch (type) {
            case ui::CheckBox::EventType::SELECTED:
                MusicManager::setFlags(true);
                MusicManager::playBackgroundMusic("Music/Main/BGMusic.mp3",true);
                //                MusicManager::resumeBackgroundMusic();
                break;
            case ui::CheckBox::EventType::UNSELECTED:
                MusicManager::setFlags(false);
                MusicManager::pauseBackgroundMusic();
                break;
            default:
                break;
        }
    });

}
void shezhiLayer::xuanXiang(cocos2d::Ref*)
{
    node->removeFromParent();
    node = CSLoader::createNode("Layerxxread01.csb");
    this->addChild(node);
    
    m_xuanxiang = static_cast<ui::Button*>(node->getChildByName("Button_1"));
    m_shujutongji = static_cast<ui::Button*>(node->getChildByName("Button_2"));
    m_bangzhu = static_cast<ui::Button*>(node->getChildByName("Button_3"));
    
    m_xuanxiang->addClickEventListener(CC_CALLBACK_1(shezhiLayer::xuanXiang,this));
    m_shujutongji->addClickEventListener(CC_CALLBACK_1(shezhiLayer::shuju,this));
    m_bangzhu->addClickEventListener(CC_CALLBACK_1(shezhiLayer::bangZhu,this));
    
    m_fanhui = static_cast<ui::Button*>(node->getChildByName("Button_4"));
    m_fanhui->addClickEventListener([=](Ref*){
        SceneMannger::goToFirstScene();
    });
    
    m_yinyue = static_cast<ui::CheckBox*>(node->getChildByName("CheckBox_1"));
    m_yinyue->addEventListener([](Ref* sender,ui::CheckBox::EventType type){
        switch (type) {
            case ui::CheckBox::EventType::SELECTED:
                MusicManager::setFlags(true);
                MusicManager::playBackgroundMusic("Music/Main/BGMusic.mp3",true);
                //                MusicManager::resumeBackgroundMusic();
                break;
            case ui::CheckBox::EventType::UNSELECTED:
                MusicManager::setFlags(false);
                MusicManager::pauseBackgroundMusic();
                break;
            default:
                break;
        }
    });
}
void shezhiLayer::shuju(cocos2d::Ref*)
{
    CCLOG("shujutongji");
    node->removeFromParent();
    node = CSLoader::createNode("Layerxxread02.csb");
    this->addChild(node);
    
    m_xuanxiang = static_cast<ui::Button*>(node->getChildByName("Button_1"));
    m_shujutongji = static_cast<ui::Button*>(node->getChildByName("Button_2"));
    m_bangzhu = static_cast<ui::Button*>(node->getChildByName("Button_3"));
    
    m_xuanxiang->addClickEventListener(CC_CALLBACK_1(shezhiLayer::xuanXiang,this));
    m_shujutongji->addClickEventListener(CC_CALLBACK_1(shezhiLayer::shuju,this));
    m_bangzhu->addClickEventListener(CC_CALLBACK_1(shezhiLayer::bangZhu,this));
    
    m_fanhui = static_cast<ui::Button*>(node->getChildByName("Button_4"));
    m_fanhui->addClickEventListener([=](Ref*){
        SceneMannger::goToFirstScene();
    });
}
void shezhiLayer::bangZhu(cocos2d::Ref*)
{
    node->removeFromParent();
    node = CSLoader::createNode("Layerxxread03.csb");
    this->addChild(node);
    
    m_xuanxiang = static_cast<ui::Button*>(node->getChildByName("Button_1"));
    m_shujutongji = static_cast<ui::Button*>(node->getChildByName("Button_2"));
    m_bangzhu = static_cast<ui::Button*>(node->getChildByName("Button_3"));
    
    m_xuanxiang->addClickEventListener(CC_CALLBACK_1(shezhiLayer::xuanXiang,this));
    m_shujutongji->addClickEventListener(CC_CALLBACK_1(shezhiLayer::shuju,this));
    m_bangzhu->addClickEventListener(CC_CALLBACK_1(shezhiLayer::bangZhu,this));
    
    m_fanhui = static_cast<ui::Button*>(node->getChildByName("Button_4"));
    m_fanhui->addClickEventListener([=](Ref*){
        SceneMannger::goToFirstScene();
    });
}





