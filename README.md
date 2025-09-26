# 7697 Robotic Arm

A collection of Arduino sketches for controlling a simple 4‑DOF robotic arm with the LinkIt 7697 board. Examples range from basic servo sweeps to Wi‑Fi control via MediaTek Cloud Sandbox (MCS), including a BlocklyDuino‑generated example.

## What’s inside

- `test1/` — Sweep four servos on pins 7–10 in sync using `Servo.writeMicroseconds`.
- `test2/` — Control servos via serial input (send values over Serial to move pins 7–10).
- `test3/` — Connects 7697 to Wi‑Fi and demonstrates raw HTTP calls to MCS.
- `test4/` — Wi‑Fi + MCS library control of one servo using a PWM controller channel `sd`.
- `test5/` — BlocklyDuino‑generated sketch controlling 4 servos from MCS integer channels `a1`–`a4`.

## Hardware required

- LinkIt 7697 board
- 4× hobby servos (connected to pins 7, 8, 9, 10)
- External 5V power supply for servos (recommended); share ground with the 7697
- Micro‑USB cable
- 2.4 GHz Wi‑Fi network

## Software and libraries

- Arduino IDE with LinkIt 7697 board support
- Libraries (install via Arduino Library Manager or the LinkIt SDK):
  - `Servo`
  - `LWiFi`, `LWiFiClient`, `LTask`
  - `MCS` (MediaTek Cloud Sandbox Arduino library)

## Configure the sketches

Update Wi‑Fi and MCS credentials directly in the sketches:

- `test4/test4.ino`
  - Wi‑Fi: `_SSID`, `_KEY`
  - MCS: `MCSDevice mcs("<deviceId>", "<deviceKey>")`
  - Channel: `MCSControllerPWM servo_degree("sd")`

- `test5/test5.ino`
  - Wi‑Fi: `_lwifi_ssid`, `_lwifi_pass`
  - MCS: `MCSDevice mcs("<deviceId>", "<deviceKey>")`
  - Channels: `a1`, `a2`, `a3`, `a4` (Integer controllers)

- `test3/test3.ino`
  - Wi‑Fi: `WIFI_AP`, `WIFI_PASSWORD`
  - Raw HTTP to MCS: replace the device ID in the URL path and `deviceKey` header

Tip: Do not commit real device keys to public repos.

## Set up MCS (MediaTek Cloud Sandbox)

1. Create a device and note its device ID and device key.
2. Add channels (IDs must match the sketches):
   - `test4`: Controller → PWM → channel id `sd`.
   - `test5`: Controller → Integer → channel ids `a1`, `a2`, `a3`, `a4`.

## Build and upload

1. Open a sketch (e.g., `test4/test4.ino`) in Arduino IDE.
2. Select board: LinkIt 7697.
3. Select the correct serial port.
4. Verify/Compile, then Upload.

## How to use

- `test1` — The servos sweep automatically.
- `test2` — Send bytes over Serial (e.g., via Serial Monitor). Values will be used to position servos on pins 7–10.
- `test3` — On boot, connects to AP and demonstrates an HTTP request to MCS; watch Serial for logs.
- `test4` — After connecting to Wi‑Fi and MCS, adjust the `sd` PWM channel value in MCS to move the servo on pin 7.
- `test5` — After connecting, set integer channel values `a1`–`a4` in MCS to move the four servos.

## Safety and notes

- Power servos from a stable 5V supply; tie servo ground to the 7697 ground.
- Typical servo angle range is 0–180; microsecond pulse ranges often ~500–2400 μs.
- Wi‑Fi SSID/password and MCS credentials are hardcoded in examples for simplicity. Replace them before uploading.

---

7697 MCS 手臂控制：包含基本伺服馬達測試、Wi‑Fi 連線與 MCS 控制範例。請在程式內更新 Wi‑Fi 與 MCS 參數（如 `SSID`、`deviceId`、`deviceKey`、頻道 ID），再編譯與上傳。
