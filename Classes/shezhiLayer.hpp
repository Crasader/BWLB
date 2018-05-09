//
//  shezhiLayer.hpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#ifndef shezhiLayer_hpp
#define shezhiLayer_hpp

#include <stdio.h>
#include "UIBaseLayer.hpp"
#include "ui/CocosGUI.h"

class shezhiLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(shezhiLayer);
    
    void onCreate()override;
    
    void xuanXiang(cocos2d::Ref*);
    void shuju(cocos2d::Ref*);
    void bangZhu(cocos2d::Ref*);
private:
    cocos2d::ui::Button* m_xuanxiang;
    cocos2d::ui::Button* m_shujutongji;
    cocos2d::ui::Button* m_bangzhu;
    cocos2d::ui::Button* m_fanhui;
    
    cocos2d::ui::CheckBox* m_yinyue;
    
    cocos2d::Node* node;
    
    
};

#endif /* shezhiLayer_hpp */
