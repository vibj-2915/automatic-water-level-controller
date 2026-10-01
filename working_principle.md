# Working Principle

## Ultrasonic measurement
The HC-SR04 emits an ultrasonic pulse and measures the time for its echo to return. Approximate distance:

`distance = (echo time × speed of sound) / 2`

The code uses 0.0343 cm/µs as an approximate speed of sound. The factor of two accounts for the round trip.

## Interpreting the reading
The sensor is mounted above the water and points downward:
- Larger distance means a lower water level.
- Smaller distance means a higher water level.

The sensor measures distance, not water height directly. Tank dimensions and mounting location determine the relationship.

## Hysteresis control
Two example thresholds are used:
- Start: distance >= 15 cm.
- Stop: distance <= 5 cm.
- Between thresholds: retain the prior pump state.

This gap helps prevent rapid switching around one threshold.

## Invalid readings
If `pulseIn` times out, the code returns -1 and requests pump OFF. This is a basic fail-safe behavior and does not replace hardware protection or supervised testing.
