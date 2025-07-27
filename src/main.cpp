#pragma once
/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
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
		{keybinds::Keybind::create(KEY_H, keybinds::Modifier::Shift)},
		"Play/UI"
	});
}
bool isHidden = false;