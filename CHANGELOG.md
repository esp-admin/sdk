# Changelog


## v0.2.3

[compare changes](https://github.com/esp-admin/sdk/compare/v0.2.2...v0.2.3)


### 🩹 Fixes

  - **Update:** Add 5 sec delay before reset to complete MQTT publish process ([7d7a002](https://github.com/esp-admin/sdk/commit/7d7a002))

### 🏡 Chore

  - Set seperate certificates for HTTP and MQTT clients ([11a7138](https://github.com/esp-admin/sdk/commit/11a7138))
  - Create credentials.h file ([cde9402](https://github.com/esp-admin/sdk/commit/cde9402))
  - Update basic example ([e3eb2c5](https://github.com/esp-admin/sdk/commit/e3eb2c5))

### ❤️  Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v0.2.2

[compare changes](https://github.com/esp-admin/sdk/compare/v0.2.1...v0.2.2)


### 🏡 Chore

  - Change origin ([19a73af](https://github.com/esp-admin/sdk/commit/19a73af))

### ❤️  Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v0.2.1

[compare changes](https://github.com/esp-admin/sdk/compare/v0.2.0...v0.2.1)


### 🔥 Performance

  - **OTA:** Run process async on a seperate task ([dd40a46](https://github.com/esp-admin/sdk/commit/dd40a46))

### 🩹 Fixes

  - **Command:** Check if custom handler exists before calling it ([5e463ea](https://github.com/esp-admin/sdk/commit/5e463ea))
  - **HTTP:** On GET check status code before read response ([9b034d4](https://github.com/esp-admin/sdk/commit/9b034d4))
  - **HTTP:** On POST check status code before read response ([14b0f4d](https://github.com/esp-admin/sdk/commit/14b0f4d))
  - **Store:** Avoid storing setting on failed fetch ([402ea77](https://github.com/esp-admin/sdk/commit/402ea77))

### 💅 Refactors

  - Allow override of internal config values ([c950ca3](https://github.com/esp-admin/sdk/commit/c950ca3))

### 🏡 Chore

  - **MQTT:** Set keep alive to 30 sec ([041b834](https://github.com/esp-admin/sdk/commit/041b834))

### ❤️  Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v0.2.0

[compare changes](https://github.com/esp-admin/sdk/compare/v0.1.6...v0.2.0)


### 💅 Refactors

  - **Store:** ⚠️  Pass root ca cert as argument instead of hard coded value ([551ebf5](https://github.com/esp-admin/sdk/commit/551ebf5))

### 🏡 Chore

  - Update library.json ([c70987b](https://github.com/esp-admin/sdk/commit/c70987b))
  - Increase keep alive to 120 sec ([467ed28](https://github.com/esp-admin/sdk/commit/467ed28))
  - Set OTA timeout config ([7eb3385](https://github.com/esp-admin/sdk/commit/7eb3385))
  - **Update:** Change already updated log msg ([b6b0541](https://github.com/esp-admin/sdk/commit/b6b0541))

#### ⚠️  Breaking Changes

  - **Store:** ⚠️  Pass root ca cert as argument instead of hard coded value ([551ebf5](https://github.com/esp-admin/sdk/commit/551ebf5))

### ❤️  Contributors

- Becem-gharbi <becem.gharbi@live.com>
- Becem Gharbi <becem.gharbi@live.com>

## v0.1.6

[compare changes](https://github.com/esp-admin/sdk/compare/v0.1.5...v0.1.6)


### 🩹 Fixes

  - **NVS:** Store NULL values as empty strings ([8fd6cb2](https://github.com/esp-admin/sdk/commit/8fd6cb2))

### 🏡 Chore

  - Delete test directory ([0bedbe9](https://github.com/esp-admin/sdk/commit/0bedbe9))
  - Rename directory test to tests ([2e623f6](https://github.com/esp-admin/sdk/commit/2e623f6))

### ❤️  Contributors

- Becem Gharbi <becem.gharbi@live.com>
- Becem <becem.gharbi@live.com>

## v0.1.5

[compare changes](https://github.com/esp-admin/sdk/compare/v0.1.4...v0.1.5)


### 🔥 Performance

  - **OTA:** Use espressif APIs instead of arduino-esp32 ([486f3b3](https://github.com/esp-admin/sdk/commit/486f3b3))

### 🩹 Fixes

  - **MQTT:** Increase stack size to 10k ([e17716b](https://github.com/esp-admin/sdk/commit/e17716b))

### 🏡 Chore

  - Add test to gitignore ([5cc6bb3](https://github.com/esp-admin/sdk/commit/5cc6bb3))
  - Update ca root cert ([1a461d8](https://github.com/esp-admin/sdk/commit/1a461d8))
  - Update ssid ([ef53230](https://github.com/esp-admin/sdk/commit/ef53230))
  - Update ca root cert ([ab3c58a](https://github.com/esp-admin/sdk/commit/ab3c58a))

### ❤️  Contributors

- Becem Gharbi <becem.gharbi@live.com>

## v0.1.4

[compare changes](https://github.com/esp-admin/sdk/compare/v0.1.3...v0.1.4)


### 🩹 Fixes

  - **HTTP:** Only fail when -1 returned ([afe32f6](https://github.com/esp-admin/sdk/commit/afe32f6))

### ❤️  Contributors

- Becem Gharbi <becem.gharbi@live.com>

## v0.1.3

[compare changes](https://github.com/becem-gharbi/esp-admin-sdk/compare/v0.1.2...v0.1.3)


### 🏡 Chore

  - Update application domain ([ba9ee93](https://github.com/becem-gharbi/esp-admin-sdk/commit/ba9ee93))

### ❤️  Contributors

- Becem Gharbi <becem.gharbi@live.com>

## v0.1.2

[compare changes](https://github.com/becem-gharbi/esp-admin-sdk/compare/v0.1.1...v0.1.2)


### 💅 Refactors

  - Set mqtt subscribe method to public ([88f7d51](https://github.com/becem-gharbi/esp-admin-sdk/commit/88f7d51))

### 🏡 Chore

  - Set mqtt keep alive to 30 sec ([ff297ef](https://github.com/becem-gharbi/esp-admin-sdk/commit/ff297ef))

### ❤️  Contributors

- Becem Gharbi <becem.gharbi@live.com>

## v0.1.1

[compare changes](https://github.com/becem-gharbi/esp-admin-sdk/compare/v0.0.5...v0.1.1)


### 💅 Refactors

  - Rename debug to log ([1088e7d](https://github.com/becem-gharbi/esp-admin-sdk/commit/1088e7d))
  - Rename downloadUrl to download Path in update command ([6507c5d](https://github.com/becem-gharbi/esp-admin-sdk/commit/6507c5d))

### 📖 Documentation

  - **readme:** Remove under development warning ([2dda708](https://github.com/becem-gharbi/esp-admin-sdk/commit/2dda708))

### 🏡 Chore

  - Bump version to 0.1 ([209cab2](https://github.com/becem-gharbi/esp-admin-sdk/commit/209cab2))

### ❤️  Contributors

- Becem Gharbi ([@becem-gharbi](http://github.com/becem-gharbi))

## v0.0.5

[compare changes](https://github.com/becem-gharbi/esp-admin-sdk/compare/v0.0.4...v0.0.5)


### 💅 Refactors

  - Create download URL locally from relative path and httpHost ([6b98382](https://github.com/becem-gharbi/esp-admin-sdk/commit/6b98382))

### 📖 Documentation

  - Add documentation section ([567e66a](https://github.com/becem-gharbi/esp-admin-sdk/commit/567e66a))

### ❤️  Contributors

- Becem Gharbi ([@becem-gharbi](http://github.com/becem-gharbi))

## v0.0.4

[compare changes](https://github.com/becem-gharbi/esp-admin-sdk/compare/v0.0.3...v0.0.4)


### 📖 Documentation

  - Update readme ([62a74a4](https://github.com/becem-gharbi/esp-admin-sdk/commit/62a74a4))
  - Add platformio badge ([69eb580](https://github.com/becem-gharbi/esp-admin-sdk/commit/69eb580))

### 🏡 Chore

  - Add library.json and basic example ([b8858f4](https://github.com/becem-gharbi/esp-admin-sdk/commit/b8858f4))
  - Update basic example ([52884f8](https://github.com/becem-gharbi/esp-admin-sdk/commit/52884f8))
  - Update basic example ([79f1984](https://github.com/becem-gharbi/esp-admin-sdk/commit/79f1984))
  - Update default httpHost ([87dc2c8](https://github.com/becem-gharbi/esp-admin-sdk/commit/87dc2c8))

### ❤️  Contributors

- Becem Gharbi ([@becem-gharbi](http://github.com/becem-gharbi))
- Becem ([@becem-gharbi](http://github.com/becem-gharbi))

## v0.0.3

[compare changes](https://github.com/becem-gharbi/esp-admin-sdk/compare/v0.0.2...v0.0.3)


### 🚀 Enhancements

  - Implement getSettings on boot ([8d94dea](https://github.com/becem-gharbi/esp-admin-sdk/commit/8d94dea))
  - Implement custom resport ([329cb5e](https://github.com/becem-gharbi/esp-admin-sdk/commit/329cb5e))
  - Select mqtt by default and ws as fallback ([905ca68](https://github.com/becem-gharbi/esp-admin-sdk/commit/905ca68))

### 🔥 Performance

  - Implement minor memory optimizations ([d921b94](https://github.com/becem-gharbi/esp-admin-sdk/commit/d921b94))

### 🩹 Fixes

  - Add status to report update ([38e904c](https://github.com/becem-gharbi/esp-admin-sdk/commit/38e904c))
  - Fix custom report http path ([9ca3681](https://github.com/becem-gharbi/esp-admin-sdk/commit/9ca3681))

### 💅 Refactors

  - Implement minor refactoring ([e0cf930](https://github.com/becem-gharbi/esp-admin-sdk/commit/e0cf930))

### ❤️  Contributors

- Becem Gharbi ([@becem-gharbi](http://github.com/becem-gharbi))

## v0.0.2

[compare changes](https://github.com/becem-gharbi/esp-admin-sdk/compare/v0.0.1...v0.0.2)


### 🚀 Enhancements

  - Implement remote logger ([f31c692](https://github.com/becem-gharbi/esp-admin-sdk/commit/f31c692))
  - Implement remote logger enable/disable ([1d00e63](https://github.com/becem-gharbi/esp-admin-sdk/commit/1d00e63))
  - Implement command <restart> ([55a0dc3](https://github.com/becem-gharbi/esp-admin-sdk/commit/55a0dc3))
  - Implement command <update> ([2660c4f](https://github.com/becem-gharbi/esp-admin-sdk/commit/2660c4f))
  - Implement report <status> ([5bb0915](https://github.com/becem-gharbi/esp-admin-sdk/commit/5bb0915))
  - Implement status LWT ([d0d24f1](https://github.com/becem-gharbi/esp-admin-sdk/commit/d0d24f1))
  - Implement command <config> ([82214a7](https://github.com/becem-gharbi/esp-admin-sdk/commit/82214a7))
  - Implement command <custom> ([2b36e52](https://github.com/becem-gharbi/esp-admin-sdk/commit/2b36e52))
  - Implement report <update> ([927c65f](https://github.com/becem-gharbi/esp-admin-sdk/commit/927c65f))

### 🩹 Fixes

  - Use escape sequence in LwT message ([7447086](https://github.com/becem-gharbi/esp-admin-sdk/commit/7447086))

### 💅 Refactors

  - Use only ISRG_ROOT_X1 for CA certificate ([b659d93](https://github.com/becem-gharbi/esp-admin-sdk/commit/b659d93))

### ❤️  Contributors

- Becem Gharbi ([@becem-gharbi](http://github.com/becem-gharbi))

## v0.0.1


### 🚀 Enhancements

  - Implement serial logger ([c866305](https://github.com/becem-gharbi/esp-admin-sdk/commit/c866305))
  - Implement MQTT class ([4e074d6](https://github.com/becem-gharbi/esp-admin-sdk/commit/4e074d6))
  - Implement HTTP class ([b451dc1](https://github.com/becem-gharbi/esp-admin-sdk/commit/b451dc1))
  - Implement NVS & Store classes ([3a470ee](https://github.com/becem-gharbi/esp-admin-sdk/commit/3a470ee))
  - Implement OTA class ([b95ccdb](https://github.com/becem-gharbi/esp-admin-sdk/commit/b95ccdb))
  - Implement Update class ([d247f2c](https://github.com/becem-gharbi/esp-admin-sdk/commit/d247f2c))

### 💅 Refactors

  - Define project file structure ([c1f79bc](https://github.com/becem-gharbi/esp-admin-sdk/commit/c1f79bc))
  - **MQTT:** Set subscribe method as private ([d06f903](https://github.com/becem-gharbi/esp-admin-sdk/commit/d06f903))

### 📖 Documentation

  - Add README ([5ecb26c](https://github.com/becem-gharbi/esp-admin-sdk/commit/5ecb26c))
  - Update architecture img ([60443c0](https://github.com/becem-gharbi/esp-admin-sdk/commit/60443c0))

### 🏡 Chore

  - Add changelogen ([4db1095](https://github.com/becem-gharbi/esp-admin-sdk/commit/4db1095))
  - Set version to 0.0.0 ([c86c159](https://github.com/becem-gharbi/esp-admin-sdk/commit/c86c159))

### ❤️  Contributors

- Becem Gharbi ([@becem-gharbi](http://github.com/becem-gharbi))

