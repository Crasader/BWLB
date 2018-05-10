//
//  UIManager.hpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#ifndef UIManager_hpp
#define UIManager_hpp

#include <stdio.h>
#include "UIBaseLayer.hpp"
class UIManager
{
public:
    enum LayerType{
        FIRST,
        MAOXIAN,
        SHEZHI,
        SHUOMING,
        CHOOSE,
    };
    static UIBaseLayer* CreateLayer(LayerType type);
    static void DestroyLayer();
    static UIBaseLayer* m_activeLayer;
    
    
    
    
};



#endif /* UIManager_hpp */
