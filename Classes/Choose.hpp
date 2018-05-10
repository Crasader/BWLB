//
//  Choose.hpp
//  luobo
//
//  Created by student on 18/5/9.
//
//

#ifndef Choose_hpp
#define Choose_hpp

#include <stdio.h>
#include"cocos2d.h"
#include "UIBaseLayer.hpp"

class ChooseLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(ChooseLayer);
    
    void onCreate()override;
    void onDestroy()override;
    
    void towers();
private:
    cocos2d::Node* m_node;
    cocos2d::Vec2 m_touchPos;
    
    cocos2d::Sprite* m_sp;
    
    static int A;
    
};


#endif /* Choose_hpp */
