# Smart-Medical-Compliance

**Smart Medical Compliance System for Elderly-**

An IoT-enabled smart medicine compliance designed to assist elderly individuals in adhering to their prescribed medication schedules (morning/evening) and notify caregivers in case of missed doses.

**OBJECTIVES**-

●	To demonstrate the use of embedded systems in real-life healthcare applications.

●	To design and develop a Smart Medicine Reminder and Detection System using ESP32.

●	To ensure timely intake of medicines using accurate time tracking with RTC module and IR sensors

●	To provide audio reminders and SMS alerts using DFPlayer Mini , speaker and GSM Module

**SYSTEM OVERVIEW**-

The proposed system is a Smart Medicine Reminder and Monitoring System designed to ensure that medicines are taken on time and in the correct manner. The system is built around the ESP32 microcontroller, which acts as the main control unit and manages all operations based on programmed logic.
The system uses a Real Time Clock (RTC) module to keep accurate track of time. Based on this, the day is divided into two main time slots: morning (9:00 AM to 11:00 AM) and night (7:00 PM to 9:00 PM). Each time slot consists of two medicine compartments, making a total of four compartments.
To monitor medicine intake, IR sensors are placed in each compartment. These sensors detect when a compartment is accessed, allowing the system to determine whether the medicine has been taken. When the scheduled time begins, the system provides voice alerts using a DFPlayer Mini module and speaker, guiding the user to take their medicine.
The system is designed to handle different conditions. If the medicine is taken within the time slot, a confirmation message is played. If the medicine is not taken before the end of the time slot, a missed dose alert is generated. In case the same compartment is accessed more than once, the system identifies it as a repeated dose and gives a warning.
Additionally, the system includes a GSM module to send SMS notifications to caregivers, ensuring remote monitoring. Overall, the system provides a simple, reliable, and effective solution for medication management

**Components Required**

**ESP32 Microcontroller**

**RTC Module (DS1307)**Real-time clock for scheduling

**IR Sensors (x4) **Detecting pill removal from compartments

**GSM Module (SIM900A)**SMS notifications to caregivers

****DFPlayer Mini + Speaker **** Audio reminder 

**LM305 Voltage Regulator** For regulating stable supply to DFMini player

**Amplifier** To amplify speaker signals

**Resistor **To control current flow




**COMPONENTS DESCRIPTION**-

The Smart Medicine Reminder and Monitoring System is designed by integrating multiple hardware components, where each component performs a specific function to ensure accurate operation, real-time monitoring, and user interaction. The proper interfacing and coordination between these components is essential for the overall performance of the system.
**1. ESP32 Microcontroller**-

The ESP32 serves as the central processing unit of the entire system, acting as the brain that coordinates all sensing, timing, and output operations. It is a highly efficient microcontroller featuring a dual-core processor, high clock speed, multiple General Purpose Input/Output (GPIO) pins, and built-in communication protocols such as UART, I2C, and SPI. These features make it suitable for handling multiple peripherals simultaneously in real-time applications.
In this project, the ESP32 is responsible for executing the embedded program logic. It continuously reads input signals from multiple IR sensors placed at medicine compartments to detect whether a medicine has been taken or not. These sensors are connected to GPIO pins configured as digital inputs (for example: GPIO 34, 35, 32, 33), where HIGH/LOW signals indicate presence or absence of the object.
The ESP32 communicates with the RTC module (DS1307) using the I2C protocol. The SDA (Serial Data Line) and SCL (Serial Clock Line) of the RTC are typically connected to GPIO 21 (SDA) and GPIO 22 (SCL) of the ESP32. The RTC provides accurate real-time data, which the ESP32 continuously reads to compare with predefined medication schedules stored in the program.
For output operations, the ESP32 interfaces with the DFPlayer Mini module using UART communication. The TX pin of ESP32 (e.g., GPIO 17) is connected to the RX pin of the DFPlayer, and the RX pin (GPIO 16) is connected to the TX of DFPlayer. This module is used to play pre-recorded voice alerts through a speaker when it is time to take medicine or when a dose is missed.
Additionally, the GSM module is also connected via UART (either same or separate serial interface depending on design). It uses TX and RX pins (for example GPIO 26 and 27) to send SMS notifications to caregivers or users in case of missed medication or system alerts.
The ESP32 continuously processes all these inputs and outputs in a loop. It compares real-time clock data with scheduled timings and checks sensor feedback. Based on logical conditions, it decides whether to trigger an audio alert, send an SMS, or confirm successful medicine intake. Its multitasking capability ensures smooth and reliable operation of the system without delays.
Thus, the ESP32 plays a critical role in integrating all modules, ensuring synchronization, and maintaining the overall functionality and intelligence of the system.

<img width="752" height="479" alt="image" src="https://github.com/user-attachments/assets/b795670c-be6a-4c10-a6e6-5a788db98c95" />

**2. RTC (Real Time Clock) Module**-


The RTC module is used to maintain accurate real-time information such as hours, minutes, and seconds. It operates independently using a backup battery, which allows it to retain time even when the main power supply is turned off.
In this system, the RTC provides continuous time data to the ESP32. The controller uses this data to divide the day into specific time intervals (morning and night slots) and activates the system accordingly. Accurate timing is critical for ensuring that alerts are generated at the correct moments.

<img width="400" height="400" alt="WhatsApp Image 2026-05-12 at 10 01 56 PM" src="https://github.com/user-attachments/assets/4a028cf8-7b03-468d-b8e1-375fce475a58" />

**3. IR Sensors**-

Infrared (IR) sensors are used for object detection within each medicine compartment. Each compartment is equipped with one IR sensor, making a total of four sensors in the system.
These sensors work by transmitting infrared radiation and detecting its reflection. When a medicine is present, the IR signal behaves differently compared to when the compartment is accessed or the medicine is removed. This change is detected and converted into a digital signal, which is sent to the ESP32.
The controller uses this input to determine whether a dose has been taken, missed, or repeated. Proper placement and calibration of sensors are important to ensure accurate detection.

<img width="944" height="631" alt="image" src="https://github.com/user-attachments/assets/3f2ab301-75e8-4c69-bc17-64440a0bdf9f" />

**4. DFPlayer Mini Module**-

The DFPlayer Mini is a compact MP3 audio module used for voice output. It interfaces with the ESP32 through serial communication. The module reads audio files stored in a micro SD card and plays them when triggered.
In this system, different audio messages are pre-recorded and stored, such as reminders, confirmations, and warning alerts. Based on system conditions, the ESP32 sends commands to the DFPlayer to play the appropriate message. This provides a user-friendly interface, especially for users who prefer audio guidance.

<img width="944" height="560" alt="image" src="https://github.com/user-attachments/assets/cfe0bc4a-742f-4c3f-9b23-fed5d8197829" />

**5. Speaker**-

The speaker acts as the output device for the audio signals generated by the DFPlayer Mini. It converts electrical audio signals into audible sound. A clear and audible output is important to ensure that the user can easily understand the alerts and instructions provided by the system.


**6. SD Card**-
The SD card is used as external storage for the DFPlayer Mini module. It contains pre-recorded voice messages in audio format. Each file is indexed so that it can be accessed and played based on specific commands from the ESP32.
The use of an SD card allows easy modification or addition of new voice messages without changing the hardware design.

<img width="814" height="477" alt="image" src="https://github.com/user-attachments/assets/8931ef96-2bb8-44d1-923b-50747a650b97" />

**7. GSM Module**-

The GSM module is used to send SMS notifications. It helps in informing family members or caregivers if a dose is missed or repeated, making the system more reliable and useful for remote monitoring.

<img width="944" height="546" alt="image" src="https://github.com/user-attachments/assets/21ba512d-1745-417d-b6ad-0144b85f7748" />

**8. Power Supply and USB Interface**-

A USB cable is used to power the ESP32 and other components. It ensures stable power supply for proper functioning of the system.

**9. Jumper Wires**-

Jumper wires are used to connect all the components together. They help in building the circuit easily without soldering.

**BLOCK DIAGRAM-**-

<img width="2231" height="1485" alt="image" src="https://github.com/user-attachments/assets/aad33a69-d3cf-4ca9-8657-8806c9926ccc" />

**WORKING PRINCIPLE**-


The Smart Medicine Reminder and Monitoring System works based on time scheduling, sensor detection, and programmed decision-making using the ESP32 microcontroller. The system operates by continuously monitoring time and checking whether the medicine has been taken within defined time slots.
The RTC module provides real-time data to the ESP32. Based on this, the system identifies active time slots: morning (9:00 AM to 11:00 AM) and night (7:00 PM to 9:00 PM). When a time slot begins, the system activates the corresponding compartments and starts monitoring.
During the active period, the system gives an audio reminder using the DFPlayer Mini and speaker. IR sensors placed inside each compartment detect whether the medicine is removed. When medicine is taken, the sensor sends a signal to the ESP32.
The ESP32 processes this input and verifies whether the action is valid based on time and previous activity. If the medicine is taken correctly, a confirmation message is played.
If no activity is detected within the time slot, the system identifies it as a missed dose and generates a warning after the time ends. If a compartment is accessed more than once, it is treated as a repeated dose, and a caution alert is given.
Additionally, the GSM module sends SMS notifications in case of missed or repeated doses, ensuring remote monitoring and improved reliability of the system.

**APPLICATIONS**

1 Home & Elderly Medication Management

This includes both home healthcare and elderly care, where patients manage medicines outside hospitals.

It helps individuals who:

●	forget to take medicines on time (especially elderly people)

●	need regular daily dosage tracking at home

●	require reminders for long-term prescriptions

Such systems often use alarms, mobile apps, or smart pill dispensers to improve adherence and reduce missed doses.

2. Hospital & Clinical Medication Monitoring

In hospitals and clinics, medication schedules must be strictly followed for multiple patients.

This application supports:

●	doctors and nurses in tracking patient medicine timing

●	reducing human error in busy hospital environments

●	maintaining accurate medication records for each patient

It improves treatment efficiency and ensures patients receive correct doses at correct times.

3. Chronic Disease Management
   
For patients with long-term conditions like diabetes, blood pressure, asthma, etc.

These systems are useful because:

●	medicines are taken continuously for months or years

●	missing doses can worsen health conditions

●	regular reminders and tracking improve health stability

Some systems also log dosage history so doctors can adjust treatment based on compliance.

4. Remote Caregiver & Family Monitoring
   
This focuses on enabling family members or caregivers to remotely ensure patients are taking medicines properly.

Key features include:

●	SMS/app alerts when medicine is taken or missed

●	remote tracking of adherence

●	better care for patients living alone or elderly people

It improves trust and safety in home-based healthcare.

6. Smart Healthcare / IoT-Based Systems

This is the advanced integration layer where medication management becomes part of smart healthcare ecosystems.

It involves:

●	IoT-enabled pill boxes and sensors

●	cloud-based patient records

●	integration with hospital systems and mobile apps

Such systems allow real-time monitoring, data analytics, and even AI-based health recommendations in advanced setups.






















