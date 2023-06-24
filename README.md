# ESP Admin SDK

The sdk for [ESP Admin](https://github.com/becem-gharbi/esp-admin) platform

## ⚠️ Under development

This project is under developement. Any contribution you make is greatly appreciated.

## 🧱 Architecture

![architecture](https://pub-52f7e6f21f164b9e9f3f9c2df16ece76.r2.dev/sdk-architecture.png)

This is based on an initial conceptual design

### MQTT

MQTT client that should establish connection with the broker, publish and subscribe to device related topics.

### HTTP

HTTP client that should call REST API endpoints with authentication. Accepts `baseURL`, `path`, `method` and returns `response`

### Storage

- Based on Non-volatile storage.
- Should handle Flash encryption.
- Should provide `get`, `set` and `clear` methods.

### OTA

Performs OTA and report deployment status

### Store

Provides state management with namespaces:

- `status`: contains `mqtt`, `deployment` and `debug` status
- `auth`: contains `deviceId`, `mac`, `apiKey`
- `mqtt`: constains `uriTCP`, `uriWS`, `username`, `password`, `certificate`
- `soft`: contains `projectId`, `releaseId`
- `config`: contains project specific variables

### Logger

- Should accept:
  - `scope`: the class from which it's called, `app` by default
  - `type`: can be `error`, `warn`, `success` or `info` by default
  - `message`: the message string
- The output sources are:
  - `serial`: displayed on serial monitor, params are `enabled` and `baudrate`
  - `remote`: sent to the platform, params are `enabled`

### Command

Handles incomming command messages

- `onMessage`: parse received MQTT message
- `onCustom`: handle project specific commands
- `onUpdate`: calls OTA
- `onConfig`: update `config` in Store
- `onDebug`: update `status/debug` in Store
- `onRestart`: restarts device

### Report

Handles outgoing report messages

- `send`: send a report message
- `sendStatus`: send device connection status
- `sendUpdate`: send deployment status

### Settings

- `setAuth`: update `auth` in Store
