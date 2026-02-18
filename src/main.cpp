#include "main.hpp"

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