#pragma once

#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/modify/CCNode.hpp>

#include "../main.cpp"

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

class $modify(hidableNode, CCNode) {
	struct Fields {
		bool isUI = false;
		// 2 for hidden
		// 1 for not hidden
		int hideNode = 0;
	};
	// if the node is having its visibility set, check a couple things first
	virtual void setVisible(bool visible) {
		if (isHidden && m_fields->isUI) {
			CCNode::setVisible(false);
		}
		else {
			if (visible) {
				m_fields->hideNode = 1;
			}
			else {
				m_fields->hideNode = 2;
			}
			CCNode::setVisible(visible);

		}
	}
};