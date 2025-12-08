#include "hideUILayer.hpp"
#include "../main.hpp"
	// set the visibility of nodes
	void hideUILayer::hideNode(const char* name) {
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
	void hideUILayer::hideNode(CCNode * n) {
		// get the node as a hidableNode
		hidableNode* node = (hidableNode*)n;
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
	void hideUILayer::hideNodes() {
		//go through each element
		LinkedListNode* current=head;
		while (current!=nullptr) {
			if (current->getIsNested()==0) {
				hideNode(current->getData().c_str());
			} else if (current->getIsNested()==1) {
				hideNode(getParent()->getChildByID(current->getData()));
			} else if (current->getIsNested()==-1) {
				hideNode(getChildByIDRecursive(current->getData()));
			}
			current=current->getNext();
		}
	}
	// mark a node as a member of the UI to be hidden
	void hideUILayer::markAsUI(const char* name) {
		hidableNode* node = (hidableNode*)getChildByID(name);
		if (node == nullptr) {
			return;
		}
		node->m_fields->isUI = true;
	}
	void hideUILayer::markAsUI(CCNode * n) {
		hidableNode* node = (hidableNode*)n;
		if (node == nullptr) {
			return;
		}
		node->m_fields->isUI = true;
	}
	void hideUILayer::markNodesAsUI() {
		//go through each element
		LinkedListNode* current=head;
		while (current!=nullptr) {
			if (current->getIsNested()==0) {
				markAsUI(current->getData().c_str());
			} else if (current->getIsNested()==1) {
				markAsUI(getParent()->getChildByID(current->getData()));
			} else if (current->getIsNested()==-1) {
				markAsUI(getChildByIDRecursive(current->getData()));
			}
			current=current->getNext();
		}
	}
	bool hideUILayer::init(GJGameLevel * level, bool useReplay, bool dontCreateObjects) {
		if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
			return false;
		}
		// add the keybind event
		this->template addEventListener<keybinds::InvokeBindFilter>([=](keybinds::InvokeBindEvent* event) {
			if (event->isDown()) {
				// switch the isHidden value
				isHidden = !(isHidden);
				hideNodes();
			}
			return ListenerResult::Propagate;
			}, "hideUI"_spr);
		return true;
	}
	// hook the startGame method
	void hideUILayer::startGame() {
		PlayLayer::startGame();
		markNodesAsUI();
		if (Mod::get()->getSettingValue<bool>("auto-hide")) {
			// switch the isHidden value
			isHidden = !(isHidden);
			hideNodes();
		}
	}