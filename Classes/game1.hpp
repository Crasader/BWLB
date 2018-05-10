//
//  game1.hpp
//  luobo
//
//  Created by student on 18/5/9.
//
//

#ifndef game1_hpp
#define game1_hpp

#include <stdio.h>
#include"cocos2d.h"
#include "UIBaseLayer.hpp"

class game1:public UIBaseLayer
{
public:
    CREATE_FUNC(game1);
    
    void onCreate()override;
};

#endif /* game1_hpp */
