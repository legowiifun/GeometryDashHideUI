#define GEODE_DEFINE_EVENT_EXPORTS
#include "hideUIAPI.hpp"

void hideUIAPI::toggleUI() {
    // switch the isHidden value
	isHidden = !(isHidden);
    PlayLayer* layer = PlayLayer::get();
    if (layer!=nullptr) {
	    ((hideUILayer*)layer)->hideNodes();
    }
}
void hideUIAPI::turnOffUI() {
    // set isHidden to true
	isHidden = true;
    PlayLayer* layer = PlayLayer::get();
    if (layer!=nullptr) {
	    ((hideUILayer*)layer)->hideNodes();
    }
}
void hideUIAPI::turnOnUI() {
    // set isHidden to false
	isHidden = false;
    PlayLayer* layer = PlayLayer::get();
    if (layer!=nullptr) {
	    ((hideUILayer*)layer)->hideNodes();
    }
}


geode::Result<void> hide_ui_events::addUIElementEvent(std::string nodeID, std::string location) {
    log::debug("Recieving hide UI event");
    //prevent duplicates
	if (head->strExists(nodeID)) {
		return Ok();
	}
	if (location=="PlayLayer") {
		head->addToEnd(new LinkedListNode(nodeID, 0));
	} else if (location=="Nested") {
		head->addToEnd(new LinkedListNode(nodeID, -1));
	} else if (location=="Sibling") {
		head->addToEnd(new LinkedListNode(nodeID, 1));
	}
    return Ok();
}