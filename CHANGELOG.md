# Changelog

## v2.0.1

[compare changes](https://github.com/esp-admin/sdk/compare/v2.0.0...v2.0.1)

### 🔥 Performance

- Migrate to `ArduinoJson` v7 ([236a636](https://github.com/esp-admin/sdk/commit/236a636))

### 🩹 Fixes

- **mqtt:** Fix MQTT connection status after disconnect ([a5cb082](https://github.com/esp-admin/sdk/commit/a5cb082))
- **mqtt:** Remove extra disconnection report (LWT sufficient) ([414b53b](https://github.com/esp-admin/sdk/commit/414b53b))

### 🏡 Chore

- **examples:** Update main.cpp on gprs ([fa806b6](https://github.com/esp-admin/sdk/commit/fa806b6))
- Develop with arduino framework ([4f12d8a](https://github.com/esp-admin/sdk/commit/4f12d8a))
- Update release script ([ef8fad0](https://github.com/esp-admin/sdk/commit/ef8fad0))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>
- Becem <becem.gharbi@live.com>

## v2.0.0

[compare changes](https://github.com/esp-admin/sdk/compare/v1.4.3...v2.0.0)

### 🚀 Enhancements

- ⚠️  Support `espidf` framework ([#2](https://github.com/esp-admin/sdk/pull/2))

### 🏡 Chore

- Bump version ([3eff33e](https://github.com/esp-admin/sdk/commit/3eff33e))

#### ⚠️ Breaking Changes

- ⚠️  Support `espidf` framework ([#2](https://github.com/esp-admin/sdk/pull/2))

### ❤️ Contributors

- Becem <becem.gharbi@live.com>
- Becem-gharbi <becem.gharbi@live.com>

## v1.4.3

[compare changes](https://github.com/esp-admin/sdk/compare/v1.4.2...v1.4.3)

### 🔥 Performance

- Store static log messages in Flash ([4822153](https://github.com/esp-admin/sdk/commit/4822153))

### 🩹 Fixes

- **HTTP:** Correctly set response buffer size ([b6c6eb5](https://github.com/esp-admin/sdk/commit/b6c6eb5))
- **Logger:** Correctly set message buffer size ([757eeac](https://github.com/esp-admin/sdk/commit/757eeac))
- **OTA:** Close HTTP connection before sending update status ([00a56ed](https://github.com/esp-admin/sdk/commit/00a56ed))

### 🏡 Chore

- Bump version ([f0d0e29](https://github.com/esp-admin/sdk/commit/f0d0e29))
- **HTTP:** Log reason on open connection fail ([4e7d619](https://github.com/esp-admin/sdk/commit/4e7d619))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v1.4.2

[compare changes](https://github.com/esp-admin/sdk/compare/v1.4.1...v1.4.2)

### 🩹 Fixes

- **Update:** Avoid sending duplicate progress values ([53232b7](https://github.com/esp-admin/sdk/commit/53232b7))

### 🏡 Chore

- Bump version ([4ea06b6](https://github.com/esp-admin/sdk/commit/4ea06b6))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v1.4.1

[compare changes](https://github.com/esp-admin/sdk/compare/v1.4.0...v1.4.1)

### 🔥 Performance

- Store static log messages in Flash ([8c07d9b](https://github.com/esp-admin/sdk/commit/8c07d9b))

### 💅 Refactors

- **HTTP:** Refactor `get` ([f117373](https://github.com/esp-admin/sdk/commit/f117373))
- **HTTP:** Refactor `post` ([a55eb1d](https://github.com/esp-admin/sdk/commit/a55eb1d))
- **MQTT:** Refactor `connect` ([67f8872](https://github.com/esp-admin/sdk/commit/67f8872))
- **MQTT:** Refactor `_onEvent` ([2dd3998](https://github.com/esp-admin/sdk/commit/2dd3998))
- **NVS:** Refactor `getString` ([1de636f](https://github.com/esp-admin/sdk/commit/1de636f))
- **NVS:** Refactor `setString` ([1f789a4](https://github.com/esp-admin/sdk/commit/1f789a4))
- **OTA:** Refactor `_task` ([69a24ad](https://github.com/esp-admin/sdk/commit/69a24ad))
- **Logger:** Do not specify data type ([d5fc4d7](https://github.com/esp-admin/sdk/commit/d5fc4d7))

### 🏡 Chore

- Bump version ([b37dc73](https://github.com/esp-admin/sdk/commit/b37dc73))
- Change OTA and MQTT default stack size ([2c8cffa](https://github.com/esp-admin/sdk/commit/2c8cffa))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v1.4.0

[compare changes](https://github.com/esp-admin/sdk/compare/v1.3.0...v1.4.0)

### 🚀 Enhancements

- **OTA:** Publish progress on `device/+/report/update/progress` ([8b86b72](https://github.com/esp-admin/sdk/commit/8b86b72))
- **Update:** Add abort option ([abfb73c](https://github.com/esp-admin/sdk/commit/abfb73c))

### 🔥 Performance

- **OTA:** Avoid running ota task when connection failed ([832f489](https://github.com/esp-admin/sdk/commit/832f489))

### 🩹 Fixes

- **OTA:** Set initial progress state to `0` ([256cd2f](https://github.com/esp-admin/sdk/commit/256cd2f))
- **Update:** Avoid progress calculation when image size unknown ([991e0f0](https://github.com/esp-admin/sdk/commit/991e0f0))

### 💅 Refactors

- **OTA:** Use advanced APIs ([7c4763f](https://github.com/esp-admin/sdk/commit/7c4763f))
- **Logger:** Change style of log message ([0c4f5d3](https://github.com/esp-admin/sdk/commit/0c4f5d3))
- No significant change ([24f7612](https://github.com/esp-admin/sdk/commit/24f7612))

### 🏡 Chore

- Bump version ([33f8949](https://github.com/esp-admin/sdk/commit/33f8949))
- Build compilation database ([74388a0](https://github.com/esp-admin/sdk/commit/74388a0))
- **examples:** Set mqttCert for HiveMQ Cloud ([52b5f77](https://github.com/esp-admin/sdk/commit/52b5f77))
- Add doc comments for public methods ([73b16e9](https://github.com/esp-admin/sdk/commit/73b16e9))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v1.3.0

[compare changes](https://github.com/esp-admin/sdk/compare/v1.2.3...v1.3.0)

### 🚀 Enhancements

- Set internal config options on initialization ([ee708f0](https://github.com/esp-admin/sdk/commit/ee708f0))

### 🩹 Fixes

- **log:** Set default message max size locally ([b34f214](https://github.com/esp-admin/sdk/commit/b34f214))

### 💅 Refactors

- Increase log message max size ([1d9a41a](https://github.com/esp-admin/sdk/commit/1d9a41a))

### 🏡 Chore

- Sync version ([9c8f944](https://github.com/esp-admin/sdk/commit/9c8f944))
- Update examples ([92b1533](https://github.com/esp-admin/sdk/commit/92b1533))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v1.2.3

[compare changes](https://github.com/esp-admin/sdk/compare/v1.2.2...v1.2.3)

### 💅 Refactors

- **MQTT:** Create a `publish` overload ([2a1b853](https://github.com/esp-admin/sdk/commit/2a1b853))

### 🏡 Chore

- **library.json:** Bump version ([46c308b](https://github.com/esp-admin/sdk/commit/46c308b))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v1.2.2

[compare changes](https://github.com/esp-admin/sdk/compare/v1.2.1...v1.2.2)

### 🩹 Fixes

- **NVS:** Return empty string when nvs_get_str failed ([5bbf722](https://github.com/esp-admin/sdk/commit/5bbf722))
- **HTTP:** Initialize response buffers ([1a5d5ff](https://github.com/esp-admin/sdk/commit/1a5d5ff))

### 💅 Refactors

- **Command:** Increase _onUpdate document size ([73b23ce](https://github.com/esp-admin/sdk/commit/73b23ce))
- **HTTP:** Increase response buffer size ([b49ad82](https://github.com/esp-admin/sdk/commit/b49ad82))
- **MQTT:** Increase stack size ([a616157](https://github.com/esp-admin/sdk/commit/a616157))

### 🏡 Chore

- Sync library.json ([ff44570](https://github.com/esp-admin/sdk/commit/ff44570))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v1.2.1

[compare changes](https://github.com/esp-admin/sdk/compare/v1.2.0...v1.2.1)

### 🩹 Fixes

- **Store:** Disable remote logging by default ([83b178b](https://github.com/esp-admin/sdk/commit/83b178b))

### 🏡 Chore

- **examples:** Add lvgl example ([2ea8a5e](https://github.com/esp-admin/sdk/commit/2ea8a5e))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v1.2.0

[compare changes](https://github.com/esp-admin/sdk/compare/v1.1.2...v1.2.0)

### 🚀 Enhancements

- **Command:** Add onConfig method ([997bb02](https://github.com/esp-admin/sdk/commit/997bb02))

### 💅 Refactors

- **Command:** Create _onCustom method ([a3161be](https://github.com/esp-admin/sdk/commit/a3161be))
- Add warning on deserializeJson fail ([3d7544f](https://github.com/esp-admin/sdk/commit/3d7544f))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v1.1.2

[compare changes](https://github.com/esp-admin/sdk/compare/v1.0.0...v1.1.2)

### 🩹 Fixes

- Send disconnected report status before reset ([8b2c4a1](https://github.com/esp-admin/sdk/commit/8b2c4a1))

### 🏡 Chore

- Remove rc suffix ([72c2514](https://github.com/esp-admin/sdk/commit/72c2514))
- **release:** V1.0.1 ([b257b70](https://github.com/esp-admin/sdk/commit/b257b70))
- Exclude node files from library pkg ([dae2e41](https://github.com/esp-admin/sdk/commit/dae2e41))
- Bump version to 1.1.1 ([345b066](https://github.com/esp-admin/sdk/commit/345b066))

### ❤️ Contributors

- Becem-gharbi ([@becem-gharbi](http://github.com/becem-gharbi))

## v1.0.1

[compare changes](https://github.com/esp-admin/sdk/compare/v1.0.0...v1.0.1)

### 🩹 Fixes

- Send disconnected report status before reset ([8b2c4a1](https://github.com/esp-admin/sdk/commit/8b2c4a1))

### 🏡 Chore

- Remove rc suffix ([72c2514](https://github.com/esp-admin/sdk/commit/72c2514))

### ❤️ Contributors

- Becem-gharbi ([@becem-gharbi](http://github.com/becem-gharbi))

## v1.0.0

[compare changes](https://github.com/esp-admin/sdk/compare/v1.1.1-rc...main)

### 🩹 Fixes

- **Update:** Avoid concurrent updates ([d2e7b5d](https://github.com/esp-admin/sdk/commit/d2e7b5d))

### 🏡 Chore

- Bump version to 1.0.0 ([2d26997](https://github.com/esp-admin/sdk/commit/2d26997))

### ❤️ Contributors

- Becem-gharbi ([@becem-gharbi](http://github.com/becem-gharbi))

## v1.1.1-rc

[compare changes](https://github.com/esp-admin/sdk/compare/v1.1.0-rc...v1.1.1-rc)

### 🩹 Fixes

- **Report:** Increase Json buffer to avoid potential overflow ([2a3c0ca](https://github.com/esp-admin/sdk/commit/2a3c0ca))

### 🏡 Chore

- Sync library.json ([3cba4fd](https://github.com/esp-admin/sdk/commit/3cba4fd))

### ❤️ Contributors

- Becem-gharbi ([@becem-gharbi](http://github.com/becem-gharbi))

## v1.1.0-rc

[compare changes](https://github.com/esp-admin/sdk/compare/v1.0.1-rc...v1.1.0-rc)

### 🚀 Enhancements

- **Logger:** Add string interpolation ([a5fd337](https://github.com/esp-admin/sdk/commit/a5fd337))

### 🔥 Performance

- Pass Strings by reference ([8d3fc01](https://github.com/esp-admin/sdk/commit/8d3fc01))
- **MQTT:** Reduce stack size to 6kB (uses 4.7kB) ([535360d](https://github.com/esp-admin/sdk/commit/535360d))
- **OTA:** Reduce stack size to 6kB (uses 5kB) ([82fce7d](https://github.com/esp-admin/sdk/commit/82fce7d))
- **HTTP:** Reduce response buffer size to 200B (used 100B) ([5d3075a](https://github.com/esp-admin/sdk/commit/5d3075a))
- Set stack sizes 1KB larger than max used size ([88703b9](https://github.com/esp-admin/sdk/commit/88703b9))

### 🩹 Fixes

- **MQTT:** Disconnect on destruction ([154719d](https://github.com/esp-admin/sdk/commit/154719d))
- **NVS:** Fix memory leak on getString ([adf80ad](https://github.com/esp-admin/sdk/commit/adf80ad))
- **MQTT:** Avoid heap allocation on connect ([aafa10e](https://github.com/esp-admin/sdk/commit/aafa10e))
- **Logger:** Add scope to MQTT message ([04d0f02](https://github.com/esp-admin/sdk/commit/04d0f02))

### 💅 Refactors

- Follow C++ guidelines ([9539068](https://github.com/esp-admin/sdk/commit/9539068))
- Minor refactoring ([a3501ca](https://github.com/esp-admin/sdk/commit/a3501ca))
- Minor refactoring ([e865507](https://github.com/esp-admin/sdk/commit/e865507))
- Minor refactoring ([d0dc632](https://github.com/esp-admin/sdk/commit/d0dc632))

### 🏡 Chore

- Add credentials.h to ignore ([636900a](https://github.com/esp-admin/sdk/commit/636900a))
- Sync library version ([73c8a5b](https://github.com/esp-admin/sdk/commit/73c8a5b))
- Set monitor speed to 115200 ([1436280](https://github.com/esp-admin/sdk/commit/1436280))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v1.0.1-rc

[compare changes](https://github.com/esp-admin/sdk/compare/v0.2.4...v1.0.1-rc)

### 🏡 Chore

- **Update:** Set reset delay to 8 sec ([6d10f2a](https://github.com/esp-admin/sdk/commit/6d10f2a))
- Bump version to 1.0.0 ([1deb7da](https://github.com/esp-admin/sdk/commit/1deb7da))
- Upgrade changelogen ([7f7466f](https://github.com/esp-admin/sdk/commit/7f7466f))

### ❤️ Contributors

- Becem-gharbi <becem.gharbi@live.com>

## v0.2.4

[compare changes](https://github.com/esp-admin/sdk/compare/v0.2.3...v0.2.4)


### 🏡 Chore

  - Delete src/main.cpp ([4d94250](https://github.com/esp-admin/sdk/commit/4d94250))
  - Delete design directory ([55832e9](https://github.com/esp-admin/sdk/commit/55832e9))
  - Exclude main.cpp from pkg build ([b7858bc](https://github.com/esp-admin/sdk/commit/b7858bc))

### ❤️  Contributors

- Becem-gharbi <becem.gharbi@live.com>
- Becem <becem.gharbi@live.com>

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

