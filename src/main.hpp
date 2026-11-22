#pragma once
/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include "LinkedListImpl/Node.hpp"


inline bool isHidden = false;
inline LinkedListNode* head = nullptr;

void addUIEvent(std::string nodeID, std::string location);