#include "main.hpp"

//dispatch events
void addUIEvent(std::string nodeID, std::string location) {
	//prevent duplicates
	if (head->strExists(nodeID)) {
		return;
	}
	if (location=="PlayLayer") {
		head->addToEnd(new LinkedListNode(nodeID, 0));
	} else if (location=="Nested") {
		head->addToEnd(new LinkedListNode(nodeID, -1));
	} else if (location=="Sibling") {
		head->addToEnd(new LinkedListNode(nodeID, 1));
	}
}

$execute{
	// register keybind
	keybinds::BindManager::get()->registerBindable({
		"hideUI"_spr,
		"Hide the user interface",
		"",
		{keybinds::Keybind::create(KEY_H, keybinds::Modifier::Shift)},
		"Play/UI"
	});
	
	// dispatch event
	new EventListener(+[](std::string nodeID, std::string location) {
		addUIEvent(nodeID, location);
		return ListenerResult::Stop;
	}, ToFilter<EventAddUI>("legowiifun.hide_ui/addUI"));
}
$on_mod(Loaded) {
	// globed
	head=new LinkedListNode("dankmeme.globed2/game-overlay", 0);
	// platformer ghosts
	head->addToEnd(new LinkedListNode("zilko.platformer_ghosts/ghost_ui", 0));
	head->addToEnd(new LinkedListNode("zilko.platformer_ghosts/player-icon1", 0));
	head->addToEnd(new LinkedListNode("zilko.platformer_ghosts/player-icon2", 0));
	// The Ghosts themselves
	head->addToEnd(new LinkedListNode("zilko.platformer_ghosts/ghost-player1", -1));
	head->addToEnd(new LinkedListNode("zilko.platformer_ghosts/ghost-player2", -1));

	// RunInfo
	head->addToEnd(new LinkedListNode("mat.run-info/RunInfoWidget", 0));

	// GDH
	head->addToEnd(new LinkedListNode("tobyadd.gdh/labels_top_left", 0));
	head->addToEnd(new LinkedListNode("tobyadd.gdh/labels_top_right", 0));
	head->addToEnd(new LinkedListNode("tobyadd.gdh/labels_bottom_left", 0));
	head->addToEnd(new LinkedListNode("tobyadd.gdh/labels_bottom_right", 0));
	head->addToEnd(new LinkedListNode("tobyadd.gdh/labels_top", 0));
	head->addToEnd(new LinkedListNode("tobyadd.gdh/labels_bottom", 0));
				
	// Speedrun Timer
	head->addToEnd(new LinkedListNode("cheeseworks.speedruntimer/timer", 0));


	// Friends!
	// PetLayer
	// does not work
	//head->addToEnd(new LinkedListNode("Petlayer", 1));

	// Status Monitor
	head->addToEnd(new LinkedListNode("status-monitor", 1));

	// default (robtop) interfaces
	// also covers some other mods (stat display, etc.)
	head->addToEnd(new LinkedListNode("progress-bar", 0));
	head->addToEnd(new LinkedListNode("percentage-label", 0));
	head->addToEnd(new LinkedListNode("UILayer", 0));
	head->addToEnd(new LinkedListNode("debug-text", 0));
	head->addToEnd(new LinkedListNode("time-label", 0));	
}