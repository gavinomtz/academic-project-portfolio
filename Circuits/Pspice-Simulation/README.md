# Lab 02 - PSpice Simulation & MATLAB Analysis

Multi-tool circuit analysis demonstrating systematic validation of DC resistor networks through PSpice simulation, MATLAB matrix computation, and nodal/mesh analysis techniques.

## Project Overview

This laboratory establishes a comprehensive workflow for analyzing complex resistive circuits using industry-standard EDA tools. The project validates circuit analysis methods by comparing hand calculations, PSpice simulations, and MATLAB computational results across voltage divider, current divider, and multi-node network topologies.

## Laboratory Objectives

- **PSpice Proficiency**: Perform DC circuit simulation and extract nodal voltages/branch currents
- **MATLAB Matrix Operations**: Solve systems of linear equations for circuit analysis
- **Nodal Analysis**: Apply Kirchhoff's Current Law systematically to find node voltages
- **Mesh Analysis**: Apply Kirchhoff's Voltage Law systematically to find loop currents
- **Cross-Validation**: Verify analytical solutions against computational results

## Circuits Analyzed

### 1. Voltage Divider Circuit
**Purpose**: Demonstrate series resistor combinations and voltage division principle
**Key Concept**: Voltage drops are proportional to resistance values in series circuits

---

### 2. Current Divider Circuit
**Purpose**: Demonstrate parallel resistor combinations and current division principle
**Key Concept**: Current splits inversely proportional to resistance in parallel circuits

---

### 3. AC Sinusoidal Source Circuit
**Purpose**: Introduce transient analysis for time-domain simulation
**Key Concept**: Time-domain simulation of AC waveforms

---

### 4. Frequency Response Analysis (AC Sweep)
**Purpose**: Analyze circuit behavior across frequency spectrum
**Key Concept**: Frequency-dependent circuit behavior and filter characteristics

---

### 5. Multi-Node Circuit with Nodal & Mesh Analysis
**Purpose**: Solve complex circuit using systematic matrix-based methods

**Circuit Specifications**:
- 3 unknown node voltages
- 4 unknown mesh currents
- Multiple resistors (1kΩ - 2kΩ range)
- Voltage sources: 5V and 12V

## Validation Results

### Cross-Method Comparison

| Parameter | PSpice Simulation | MATLAB Calculation | Agreement |
|-----------|------------------|-------------------|-----------|
| Vₐ | 3.6 V | 3.6 V | Perfect |
| Vᵦ | 4.0 V | 4.0 V | Perfect |
| Vᵨ | 6.4 V | 6.4 V | Perfect |
| I₁ | 1.4 mA | 1.4 mA | Perfect |
| I₂ | -0.4 mA | -0.4 mA | Perfect |
| I₃ | -2.4 mA | -2.4 mA | Perfect |
| I₄ | -5.6 mA | -5.6 mA | Perfect |

**Conclusion**: 100% agreement between simulation and computational methods validates both the circuit model and analytical approach.

## Tools & Technologies

| Tool | Version | Purpose |
|------|---------|---------|
| **OrCAD PSpice** | Schematics | Schematic capture and DC/AC simulation |
| **MATLAB** | R2023a+ | Matrix operations and system equation solving |

## Key Learning Outcomes

1. **PSpice is essential for circuit analysis** - Enables rapid simulation, visualization, and optimization without physical prototyping

2. **MATLAB accelerates calculations** - Matrix equations that would take hours by hand are solved instantly, allowing focus on analysis rather than arithmetic

3. **Validation is critical** - Cross-checking results with multiple methods ensures accuracy and builds confidence in solutions

4. **Systematic methods scale well** - Nodal and mesh analysis techniques work for arbitrarily complex circuits where intuitive methods fail

## Course Information

**Course**: EECE 2105 - Electric Circuits I Laboratory
**Institution**: University of Texas Rio Grande Valley
**Semester**: Fall 2025

## Academic Integrity

This laboratory work was completed in accordance with university academic policies. All simulations, calculations, and analysis are original work.

---