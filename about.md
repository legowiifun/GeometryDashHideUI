# Hide UI
This mod hides most UI elements from the screen using a customizable keybind. By default it is shift+H (it used to be just H, but I learned about keybind modifiers).
If there is one that is not hidden, download https://geode-sdk.org/mods/geode.devtools, then press F11 while in a level (it also works while paused), and find where the UI element is. It will likely be somewhere under PlayLayer. Once you think you found it, click on attributes, check the visible checkbox, and see if it disappears. If it does, then share the node id on the github for this mod. If there is no node id, still let me know, but also make it known wherever the mod developer takes their issues (some want them on Discord, others want them on GitHub, others want them on other platforms)

If you are making a mod that modifies the UI, and you want it to automatically be hidden when this mod is activated without me needing to update it, place your new UI elements in the UILayer.

This mod is known not to work with: the players in Globed, Prism Menu's UI elements, Friends!, and a couple UI elements in the main levels (this is a bug on Node ID's end, they work fine in custom levels). Most of the ones listed here are because the mod developers did not add node ids to their custom nodes. 

Some mods that this mod is guarenteed to work with: Megahack, Stat Display, the progress bar and ping labels of Globed, PlatformerGhosts, channelViewer, QOLMod, RunInfo, Eclipse, Speedrun Timer, Servers Status, and GDH.