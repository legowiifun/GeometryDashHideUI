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