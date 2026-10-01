# Testing Plan

**Status: Proposed test cases; results pending.**

1. **Sensor check:** Point the sensor at a flat target at several known distances. Compare Serial Monitor readings with a ruler.
   - Expected: readings approximately track target distance within practical sensor accuracy.
2. **Low-level start logic:** With pump state OFF, provide a valid simulated/test distance >= 15 cm.
   - Expected: software requests pump ON.
3. **Near-full cutoff logic:** With pump state ON, provide a valid distance <= 5 cm.
   - Expected: software requests pump OFF.
4. **Hysteresis band:** Test distances between 5 and 15 cm from both initial states.
   - Expected: previous state is retained.
5. **Invalid echo:** Cause or simulate a timeout.
   - Expected: software reports invalid reading and requests pump OFF.
6. **Hardware demonstration (only after safe assembly):** Use a low-voltage DC pump and correctly rated separate supply; keep electronics dry and observe switching.

Record actual setup, readings, relay polarity, threshold behavior, failures, and code changes after testing. Do not report expected outcomes as measured results.
