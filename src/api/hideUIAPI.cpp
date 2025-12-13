#include "hideUIAPI.hpp"
#include "../main.hpp"
#include "../hooks/hideUILayer.hpp"

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