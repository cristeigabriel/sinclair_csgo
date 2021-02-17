# sinclair_csgo
- My CS:GO cheat, written with performance in mind. 
- Currently **in development**, and I plan to keep this as such!

# Credits
- @swoopae for his hasher.
- @Speedi13 for his [Custom WINAPI](https://github.com/Speedi13/Custom-GetProcAddress-and-GetModuleHandle-and-more) functions.
- Other creators from whom I might've taken minimal contributions such as enumerators for various matters or even inspiration.

# Adresses (signatures)
- Addresses are stored at entry point in an array, being accessable by the StaticAddresses enumerator.
- It would not be relevant to list every stored address, as you can directly peek within the PE utilities header to see them fairly verboosely listed within an enumerator.

# Interfaces
- Interfaces are stored at entry point, and are accessible in the interfaces prototypes namespace.
- These are the current available interfaces:
  - IBaseClientDLL
  - ClientModeShared
  - CGlobalVarsBase
  - IVEngineClient
  - IClientEntityList
  - IEngineTraceClient
  - ISurface
  - ICVar
  - IInputSystem
  - CModelInfo

# Hooks
- Sinclair currently uses the GameOverlayRenderer.dll hooking utilities, and it comes with these specific hooks:
  - CreateMove (ClientModeShared one)
  - DrawCrosshair
  - FrameStageNotify
  - GetColorModulation
  - GetCSWpnData
  - GetCurrentGameType
  - IsUsingStaticPropDebugModes
  - Paint (Engine VGui)
  - PushNotice (CCSGOHudChat one)
  - SendNetMsg (CNetChan one)
  - 'vsnprintf' (Game formatting function)

# Props (Netvars)
- Sinclair stores every prop with it's submember's offsets in a double unordered map at entry point that uses hashes. 
- Alternatives could've been chose but it'd be likely that they'd be worse.

# Rendering
- Sinclair comes with an ISurface wrapper that supports both unicode strings by DrawColoredText (granting no conversion overhead, thus not making standard an issue at hand), with renderer functions font processing by compile-time since the fonts being stored in an array, with geometry templatized color-preservation abilities (the latter not being complete), these are the current wrapped geometry shapes:
  - Rectangle
  - Rectangle Outline
  - Line

# Design
- Sinclair is designed with what'd perform the best in mind, explaining the templates 'abuse'. 
- This could be a trade off, due to possibly extended compilation times, but this should not be noticeable when compiling on computers that benefit from the multi-processor option.
- In this current stage, it is very likely for inconsistencies in code to be noticeable, if you notice any of those, please proceed with reporting them or even making a pull request solving them. Sometimes, inconsistencies might be there for actual practical matters, the consistency being though opposed by my coding style. These inconsistencies though should not be often apparent.

# Features
- Outside of aforementioned capabilities, actual features are:
  - No Duck Delay
  - Force Crosshair
  - Dangerzone Compass
  - Nightmode (with static prop/skybox modulation)
  - net_graph watermark
  - FileCRCCheck netmessage protobuf bypass
