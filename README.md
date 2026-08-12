# 🌱 Garden Monitoring System

An Arduino project (from the Electronics course) that measures light level (using an LDR) and soil moisture, displays the readings live on a 16x2 LCD, and triggers a buzzer if the plant needs to be watered or exposed to the sun.

---

## ✨ Features

- Real-time light and soil moisture readings
- An LCD screen showing live status alerts
- A buzzer that goes off for low light or water
- Logging via Serial monitor
- Threshold settings and PWM LCD contrast control

---

## 🔌 Wiring

| Pin | Component |
|---|---|
| A0 | Light sensor |
| A1 | Soil moisture sensor |
| D6 | Buzzer |
| D9 | LCD contrast (PWM) |
| D12, D11, D5, D4, D3, D2 | LCD RS, E, D4-D7 |

---

## ⚙️ Operation

The main loop continuously reads the raw data from each sensor → translates it into percentage → updates the LCD every second (`Light: XX%`/`NEED SUN!` `Water: XX%`/`NEED WATER!`) → activates the buzzer if any one is below its threshold value → logs all the values on the Serial monitor.

---

## 🎚️ Calibration

The threshold values are define constants right at the start of the code (`LDR_MIN/MAX_RAW`, `SOIL_DRY/WET_RAW`, `MIN_LIGHT/WATER_THRESHOLD`). Measure the `analogRead()` values in known conditions to calibrate your sensors.

---

## 👌 To Get Started

1. Follow the wiring schema shown above.
2. Upload the Arduino sketch (LiquidCrystal library is required).
3. Open the Serial Monitor (baud rate is 9600).

---

## 🔮 Further Work

Adding a DHT sensor for temperature and humidity measuring · auto irrigation system pump · WiFi/BT communication · muting buzzer switch

---

*Electronics course project. FCIS, Ain Shams University.*
