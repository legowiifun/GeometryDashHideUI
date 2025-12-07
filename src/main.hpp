#pragma once
/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include "LinkedListImpl/Node.hpp"
/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

inline bool isHidden = false;
inline LinkedListNode* head = nullptr;