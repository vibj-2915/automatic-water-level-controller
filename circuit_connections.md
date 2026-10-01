# Circuit Connections

## HC-SR04 to Arduino Uno
| HC-SR04 | Arduino |
|---|---|
| VCC | 5V |
| TRIG | D9 |
| ECHO | D10 |
| GND | GND |

## Relay module to Arduino
| Relay module | Arduino |
|---|---|
| VCC | 5V, if supported by module |
| GND | GND |
| IN | D7 |

The sketch assumes an active-LOW relay. Verify the module's input polarity before connecting the pump.

## Low-voltage DC pump contacts
- DC supply positive -> Relay COM
- Relay NO -> Pump positive
- Pump negative -> DC supply negative

NO means normally open: the pump supply path is disconnected when the relay is inactive. Use a supply matching the pump voltage/current and observe relay contact ratings. Never connect the pump directly to an Arduino pin. Keep all electronics away from water; do not use household AC mains for this beginner setup.
