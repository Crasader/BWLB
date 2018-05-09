//
//  shuomingLayer.hpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#ifndef shuomingLayer_hpp
#define shuomingLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "UIBaseLayer.hpp"
#include "ui/CocosGUI.h"

class shuomingLayer:public UIBaseLayer
{
public:
    static int A;
    CREATE_FUNC(shuomingLayer);
    
    void onCreate()override;
    
    void bangzhu(cocos2d::Ref*);
    void guaiwu(cocos2d::Ref*);
    void paota(cocos2d::Ref*);
    
private:
    cocos2d::ui::Button* m_bangzhu;
    cocos2d::ui::Button* m_guaiwu;
    cocos2d::ui::Button* m_paota;
    cocos2d::ui::Button* m_fanhui;
    
    cocos2d::Node* node;
    
    
};
#endif /* shuomingLayer_hpp */
