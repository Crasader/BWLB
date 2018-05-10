//
//  FirstLayer.cpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#include "FirstLayer.hpp"
#include "UIManager.hpp"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SceneManager.hpp"
using namespace cocos2d;

void FirstLayer::onCreate()
{
//    m_layer =
    FileUtils::getInstance()->addSearchPath("studio");
    auto node = CSLoader::createNode("zhujiemian.csb");
    CCLOG("FirstLayer");
    this->addChild(node);
//    auto s = Sprite::create("bird.png");
//    s->setPosition(Vec2(200,200));
//    this->addChild(s);
    
//    m_rye = Sprite::create();
//    m_rye = node->getChildByName("Sprite_9");
//    m_lye = static_cast<Sprite(*)>(node->getChildByName("Sprite_8"));
//    
//    m_bird = static_cast<Sprite(*)>(node->getChildByName("Sprite_3"));
//    
//    dong();
    auto action = CSLoader::createTimeline("zhujiemian.csb");
    action->gotoFrameAndPlay(0,120,true);
    node->runAction(action);

    
    m_shezhi = static_cast<ui::Button(*)>(node->getChildByName("Button_2"));
    m_shezhi->addClickEventListener(CC_CALLBACK_1(FirstLayer::shezhi, this));
    
    m_maoxian = static_cast<ui::Button(*)>(node->getChildByName("Button_4"));
    m_maoxian->addClickEventListener(CC_CALLBACK_1(FirstLayer::maoxian, this));

    m_shuoming = static_cast<ui::Button(*)>(node->getChildByName("Button_3"));
    m_shuoming->addClickEventListener(CC_CALLBACK_1(FirstLayer::shuoming, this));
    
    m_heart = static_cast<ui::Button(*)>(node->getChildByName("Button_1"));
    m_heart->addClickEventListener([=](Ref*){
        
        //触摸吞噬
        auto m_layout = ui::Layout::create();
        m_layout->setContentSize(Size(480,320));
        this->addChild(m_layout);
        m_layout->setTouchEnabled(true);
        m_layout->setSwallowTouches(true);
        
        auto node = CSLoader::createNode("Layer.csb");
        CCLOG("HeartLayer");
        this->addChild(node);
        
        auto cha = static_cast<ui::Button(*)>(node->getChildByName("Button_1"));
        cha->addClickEventListener([=](Ref*)mutable{
            m_layout->removeFromParent();
            node->setVisible(false);
        });
    });
    
    
}
void FirstLayer::onActive()
{
}
void FirstLayer::onDestroy()
{
    
}
void FirstLayer::maoxian(Ref*)
{
//    UIManager::CreateLayer(UIManager::MAOXIAN);
    SceneMannger::gotoMaoxianScene();
    CCLOG("gotoMaoxianScene");
}
void FirstLayer::shezhi(cocos2d::Ref*)
{
//    UIManager::CreateLayer(UIManager::SHEZHI);
    SceneMannger::gotoShezhiScene();

}
void FirstLayer::shuoming(cocos2d::Ref*)
{
    CCLOG("goto shuoming");
//    UIManager::CreateLayer(UIManager::SHUOMING);
    SceneMannger::goToHelpScene();
    }
void FirstLayer::dong()
{
    auto rotateBy1 = RotateBy::create(1.25,25);
    auto rotateBy11 = RotateBy::create(1.25,-25);
    auto s1 = Sequence::create(rotateBy1,rotateBy11,NULL);
    
    auto ta = TargetedAction::create(m_rye,s1);
    auto rotateBy2 = RotateBy::create(1.25,-25);
    auto rotateBy22 = RotateBy::create(1.25,25);
    auto s2 = Sequence::create(rotateBy2,rotateBy22,NULL);
    auto seq = Sequence::create(ta,s2,NULL);
    auto re = Repeat::create(seq,100);
    m_lye->runAction(re);
    
    auto ac = MoveBy::create(0.5,Vec2(0, 20));
    auto ac2 = MoveBy::create(0.5,Vec2(0,-20));
    
    auto seq3 = Sequence::create(ac,ac2, NULL);
    auto A = Repeat::create(seq3,100);
    m_bird->runAction(A);
    
    
    
}






