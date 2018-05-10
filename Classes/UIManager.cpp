//
//  UIManager.cpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#include "UIManager.hpp"

#include "MaoxianLayer.hpp"
#include "shezhiLayer.hpp"
#include "shuomingLayer.hpp"
#include "FirstLayer.hpp"
#include "Choose.hpp"
#define BACKGROUNDZORDER 10
#define SETLAYERZORDER 20

UIBaseLayer* UIManager::m_activeLayer = nullptr;
UIBaseLayer* UIManager::CreateLayer(UIManager::LayerType type)
{
    m_activeLayer = nullptr;
    switch (type) {
        case MAOXIAN:
        {
            m_activeLayer = MaoxianLayer::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        case SHEZHI:
        {
            m_activeLayer = shezhiLayer::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        case SHUOMING:
        {
            m_activeLayer = shuomingLayer::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        case FIRST:
        {
            m_activeLayer = FirstLayer::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        case CHOOSE:
        {
            m_activeLayer = ChooseLayer::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        default:
        break;
    }
    return m_activeLayer;
}
void UIManager::DestroyLayer()
{
    if (m_activeLayer)
    {
        m_activeLayer->removeFromParent();
        m_activeLayer = nullptr;
    }
}