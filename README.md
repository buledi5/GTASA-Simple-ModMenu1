
# GTA SA Simple Mod Menu

A native Android mod-menu starter project for GTA San Andreas.

## Target

- GTA San Andreas Android 2.00
- Android Mod Loader (AML) 2.0
- ARM64 (`arm64-v8a`)
- Mali-G57 devices
- C++17
- GTA V Simple-inspired menu design

## Project structure

```text
GTASA-Simple-ModMenu/
├── .github/
│   └── workflows/
│       └── build.yml
├── src/
│   └── main.cpp
├── CMakeLists.txt
└── README.md
```

## Build

1. Open the Actions tab on GitHub.
2. Select Build GTA SA Simple Mod Menu.
3. Press Run workflow.
4. Wait for the build to finish.
5. Download the GTASA-SimpleMenu-ARM64 artifact.

## Current status

This is an initial native-library starter.

The AML plugin registration, in-game menu rendering,
and GTA SA-specific features still need to be implemented
and tested against the target game and AML SDK.

## License

For educational and personal modding use.
