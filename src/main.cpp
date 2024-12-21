/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameManager.hpp>
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

// define the modified gameManager, as it is needed for hideUILayer, and hideUILayer is needed for it
class $modify(HideUIGM, GameManager) {
	struct Fields {
		bool isActive = false;
	};
	void hideNode(std::string name, int id);
	void update(float p0);
};

class $modify(hideUILayer, PlayLayer) {
	struct Fields {
		// tracks the current state
		bool isHidden;
		// tracks which nodes are initially visible, so ones that are invisible stay invisible
		bool isVisisble[16];
	};
	// hide nodes easily
	void hideNode(std::string name, int id) {
		CCNode* node = getChildByID(name);
		if (node == nullptr) {
			return;
		}
		if ((m_fields->isHidden) == true && (m_fields->isVisisble[id]==true)) {
			node->setVisible(true);
		}
		else {
			node->setVisible(false);
		}
	}
	// set whether a node starts invisible or not
	void setStatus(std::string name, int id) {
		CCNode* node = getChildByID(name);
		if (node == nullptr) {
			return;
		}
		m_fields->isVisisble[id] = node->isVisible();
	}
	bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
		// set elements as hidden, so they automatically get unhidden
		m_fields->isHidden = true;

		// run the original playLayer::init
		if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
			return false;
		}
		return true;
	}
	void startGame() {
		PlayLayer::startGame();

		// set initial node statuses
		// mod interfaces
		// globed
		setStatus("dankmeme.globed2/game-overlay", 0);

		// platformer ghosts
		setStatus("zilko.platformer_ghosts/ghost_ui", 1);
		m_fields->isVisisble[2] = true;
		m_fields->isVisisble[3] = true;

		// RunInfo
		setStatus("mat.run-info/RunInfoWidget", 4);

		// GDH
		setStatus("tobyadd.gdh/labels_top_left", 5);
		setStatus("tobyadd.gdh/labels_top_right", 6);
		setStatus("tobyadd.gdh/labels_bottom_left", 7);
		setStatus("tobyadd.gdh/labels_bottom_right", 8);
		setStatus("tobyadd.gdh/labels_top", 9);
		setStatus("tobyadd.gdh/labels_bottom", 10);


		// default (robtop) interfaces
		// also covers some other mods (megahack, stat display, etc.)
		setStatus("progress-bar", 11);
		setStatus("percentage-label", 12);
		setStatus("UILayer", 13);
		setStatus("debug-text", 14);
		setStatus("time-label", 15);
		
		// now that everything is ready, trigger the update method
		((HideUIGM*)GameManager::get())->m_fields->isActive = true;

		// add the keybind event
		this->template addEventListener<keybinds::InvokeBindFilter>([=](keybinds::InvokeBindEvent* event) {
			if (event->isDown()) {
				// switch the isHidden value
				m_fields->isHidden = !(m_fields->isHidden);
			}
			return ListenerResult::Propagate;
			}, "hideUI"_spr);
	}
	void onExit() {
		// reset the update method activation when you exit a level
		((HideUIGM*)GameManager::get())->m_fields->isActive = false;
		PlayLayer::onExit();
	}
};

void HideUIGM::hideNode(std::string name, int id) {
	hideUILayer* pl = (hideUILayer*)getPlayLayer();
	pl->hideNode(name,id);
}
void HideUIGM::update(float p0) {
	if (m_fields->isActive) {
		// mod interfaces
		// globed
		hideNode("dankmeme.globed2/game-overlay", 0);

		// platformer ghosts
		hideNode("zilko.platformer_ghosts/ghost_ui", 1);
		hideNode("zilko.platformer_ghosts/player-icon1", 2);
		hideNode("zilko.platformer_ghosts/player-icon2", 3);

		// RunInfo
		hideNode("mat.run-info/RunInfoWidget", 4);

		// GDH
		hideNode("tobyadd.gdh/labels_top_left", 5);
		hideNode("tobyadd.gdh/labels_top_right", 6);
		hideNode("tobyadd.gdh/labels_bottom_left", 7);
		hideNode("tobyadd.gdh/labels_bottom_right", 8);
		hideNode("tobyadd.gdh/labels_top", 9);
		hideNode("tobyadd.gdh/labels_bottom", 10);

		// default (robtop) interfaces
		// also covers some other mods (megahack, stat display, etc.)
		hideNode("progress-bar", 11);
		hideNode("percentage-label", 12);
		hideNode("UILayer", 13);
		hideNode("debug-text", 14);
		hideNode("time-label", 15);
	}
	GameManager::update(p0);
}