#pragma once
/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include "LinkedListImpl/Node.hpp"
#include <Geode/loader/Dispatch.hpp>
#include <Geode/loader/Event.hpp>

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

inline bool isHidden = false;
inline LinkedListNode* head = nullptr;

//set up for dispatch events API
// set up filter for dispatch event
using EventAddUI = geode::DispatchEvent<std::string, int>;
template <class>
struct ToFilterImpl;

template <class... Args>
struct ToFilterImpl<geode::DispatchEvent<Args...>> {
    using type = geode::DispatchFilter <Args...>;
};

template <class T>
using ToFilter = typename ToFilterImpl<T>::type;

void addUIEvent(std::string nodeID, std::string location);