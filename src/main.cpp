#include "main.hpp"
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