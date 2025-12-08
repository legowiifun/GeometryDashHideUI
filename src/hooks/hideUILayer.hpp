#pragma once

#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/modify/PlayLayer.hpp>

#include "hidableNode.hpp"
#include "../main.hpp"

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

class $modify(hideUILayer, PlayLayer) {
	// set the visibility of nodes
	void hideNode(const char* name);
	void hideNode(CCNode * n);
	// set the visibility of multiple nodes
	void hideNodes();
	// mark a node as a member of the UI to be hidden
	void markAsUI(const char* name);
	void markAsUI(CCNode * n);
	// mark multiple nodes as UI elements
	void markNodesAsUI();
	bool init(GJGameLevel * level, bool useReplay, bool dontCreateObjects);
	// hook the startGame method
	void startGame();
};