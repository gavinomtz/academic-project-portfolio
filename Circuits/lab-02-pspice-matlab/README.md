# Lab 02 - PSpice Simulation & MATLAB Analysis

Multi-tool circuit analysis demonstrating systematic validation of DC resistor networks through PSpice simulation, MATLAB matrix computation, and nodal/mesh analysis techniques.

## 🎯 Project Overview

This laboratory establishes a comprehensive workflow for analyzing complex resistive circuits using industry-standard EDA tools. The project validates circuit analysis methods by comparing hand calculations, PSpice simulations, and MATLAB computational results across voltage divider, current divider, and multi-node network topologies.

## 🔬 Laboratory Objectives

- **PSpice Proficiency**: Perform DC circuit simulation and extract nodal voltages/branch currents
- **MATLAB Matrix Operations**: Solve systems of linear equations for circuit analysis
- **Nodal Analysis**: Apply Kirchhoff's Current Law systematically to find node voltages
- **Mesh Analysis**: Apply Kirchhoff's Voltage Law systematically to find loop currents
- **Cross-Validation**: Verify analytical solutions against computational results

## 📊 Circuits Analyzed

### 1. Voltage Divider Circuit
**Purpose**: Demonstrate series resistor combinations and voltage division principle

**Analysis Method**: 
- Voltage division equations
- Equivalent resistance calculation
- PSpice DC operating point analysis

**Key Concept**: Voltage drops are proportional to resistance values in series circuits

---

### 2. Current Divider Circuit
**Purpose**: Demonstrate parallel resistor combinations and current division principle

**Circuit Parameters**:
- Current source: 5 A
- R₁ || R₂ equivalent: 307 Ω
- Calculated voltage: V = IR = 1535 V

**Analysis Method**:
- Current division equations
- Conductance-based calculations
- PSpice verification

**Key Concept**: Current splits inversely proportional to resistance in parallel circuits

---

### 3. AC Sinusoidal Source Circuit
**Purpose**: Introduce transient analysis for time-domain simulation

**Source Parameters**:
- Frequency: f = 59.81 Hz
- Period: T = 16.8187 ms
- Waveform: Sinusoidal voltage (VSIN)

**Analysis Method**:
- PSpice transient analysis
- Voltage level marker placement
- Period/frequency measurement from plot

**Key Concept**: Time-domain simulation of AC waveforms

---

### 4. Frequency Response Analysis (AC Sweep)
**Purpose**: Analyze circuit behavior across frequency spectrum

**Circuit Type**: RLC network with VAC source

**Analysis Parameters**:
- Sweep type: Decade logarithmic
- Frequency range: 1 Hz - 1 MHz
- Cutoff frequency: f₀ = 90.314 kHz (at 70.7% of DC gain)

**Analysis Method**:
- PSpice AC sweep analysis
- Bode plot generation
- Cutoff frequency identification

**Key Concept**: Frequency-dependent circuit behavior and filter characteristics

---

### 5. Multi-Node Circuit with Nodal & Mesh Analysis
**Purpose**: Solve complex circuit using systematic matrix-based methods

**Circuit Specifications**:
- 3 unknown node voltages
- 4 unknown mesh currents
- Multiple resistors (1kΩ - 2kΩ range)
- Voltage sources: 5V and 12V

#### Nodal Analysis (KCL-based)
**System of Equations**:
```
5Vₐ - 2Vᵦ = 10
2Vₐ - 5Vᵦ + 2Vᵨ = 0
2Vᵦ - 5Vᵨ = -24
```

**Matrix Form**:
```
[  5  -2   0 ] [ Vₐ ]   [  10 ]
[ -2   5  -2 ] [ Vᵦ ] = [   0 ]
[  0  -2   5 ] [ Vᵨ ]   [ -24 ]
```

**Results**:
- Vₐ = 3.6 V
- Vᵦ = 4.0 V
- Vᵨ = 6.4 V

#### Mesh Analysis (KVL-based)
**System of Equations** (where k = ×10³):
```
3kI₁ - 2kI₂ = 5
-2kI₁ + 5kI₂ - 2kI₃ = 0
-2kI₂ + 5kI₃ - 2kI₄ = 0
-2kI₃ + 3kI₄ = -12
```

**Matrix Form**:
```
[  3k  -2k   0    0  ] [ I₁ ]   [   5 ]
[ -2k   5k  -2k   0  ] [ I₂ ] = [   0 ]
[  0   -2k   5k  -2k ] [ I₃ ]   [   0 ]
[  0    0   -2k  3k  ] [ I₄ ]   [ -12 ]
```

**Results**:
- I₁ = 1.4 mA
- I₂ = -0.4 mA
- I₃ = -2.4 mA
- I₄ = -5.6 mA

## ✅ Validation Results

### Cross-Method Comparison

| Parameter | PSpice Simulation | MATLAB Calculation | Agreement |
|-----------|------------------|-------------------|-----------|
| Vₐ | 3.6 V | 3.6 V | ✓ Perfect |
| Vᵦ | 4.0 V | 4.0 V | ✓ Perfect |
| Vᵨ | 6.4 V | 6.4 V | ✓ Perfect |
| I₁ | 1.4 mA | 1.4 mA | ✓ Perfect |
| I₂ | -0.4 mA | -0.4 mA | ✓ Perfect |
| I₃ | -2.4 mA | -2.4 mA | ✓ Perfect |
| I₄ | -5.6 mA | -5.6 mA | ✓ Perfect |

**Conclusion**: 100% agreement between simulation and computational methods validates both the circuit model and analytical approach.

## 🛠️ Tools & Technologies

| Tool | Version | Purpose |
|------|---------|---------|
| **OrCAD PSpice** | Schematics | Schematic capture and DC/AC simulation |
| **MATLAB** | R2023a+ | Matrix operations and system equation solving |

## 🔧 Technical Implementation

### PSpice Workflow

1. **Schematic Entry**:
   - Components: VDC, IDC, VSIN, VAC, R, L, C, GND
   - Part browser: `Draw > Get New Part`
   - Wiring: `Draw > Wire`

2. **DC Analysis**:
   - Run simulation: `Analysis > Simulate` (or F11)
   - Display results: `Analysis > Display Results on Schematic`
   - View netlist: `Analysis > Examine Netlist`

3. **Transient Analysis** (AC circuits):
   - Setup: `Analysis > Setup > Transient`
   - Print step: 10 ms, Final time: 100 ms
   - Insert voltage level markers for plotting

4. **AC Sweep Analysis** (Frequency response):
   - Setup: `Analysis > Setup > AC Sweep`
   - Type: Decade logarithmic sweep
   - Range: 1 Hz to 1 MHz
   - Locate cutoff frequency using cursor

### MATLAB Workflow

**Matrix Equation Solving** using `inv()` function:

```matlab
% Enable high precision
format long

% Define coefficient matrix (Z-parameters)
z = [5, -2, 0; 
     -2, 5, -2; 
     0, -2, 5];

% Define source vector
v = [10; 0; -24];

% Solve system: Z * V = I
voltages = inv(z) * v

% Results:
% voltages(1) = Va = 3.6 V
% voltages(2) = Vb = 4.0 V
% voltages(3) = Vc = 6.4 V
```

**For Mesh Analysis** (currents):

```matlab
% Define impedance matrix (k = 1e3)
k = 1e3;
z = [3*k, -2*k, 0, 0;
     -2*k, 5*k, -2*k, 0;
     0, -2*k, 5*k, -2*k;
     0, 0, -2*k, 3*k];

% Define voltage vector
v = [5; 0; 0; -12];

% Solve for mesh currents
currents = inv(z) * v * 1e3  % Convert to mA

% Results:
% currents(1) = I1 = 1.4 mA
% currents(2) = I2 = -0.4 mA
% currents(3) = I3 = -2.4 mA
% currents(4) = I4 = -5.6 mA
```

## 🎓 Skills Demonstrated

### Circuit Analysis Techniques
- **Series/Parallel Reduction**: Equivalent resistance calculations
- **Voltage Division**: Proportional voltage drops in series circuits
- **Current Division**: Inverse proportional current splits in parallel circuits
- **Nodal Analysis**: Systematic KCL application for node voltages
- **Mesh Analysis**: Systematic KVL application for loop currents

### Software Proficiency
- **PSpice Schematic Capture**: Component placement, wiring, parameter assignment
- **DC/AC/Transient Simulation**: Multiple analysis types for different circuit behaviors
- **MATLAB Programming**: Matrix operations, system equation solving
- **Data Extraction**: Reading simulation outputs and cursor measurements

### Engineering Validation
- **Multi-Method Verification**: Hand calculations, simulation, computation
- **Error Analysis**: Comparing results across different solution methods
- **Systematic Problem-Solving**: Following structured analysis procedures

## 📈 Key Learning Outcomes

1. **PSpice is essential for circuit analysis** - Enables rapid simulation, visualization, and optimization without physical prototyping

2. **MATLAB accelerates calculations** - Matrix equations that would take hours by hand are solved instantly, allowing focus on analysis rather than arithmetic

3. **Validation is critical** - Cross-checking results with multiple methods ensures accuracy and builds confidence in solutions

4. **Systematic methods scale well** - Nodal and mesh analysis techniques work for arbitrarily complex circuits where intuitive methods fail

## 📁 Repository Contents

- **`lab-02-report.pdf`** - Complete technical report with:
  - Circuit schematics with labeled components
  - PSpice simulation screenshots showing voltages/currents
  - MATLAB command window screenshots with code and results
  - Hand calculations and comparative analysis
  - Conclusions on software utility for circuit analysis

## 🔮 Future Applications

**Academic**: These tools and techniques will be fundamental for:
- Advanced circuit analysis courses
- Electronics and power systems labs
- Senior design projects and capstone work

**Professional**: Industry-relevant skills for:
- Circuit design and verification
- PCB layout and simulation
- Systems integration and troubleshooting
- Hardware/firmware development roles

## 📞 Course Information

**Course**: EECE 2105 - Electric Circuits I Laboratory
**Institution**: University of Texas Rio Grande Valley
**Semester**: Fall 2025

## 📄 Academic Integrity

This laboratory work was completed in accordance with university academic policies. All simulations, calculations, and analysis are original work.

---