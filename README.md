# Light-Activated-Switch-using-PIC18F4550
This project automates the control of an electrical appliance, such as a light bulb, based on ambient light intensity using the **PIC18F4550 microcontroller**. It is designed to conserve energy and enhance convenience by turning the light ON during low-light conditions and OFF when sufficient light is detected.

## Features

- **Light-Responsive Automation**: Uses a Light Dependent Resistor (LDR) to detect ambient light levels and operate the appliance accordingly.
- **Energy Efficiency**: Automatically switches the light OFF during daylight, reducing energy wastage.
- **Real-Time Control**: Ensures rapid response (1ms average) to changes in ambient light.
- **Cost-Effective**: Built using easily available, affordable components.

## Components Used

- **Microcontroller**: PIC18F4550
- **Sensor**: Light Dependent Resistor (LDR)
- **Transistor**: BC547 for signal amplification
- **Relay**: SPDT for appliance control
- **Power Supply**: 5V DC

## Working Principle

1. **Light Detection**: The LDR senses the ambient light intensity and outputs a variable resistance.
2. **Analog-to-Digital Conversion**: The PIC18F4550 converts the LDR's analog signal to a digital value using its built-in ADC.
3. **Threshold Comparison**: The ADC value is compared with a predefined threshold (e.g., 48).
4. **Relay Control**: 
   - If the light intensity is below the threshold (low light), the microcontroller activates the relay to turn ON the light.
   - If the light intensity exceeds the threshold (bright light), the relay turns OFF the light.

## Circuit Design

The system consists of:
- An LDR connected to the ADC input of the PIC18F4550.
- A BC547 transistor to drive the relay.
- A SPDT relay to switch the connected appliance.
- Power supply circuits for the microcontroller and relay.

## Software Details

- **Programming Tools**: MPLAB X IDE, XC8 Compiler
- **Libraries Used**:
  - ADC module of PIC18F4550
  - Relay control logic
  - Signal processing algorithms
- **System Flow**:
  1. Read ADC value from the LDR.
  2. Compare it with the threshold.
  3. Control the relay based on the comparison.

## Applications

- **Residential Lighting**: Automates room lights based on natural light levels.
- **Street Lighting**: Ensures streetlights turn ON at dusk and OFF at dawn.
- **Industrial Automation**: Efficient control of lighting in factories and warehouses.

## Results

- Successfully automates light control based on ambient light intensity.
- Achieves consistent and rapid response with a 1ms average delay.
- Reduces energy consumption by eliminating unnecessary light usage.

## Limitations

- Sensitivity to sudden light changes (e.g., passing vehicles) may cause false triggers.
- Requires calibration for different environments and lighting conditions.

## Future Enhancements

- **Advanced Sensors**: Integrate digital light sensors for higher accuracy.
- **IoT Connectivity**: Enable remote monitoring and control using IoT platforms.
- **Enhanced Durability**: Use solid-state relays to improve system lifespan.
