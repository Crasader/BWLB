//
//  FirstLayer.hpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#ifndef FirstLayer_hpp
#define FirstLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "UIBaseLayer.hpp"
#include "ui/CocosGUI.h"

class FirstLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(FirstLayer);
    
    void onCreate()override;
    void onActive()override;
    void onDestroy()override;
    
    void maoxian(cocos2d::Ref*);
    void shezhi(cocos2d::Ref*);
    void shuoming(cocos2d::Ref*);
    
    void dong();
//    void update(float dt)override;
    
    
private:
    cocos2d::Layer* m_layer;
    
    cocos2d::Sprite* m_bird;
    cocos2d::Sprite* m_lye;
    cocos2d::Node* m_rye;
    cocos2d::Sprite* m_yun;
    cocos2d::ui::Button* m_heart;
    
    cocos2d::ui::Button* m_shezhi;
    cocos2d::ui::Button* m_shuoming;//设置界面
    cocos2d::ui::Button* m_maoxian;

    
    
};



#endif /* FirstLayer_hpp */
