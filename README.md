# Automatic Water Level Controller with Pump Cutoff

**Category:** Embedded Systems | Automation | Arduino  
**Status:** Arduino code and design documentation; physical implementation/testing pending.

## Overview
An Arduino-based design to monitor water level and control a low-voltage DC pump using an HC-SR04 ultrasonic sensor and relay module. Two distance thresholds provide hysteresis to reduce rapid switching.

## Objectives
- Measure distance to the water surface.
- Start filling when water is low and stop near full.
- Control a separate pump supply through a relay module.
- Turn the pump command off if the sensor measurement is invalid.

## Components
| Component | Purpose |
|---|---|
| Arduino Uno | Reads sensor and controls relay |
| HC-SR04 | Measures water-surface distance |
| Compatible 5V relay module | Switches pump circuit |
| Low-voltage DC pump | Transfers water |
| Correctly rated DC supply | Powers pump |
| Jumper wires and container | Connections and demonstration |

## Pin mapping
| Arduino | Connection |
|---|---|
| D9 | HC-SR04 TRIG |
| D10 | HC-SR04 ECHO |
| D7 | Relay IN |
| 5V/GND | Sensor and compatible relay logic supply |

## Thresholds
- Distance >= 15 cm while pump is OFF: request pump ON.
- Distance <= 5 cm while pump is ON: request pump OFF.
- Between 5 and 15 cm: retain previous state.

These are example distances, not universal water-level values. Calibrate for the actual tank and sensor mounting.

## How it works
The sensor sends an ultrasonic pulse and measures echo duration. Distance is estimated as:

`distance_cm = echo_duration_us * 0.0343 / 2`

The division by two accounts for the outgoing and returning sound path. The Arduino applies the two-threshold control logic and reports readings at 9600 baud.

## Safety
This design is intended for a low-voltage DC demonstration pump. Do not power a pump from an Arduino I/O pin. Use a separate supply rated for the pump and a relay with suitable contact ratings. Keep electronics dry. Household AC mains are outside this beginner project.

## Repository
- `water_level_controller.ino` — starter Arduino sketch
- `circuit_connections.md` — wiring guidance
- `working_principle.md` — measurement and control explanation
- `testing_plan.md` — proposed validation steps

## Limitations and status
This repository contains source code and design documentation. Physical assembly, calibration, and performance testing have not been completed or verified. The invalid-reading behavior is a basic software response, not a complete industrial safety system.

## Future improvements
Sensor filtering, manual override, alarm indication, dry-run protection, and measured testing across multiple water levels.
