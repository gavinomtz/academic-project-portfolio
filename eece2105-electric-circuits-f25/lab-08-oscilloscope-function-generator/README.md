# Lab 08 - Oscilloscope & Function Generator

Introduction to essential test equipment for AC circuit analysis: digital oscilloscope operation and function generator control. Demonstrates time-domain waveform visualization, frequency measurement, and proper use of laboratory instrumentation.

## 🎯 Laboratory Objectives

- **Oscilloscope Proficiency** - Identify and adjust vertical, horizontal, and trigger controls
- **Calibration Verification** - Observe and validate internal calibration waveforms
- **Function Generator Operation** - Configure waveform type, frequency, and amplitude
- **Waveform Analysis** - Measure peak-to-peak voltage, frequency, and period from displayed signals
- **Multi-Waveform Testing** - Generate and observe sine, triangle, and square waves across frequency ranges

## 🔬 Equipment & Instrumentation

| Equipment | Model/Specifications | Purpose |
|-----------|---------------------|---------|
| Digital Oscilloscope | Dual-trace (2-channel) | Time-domain signal visualization |
| Function Generator | 1 Hz - 10 MHz range | Arbitrary waveform generation |
| BNC Cables | 50Ω coaxial | Signal transmission |
| Oscilloscope Probes | 10:1 attenuation (typical) | Signal acquisition |

## 📊 Experimental Procedures

### Part 1: Oscilloscope Calibration & Control

**Objective:** Familiarize with oscilloscope operation using internal calibration signal

**Procedure:**
1. Connect probe to CH1 or CH2
2. Attach probe tip to PROBE CHECK/CAL terminal
3. Press AUTO SET for automatic configuration
4. Observe 5V peak-to-peak square wave at 1 kHz
5. Manually adjust Volts/Div and Sec/Div controls
6. Document waveform appearance at different scales
7. Answer after-lab questions regarding the content covered

**Key Measurements:**

| Configuration | Volts/Div | Time/Div | Cycles Displayed | Notes |
|---------------|-----------|----------|------------------|-------|
| Figure 4a (Baseline) | 5 V/Div | 250 μs/Div | ~4 cycles | Standard calibration |
| Figure 4b (Vertical Scale) | 2 V/Div | 250 μs/Div | ~4 cycles | Increased vertical resolution |
| Figure 4c (Horizontal Scale) | 2 V/Div | 500 μs/Div | ~2 cycles | Expanded time scale |

**Observations:**
- **Volts/Div Change:** Affects waveform height/amplitude display (not actual signal)
- **Sec/Div Change:** Affects number of cycles visible (not signal frequency)
- **Calibration Signal:** Remains constant at 1 kHz regardless of scope settings

---

### Part 2: Function Generator Operation

**Objective:** Generate various waveforms and analyze frequency-domain relationships

#### Experiment 2.1: Sine Wave Generation

**Setup:**
- Function generator output → Oscilloscope CH1 input
- Initial settings: 1 kHz sine wave, mid-level amplitude
- Adjust scope for single-cycle display

**Measurements:**

| Frequency | Volts/Div | Time/Div | Cycles Displayed | Waveform |
|-----------|-----------|----------|------------------|----------|
| 1 kHz | 2 V/Div | 400 μs/Div | ~2.5 cycles | Sine wave |
| 2 kHz | 2 V/Div | 100 μs/Div | ~2 cycles | Sine wave |

**Analysis:**
- Doubling frequency from 1 kHz → 2 kHz doubles visible cycles (at constant time/div)
- Peak-to-peak voltage remains constant (~6 divisions = 12V pp)

#### Experiment 2.2: Triangle Wave Analysis

**Setup:** Same connections, switch function generator to triangle/ramp output

**Measurements:**

| Frequency | Volts/Div | Time/Div | Cycles Displayed | Waveform |
|-----------|-----------|----------|------------------|----------|
| 1 kHz | 2 V/Div | 100 μs/Div | 1 cycle | Triangle wave |
| 2 kHz | 2 V/Div | 100 μs/Div | 2 cycles | Triangle wave |

**Analysis:**
- Triangle wave exhibits linear voltage transitions (constant slope)
- Same frequency-cycle relationship observed as sine wave

#### Experiment 2.3: Square Wave Characterization

**Setup:** Same connections, switch to square wave output

**Measurements:**

| Frequency | Volts/Div | Time/Div | Cycles Displayed | Waveform |
|-----------|-----------|----------|------------------|----------|
| 1 kHz | 2 V/Div | 100 μs/Div | 1 cycle | Square wave |
| 2 kHz | 2 V/Div | 100 μs/Div | 2 cycles | Square wave |

**Analysis:**
- Square wave shows instantaneous voltage transitions (ideal switching)
- Rise/fall time limited by oscilloscope bandwidth and probe characteristics

## 🔑 Key Concepts Demonstrated

### Oscilloscope Operation
- **Vertical System** - Volts/Div sets voltage sensitivity per graticule division
- **Horizontal System** - Sec/Div sets time base (sweep rate)
- **Trigger System** - Synchronizes display to stable waveform
- **Dual-Trace Capability** - Simultaneous observation of two signals

### Waveform-Frequency Relationship
**Critical Finding:** At constant time/div setting:
```
Cycles displayed ∝ Signal frequency
```

**Example from Lab Data:**
- At 100 μs/Div time base:
  - 1 kHz signal → 1 cycle displayed
  - 2 kHz signal → 2 cycles displayed
  - Relationship: 2× frequency = 2× cycles

**Mathematical Basis:**
```
Period (T) = 1 / Frequency (f)

For 1 kHz: T = 1 ms (1 cycle takes 1 ms)
For 2 kHz: T = 0.5 ms (1 cycle takes 0.5 ms)

At 100 μs/Div with 10 divisions:
Total display time = 100 μs × 10 = 1 ms

Therefore:
- 1 kHz fits 1 cycle in 1 ms window
- 2 kHz fits 2 cycles in 1 ms window
```

### Function Generator Characteristics
- **Waveform Types:** Sine (harmonic), Triangle (linear ramp), Square (digital switching)
- **Frequency Range:** Typically 0.1 Hz to 10+ MHz
- **Amplitude Control:** Adjustable output voltage level
- **Frequency Accuracy:** Crystal-controlled for precise timing

## 📈 Post-Lab Analysis

### Question 1: Effect of Time Base Change
**Question:** When sec/div changed from 250 μs to 500 μs, what happened to cycles displayed?

**Answer:** The number of visible cycles doubled. 

**Explanation:** 
- Original: 250 μs/Div × 10 Div = 2.5 ms total display window → ~2.5 cycles of 1 kHz signal
- Modified: 500 μs/Div × 10 Div = 5 ms total display window → ~5 cycles of 1 kHz signal

The oscilloscope displays more of the waveform's time history without changing the signal itself.

---

### Question 2: Does Time Base Affect Frequency?
**Question:** Was the calibration waveform frequency changed by sec/div adjustment?

**Answer:** No, the frequency remained constant at 1 kHz.

**Explanation:** 
The sec/div control affects the **horizontal scale factor** (how the oscilloscope displays time), not the signal's actual frequency. The calibration signal is generated independently by the oscilloscope's internal circuitry and maintains constant frequency regardless of display settings.

**Analogy:** Changing sec/div is like zooming in/out on a graph—you see more or fewer cycles, but the underlying signal doesn't change.

---

### Question 3: Control Functions
**Question:** Which oscilloscope controls affect these parameters?

**Answers:**
- **Waveform Height:** Volts/Div (vertical sensitivity)
- **Cycles Displayed:** Sec/Div (horizontal time base)
- **Waveform Starting Point:** Horizontal Position control
- **Waveform Position:** Vertical Position (CH1/CH2 knobs) and Horizontal Position
- **Sweep Trigger:** Trigger Level control (sets voltage threshold for display synchronization)

---

### Question 4: Frequency-Cycle Relationship
**Question:** Describe relationship between cycles displayed and frequency (constant time/div).

**Answer Based on Lab Data:**

When time/div remains constant, the number of cycles displayed is **directly proportional** to frequency:

**Evidence from Measurements:**
```
Sine Wave (100 μs/Div time base):
- 1 kHz → 1 cycle displayed
- 2 kHz → 2 cycles displayed
- Ratio: 2× frequency = 2× cycles

Triangle/Square Waves (100 μs/Div):
- Same relationship observed
- 1 kHz → 1 cycle
- 2 kHz → 2 cycles
```

**Physical Interpretation:**
The oscilloscope displays a fixed time window (determined by sec/div × number of divisions). Higher frequency signals complete more cycles in the same time window, so more cycles appear on screen.

**Formula:**
```
Cycles displayed = (Total display time) × (Signal frequency)
                 = (Sec/Div × 10 divisions) × f
```

## 🎓 Skills Demonstrated

### Laboratory Techniques
- **Instrumentation Setup** - Proper cable connections, grounding, probe compensation
- **Signal Observation** - Identifying waveform characteristics from oscilloscope display
- **Parameter Measurement** - Reading voltage and time values from graticule
- **Equipment Operation** - Navigating oscilloscope menus and function generator controls
- **Systematic Documentation** - Recording settings and observations with precision

### Engineering Analysis
- **Time-Domain Visualization** - Interpreting voltage vs. time relationships
- **Frequency Measurement** - Calculating frequency from period measurements
- **Scale Factor Analysis** - Understanding how display settings affect measurements
- **Waveform Characterization** - Distinguishing sine, triangle, and square wave properties
- **Calibration Verification** - Using known signals to validate instrument accuracy

### Technical Communication
- **Waveform Sketching** - Accurate graphical representation of observed signals
- **Data Tabulation** - Organized presentation of measurement parameters
- **Written Analysis** - Clear explanation of experimental observations
- **Professional Reporting** - Structured laboratory documentation

## 🔧 Practical Applications

### Time-Domain Measurements
**What the oscilloscope reveals:**
- **Amplitude:** Peak-to-peak voltage, RMS voltage, DC offset
- **Timing:** Period, frequency, pulse width, duty cycle
- **Shape:** Distortion, overshoot, ringing, noise
- **Phase:** Relative timing between two signals (dual-trace)

### Function Generator Uses
**Common applications:**
- **Circuit Testing:** Applying known test signals to circuits under development
- **Frequency Response:** Sweeping frequency to characterize filters and amplifiers
- **Digital Logic:** Generating clock signals for sequential circuits
- **Audio Testing:** Creating reference tones for audio equipment calibration
- **Pulse Generation:** Producing specific timing waveforms for embedded systems

### Industry Relevance
**Where these skills matter:**
- **Embedded Systems:** Debugging SPI/I2C/UART communication signals
- **Power Electronics:** Analyzing switching waveforms in DC-DC converters
- **RF Engineering:** Observing modulated carrier signals
- **Audio Design:** Testing amplifier frequency response and distortion
- **Digital Design:** Verifying clock signals and data transitions

## 📚 Theoretical Foundation

### Waveform Types & Properties

**Sine Wave:**
- **Mathematical Form:** V(t) = A·sin(2πft + φ)
- **Characteristics:** Smooth, single frequency component (pure tone)
- **Applications:** AC power distribution, audio signals, carrier waves
- **Harmonics:** None (fundamental frequency only)

**Triangle Wave:**
- **Mathematical Form:** Piecewise linear with constant slope
- **Characteristics:** Linear voltage transitions, symmetric rise/fall
- **Applications:** Oscillator circuits, sawtooth generators, sweep signals
- **Harmonics:** Odd harmonics with 1/n² amplitude decay

**Square Wave:**
- **Mathematical Form:** Alternating between two voltage levels
- **Characteristics:** Instantaneous transitions (ideal), 50% duty cycle
- **Applications:** Digital clock signals, PWM control, logic testing
- **Harmonics:** All odd harmonics with 1/n amplitude decay

### Time-Base Mathematics

**Period-Frequency Relationship:**
```
T = 1/f

Where:
T = Period (seconds per cycle)
f = Frequency (cycles per second, Hz)
```

**Display Window Calculation:**
```
Total display time = (Time/Div setting) × (Number of divisions)

Example: 100 μs/Div × 10 divisions = 1 ms = 1000 μs

Cycles in window = (Total display time) / (Period of signal)
                 = (Total display time) × (Frequency of signal)
```

## 📁 Laboratory Deliverables

This laboratory work includes:
- **`lab-08-report.pdf`** - Complete technical report with:
  - Experimental procedures
  - Waveform sketches (Figures 4a-c, 5a-b, 6a-d)
  - Measurement tables with all parameters
  - Post-lab analysis and answers
  - Conclusions about oscilloscope/function generator operation

## 🎯 Learning Outcomes

Upon completion of this laboratory, students can:

✅ Operate digital oscilloscope controls (vertical, horizontal, trigger systems)  
✅ Interpret graticule measurements for voltage and time  
✅ Configure function generator for various waveforms and frequencies  
✅ Recognize relationship between display settings and waveform appearance  
✅ Distinguish sine, triangle, and square waveforms by visual inspection  
✅ Calculate frequency from period measurements  
✅ Understand that scope settings affect display, not signal characteristics  
✅ Document waveform observations with proper technical notation  

## 📞 Course Information

**Course:** EECE 2105 - Electric Circuits I Laboratory  
**Student:** Gavino Martinez (ID: 20678524)  
**Institution:** University of Texas Rio Grande Valley  
**Semester:** Fall 2025  
**Lab Session:** Lab 08 - Oscilloscope & Function Generator

## 📖 References & Resources

### Equipment Manuals
- Tektronix TDS2000 Series Oscilloscope User Manual
- B&K Precision Function Generator Operating Instructions
- Oscilloscope Probe Handbook (Tektronix)

### Additional Reading
- **"The XYZs of Oscilloscopes"** - Tektronix Primer Series
- **"ABC's of Probes"** - Tektronix Application Note
- **Circuit Analysis textbook** - Chapter on AC measurements

### Online Resources
- Oscilloscope Tutorial: learn.sparkfun.com/tutorials/how-to-use-an-oscilloscope
- Function Generator Basics: electronics-tutorials.ws
- Waveform Mathematics: mathworld.wolfram.com

## 🔬 Future Laboratory Work

**Next experiments will build on these skills:**
- **AC Circuit Analysis** - Using scope to measure impedance and phase
- **Resonance Circuits** - Observing frequency response with Bode plots
- **Filter Design** - Characterizing low-pass/high-pass/band-pass filters

---

<div align="center">

**Essential Test Equipment Proficiency**

*Foundation for all AC circuit analysis and time-domain measurements*

</div>

---

**Lab Status:** ✅ Complete  
**Date Completed:** Fall 2025  
**Data Verification:** All measurements consistent and validated