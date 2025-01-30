/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CCNode.hpp>
/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

// register keybind
$execute{
	keybinds::BindManager::get()->registerBindable({
		"hideUI"_spr,
		"Hide the user interface",
		"",
		{keybinds::Keybind::create(KEY_H)},
		"Play/UI"
	});
}
bool isHidden = false;
class $modify(hidableNode,CCNode) {
	struct Fields {
		bool isUI=false;
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

class $modify(hideUILayer, PlayLayer) {
	// set the visibility of nodes
	void hideNode(const char* name) {
		// get the node with the given ID
		hidableNode* node = (hidableNode*)getChildByID(name);
		if (node == nullptr) {
			return;
		}
		// if the node has not been hidden before, 
		if (node->m_fields->hideNode == 0) {
			// determine whether it is visible by default
			bool visible = node->isVisible();
			if (visible) {
				node->m_fields->hideNode = 1;
			}
			else {
				node->m_fields->hideNode = 2;
			}
			node->setVisible(visible);
		}
		// otherwise, use known values
		else if (node->m_fields->hideNode == 1) {
			node->setVisible(true);
		}
		else {
			node->setVisible(false);
		}
	}
	// mark a node as a member of the UI to be hidden
	void markAsUI(const char* name) {
		hidableNode* node = (hidableNode*)getChildByID(name);
		if (node == nullptr) {
			return;
		}
		node->m_fields->isUI = true;
	}
	bool init(GJGameLevel * level, bool useReplay, bool dontCreateObjects) {
		if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
			return false;
		}
		// add the keybind event
		this->template addEventListener<keybinds::InvokeBindFilter>([=](keybinds::InvokeBindEvent* event) {
			if (event->isDown()) {
				// switch the isHidden value
				isHidden = !(isHidden);

				// mod interfaces
				// globed
				hideNode("dankmeme.globed2/game-overlay");

				// platformer ghosts
				hideNode("zilko.platformer_ghosts/ghost_ui");
				hideNode("zilko.platformer_ghosts/player-icon1");
				hideNode("zilko.platformer_ghosts/player-icon2");

				// RunInfo
				hideNode("mat.run-info/RunInfoWidget");

				// GDH
				hideNode("tobyadd.gdh/labels_top_left");
				hideNode("tobyadd.gdh/labels_top_right");
				hideNode("tobyadd.gdh/labels_bottom_left");
				hideNode("tobyadd.gdh/labels_bottom_right");
				hideNode("tobyadd.gdh/labels_top");
				hideNode("tobyadd.gdh/labels_bottom");

				// default (robtop) interfaces
				// also covers some other mods (megahack, stat display, etc.)
				hideNode("progress-bar");
				hideNode("percentage-label");
				hideNode("UILayer");
				hideNode("debug-text");
				hideNode("time-label");
			}
			return ListenerResult::Propagate;
			}, "hideUI"_spr);
		return true;
	}
	// hook the startGame method
	void startGame() {
		PlayLayer::startGame();

		// mark nodes as UI nodes
		// mod interfaces
		// globed
		markAsUI("dankmeme.globed2/game-overlay");

		// platformer ghosts
		markAsUI("zilko.platformer_ghosts/ghost_ui");
		markAsUI("zilko.platformer_ghosts/player-icon1");
		markAsUI("zilko.platformer_ghosts/player-icon2");

		// RunInfo
		markAsUI("mat.run-info/RunInfoWidget");

		// GDH
		markAsUI("tobyadd.gdh/labels_top_left");
		markAsUI("tobyadd.gdh/labels_top_right");
		markAsUI("tobyadd.gdh/labels_bottom_left");
		markAsUI("tobyadd.gdh/labels_bottom_right");
		markAsUI("tobyadd.gdh/labels_top");
		markAsUI("tobyadd.gdh/labels_bottom");


		// default (robtop) interfaces
		// also covers some other mods (megahack, stat display, etc.)
		markAsUI("progress-bar");
		markAsUI("percentage-label");
		markAsUI("UILayer");
		markAsUI("debug-text");
		markAsUI("time-label");
	}
};