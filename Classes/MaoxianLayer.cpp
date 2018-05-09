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
    pageview->setContentSize(Size(400.0f,300.0f));
    pageview->setPosition(Vec2(0,0));
//    pageview->setBounceEnabled(true);
    int pageCount = 4;
    for (int i = 0; i < pageCount; ++i)
    {
        ui::Layout* layout = ui::Layout::create();
        layout->setContentSize(Size(400.f, 300.f));
        char str[50];
        sprintf(str,"Chapter/theme_pack%02d.png",i+1);
//        auto imageView = ui::ImageView::create(str);
//        imageView->setScale9Enabled(true);
//        imageView->setContentSize(Size(300, 200));
//        imageView->setPosition(Vec2(layout->getContentSize().width/2.0f,layout->getContentSize().height/2.0f));
        auto bt = ui::Button::create(str);
        bt->setContentSize(Size(200,150));
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