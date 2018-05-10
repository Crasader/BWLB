//
//  MaoxianLayer.cpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#include "MaoxianLayer.hpp"
#include "ui/CocosGUI.h"
#include "SceneManager.hpp"
#include "shuomingLayer.hpp"
#include "UIManager.hpp"
using namespace cocos2d;

void MaoxianLayer::onCreate()
{
    auto bg = Sprite::create("Background/ss_bg.png");
    bg->setPosition(Vec2(240,160));
    this->addChild(bg);
    
    //返回按钮
    auto btn_fanhui = ui::Button::create("Btn/ss_back_normal.png");
    btn_fanhui->setPosition(Vec2(20, 300));
    this->addChild(btn_fanhui);
    btn_fanhui->addClickEventListener(CC_CALLBACK_1(MaoxianLayer::fanhui,this));
    
    //帮助按钮
    auto btn_help = ui::Button::create("Btn/ss_back_normal.png");
    btn_help->setPosition(Vec2(440, 300));
    this->addChild(btn_help);
    btn_help->addClickEventListener(CC_CALLBACK_1(MaoxianLayer::help,this));

    
    //翻页容器
    ui::PageView* pageview = ui::PageView::create();
    pageview->setContentSize(Size(200.0f,150.0f));
    pageview->setPosition(Vec2(150,100));
//    pageview->setBounceEnabled(true);
    int pageCount = 4;
    for (int i = 0; i < pageCount; ++i)
    {
        ui::Layout* layout = ui::Layout::create();
        layout->setContentSize(Size(200.f, 150.f));
        char str[50];
        sprintf(str,"Chapter/theme_pack%02d.png",i+1);

        auto bt = ui::Button::create(str);
        bt->setContentSize(Size(200,150));
        bt->setScale(0.5);
        bt->setTag(i);
        m_vec.pushBack(bt);
        bt->setPosition(Vec2(layout->getContentSize().width/2.0f,layout->getContentSize().height/2.0f));
    
        layout->addChild(bt);
//        auto label = ui::Text::create(StringUtils::format("page %d",(i + 1)), "fonts/Marker Felt.ttf", 30);
//        label->setColor(Color3B(255,0,0));
//        label->setPosition(Vec2(layout->getContentSize().width/2.0f, layout->getContentSize().height/2.0f));
//        layout->addChild(label);
        pageview->insertPage(layout, i);
        
    }
//    pageview->addEventListener([](Ref* pSender,ui::PageView::EventType type){
//        switch (type) {
//            case ui::PageView::EventType::TURNING:
//            {
//                auto pageview = dynamic_cast<ui::PageView*>(pSender);
//                log("page = %ld",pageview->getCurPageIndex()+1);
//            }
//                break;
//                
//            default:
//                break;
//        }
//    });
    this->addChild(pageview);
    
    static int p = 1;
    auto btn_left = ui::Button::create("Btn/recommend_left_normal.png");
    btn_left->setPosition(Vec2(100,150));
    this->addChild(btn_left);
    btn_left->addClickEventListener([=](Ref*)mutable{
        pageview->setCurrentPageIndex(--p);
        CCLOG("left");
    });
    
    auto btn_right = ui::Button::create("Btn/recommend_right_normal.png");
    btn_right->setPosition(Vec2(400,150));
    this->addChild(btn_right);
    btn_right->addClickEventListener([=](Ref*)mutable{
        pageview->setCurrentPageIndex(++p);
    });
    
    for(auto x : m_vec)
    {
        if (x->getTag() == 0) {
            
            x->addClickEventListener(CC_CALLBACK_1(MaoxianLayer::charpterOne,this));
        }
    }

}
void MaoxianLayer::fanhui(cocos2d::Ref*)
{
    SceneMannger::goToFirstScene();
}
void MaoxianLayer::help(cocos2d::Ref*)
{
    shuomingLayer::A = 2;
    SceneMannger::goToHelpScene();
}
void MaoxianLayer::charpterOne(cocos2d::Ref *)
{
    CCLOG("dianji One");
//    this->setVisible(false);
    auto layer = UIManager::CreateLayer(UIManager::CHOOSE);
    this->addChild(layer);
}



