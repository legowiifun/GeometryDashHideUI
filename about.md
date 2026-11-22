# Hide UI
This mod hides most UI elements from the screen using a customizable keybind. By default it is shift+H

To use these keybinds, you will need to have custom keybinds downloaded: https://geode-sdk.org/mods/geode.custom-keybinds. Otherwise, this mod will only work as an API to be used by other mods. 
If there is an element that is not hidden, download https://geode-sdk.org/mods/geode.devtools, then press F11 while in a level (it also works while paused), and find where the UI element is. It will likely be somewhere under PlayLayer. Once you think you found it, click on attributes, check the visible checkbox, and see if it disappears. If it does, then share the node id on the github for this mod. If there is no node id, still let me know, but also make it known wherever the mod developer takes their issues (some want them on Discord, others want them on GitHub, others want them on other platforms)

This is guarenteed to work with most vanilla UI elements. I have tested it with a couple others as well. However, it does not currently disable the built-in show hitboxes, or live death markers, in practice mode. 