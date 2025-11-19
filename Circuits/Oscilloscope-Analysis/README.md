# Lab 08 - Oscilloscope & Function Generator

Introduction to essential test equipment for AC circuit analysis: digital oscilloscope operation and function generator control. Demonstrates time-domain waveform visualization, frequency measurement, and proper use of laboratory instrumentation.

## Laboratory Objectives

- **Oscilloscope Proficiency** - Identify and adjust vertical, horizontal, and trigger controls
- **Calibration Verification** - Observe and validate internal calibration waveforms
- **Function Generator Operation** - Configure waveform type, frequency, and amplitude
- **Waveform Analysis** - Measure peak-to-peak voltage, frequency, and period from displayed signals
- **Multi-Waveform Testing** - Generate and observe sine, triangle, and square waves across frequency ranges

## Equipment & Instrumentation

| Equipment | Model/Specifications | Purpose |
|-----------|---------------------|---------|
| Digital Oscilloscope | Dual-trace (2-channel) | Time-domain signal visualization |
| Function Generator | 1 Hz - 10 MHz range | Arbitrary waveform generation |
| BNC Cables | 50Ω coaxial | Signal transmission |
| Oscilloscope Probes | 10:1 attenuation (typical) | Signal acquisition |

## Experimental Procedures

### Part 1: Oscilloscope Calibration & Control

**Objective:** Familiarize with oscilloscope operation using internal calibration signal

**Measurements:**

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

**Measurements:**

| Frequency | Volts/Div | Time/Div | Cycles Displayed | Waveform |
|-----------|-----------|----------|------------------|----------|
| 1 kHz | 2 V/Div | 400 μs/Div | ~2.5 cycles | Sine wave |
| 2 kHz | 2 V/Div | 100 μs/Div | ~2 cycles | Sine wave |

**Observations:**
- Doubling frequency from 1 kHz → 2 kHz doubles visible cycles (at constant time/div)
- Peak-to-peak voltage remains constant (~6 divisions = 12V pp)

#### Experiment 2.2: Triangle Wave Analysis

**Measurements:**

| Frequency | Volts/Div | Time/Div | Cycles Displayed | Waveform |
|-----------|-----------|----------|------------------|----------|
| 1 kHz | 2 V/Div | 100 μs/Div | 1 cycle | Triangle wave |
| 2 kHz | 2 V/Div | 100 μs/Div | 2 cycles | Triangle wave |

**Observations:**
- Triangle wave exhibits linear voltage transitions (constant slope)
- Same frequency-cycle relationship observed as sine wave

#### Experiment 2.3: Square Wave Characterization

**Measurements:**

| Frequency | Volts/Div | Time/Div | Cycles Displayed | Waveform |
|-----------|-----------|----------|------------------|----------|
| 1 kHz | 2 V/Div | 100 μs/Div | 1 cycle | Square wave |
| 2 kHz | 2 V/Div | 100 μs/Div | 2 cycles | Square wave |

**Observations:**
- Square wave shows instantaneous voltage transitions (ideal switching)
- Rise/fall time limited by oscilloscope bandwidth and probe characteristics

## Learning Outcomes

- Operate digital oscilloscope controls (vertical, horizontal, trigger systems)  
- Interpret graticule measurements for voltage and time  
- Configure function generator for various waveforms and frequencies  
- Recognize relationship between display settings and waveform appearance  
- Distinguish sine, triangle, and square waveforms by visual inspection  
- Calculate frequency from period measurements  
- Understand that scope settings affect display, not signal characteristics  
- Document waveform observations with proper technical notation  

## Course Information

**Course:** EECE 2105 - Electric Circuits I Laboratory  
**Student:** Gavino Martinez (ID: 20678524)  
**Institution:** University of Texas Rio Grande Valley  
**Semester:** Fall 2025  
**Lab Session:** Lab 08 - Oscilloscope & Function Generator

---

<div align="center">

**Essential Test Equipment Proficiency**

*Foundation for all AC circuit analysis and time-domain measurements*

</div>

---

**Date Completed:** Fall 2025  
**Data Verification:** All measurements consistent and validated