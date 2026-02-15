#pragma once
/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include "LinkedListImpl/Node.hpp"
#include <Geode/loader/Dispatch.hpp>
#include <Geode/loader/Event.hpp>

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
inline bool isHidden = false;
inline LinkedListNode* head = nullptr;

void addUIEvent(std::string nodeID, std::string location);