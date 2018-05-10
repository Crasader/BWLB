//
//  GoLayer.hpp
//  luobo
//
//  Created by student on 18/5/10.
//
//

#ifndef GoLayer_hpp
#define GoLayer_hpp

#include <stdio.h>
#include"cocos2d.h"
#include "UIBaseLayer.hpp"

class GoLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(GoLayer);
    
    void onCreate()override;
    void onDestroy()override;
private:
    cocos2d::Sprite* m_sp3;
    cocos2d::Sprite* m_sp2;
    cocos2d::Sprite* m_sp1;
    cocos2d::Sprite* m_spgo;
    
    
};

#endif /* GoLayer_hpp */
