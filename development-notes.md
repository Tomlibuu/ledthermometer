**Development notes**

**Motivation of the project**
In the fall of 2022, I participated in a course where my partner and I created something new from used electronics. The final product was a frisbee based on the intelligence of the smart watch's circuit board. The main purpose of this circuit board was to help the player find the disc he or she threw, if he or she has not found it himself or herself within a certain time. We used the sensors found on the circuit board to examine the execution of the throwing event, which enabled us to determine when the disc should start counting down the time to indicate its position. So we combined the data of more than one sensor, and thus we got the necessary information for the actual throw to occur. Additional documentation can be viewed in the frisbeegolf-finder repository found on my Github. With this course, I became even more interested in embedded systems. The output found in this repository was created as an interest in embedded systems.

**Technical issues**
The purpose was to create a thermometer, the data it collects is used to indicate the colors of the led strip. I myself am a computer science student, so I don't have a lot of experience in electronics, so the purpose was to try out what I can do in this interesting project. I chose the Arduino UNO R3 board as the development platform. In addition, other parts that I needed for a successful product were: DS18B20 thermal sensor, 1602 LCD display with I2C module, SMD5050 rgb led strip, 4.8kΩ resistor, three pieces of IRF540 N mosfets, jumper wires and breadboard. I used the DC port of the Arduino board to power my output. The led strip came with a power source that can be powered from the mains. This part was perfectly compatible with the Arduino board, because the maximum voltage that this transformer provides is 12V.

This diagram shows the connections between the various components. In the diagram, the power source is eight 1.5 volt batteries connected in series, but in the right situation, power to the circuit board is already obtained from the mains via the previously mentioned transformer. Also, the LED strip is presented as a single LED and the thermal sensor as a small component instead of at the end of the cord. These gaps in the diagram are due to the fact that the program I used to model the connections did not include the correct components.

![image](https://user-images.githubusercontent.com/94450686/213263069-1ba32cb0-a41f-461d-be96-a1545966d59e.png)
DS18B20

![IMG_20230118_211741__01](https://user-images.githubusercontent.com/94450686/213275142-f2dfb8a3-4e54-45ba-b4bd-65ec75b4abf7.jpg)
![IMG_20230118_211807__01](https://user-images.githubusercontent.com/94450686/213275088-d1309394-cc43-42f9-bfa3-cd8f107d6043.jpg)
1602 LCD display with I2C module

![IMG_20230118_211835__01](https://user-images.githubusercontent.com/94450686/213274975-7e42f651-da85-4964-826d-8588e5b846b6.jpg)
SMD5050 rgb led strip

![IMG_20230111_003950](https://user-images.githubusercontent.com/94450686/213276022-253357d5-3d6b-4881-94cd-bd824ef1126b.jpg)
Image of device wiring

**Purpose**
The purpose of this device is to measure the outside temperature and, with this information, set a certain color on the led strip to describe the value of the outside temperature. Color coding for different temperatures is almost a standard color coding used by, for example, meteorologists. More detailed color-temperature pairs can be found in the thermometer.ino file. Some of the colors have been used to depict a larger temperature range than others, because the colors started to run out and it would be too difficult to detect exact tonal differences from the led strip. The device also has an attached LCD screen for the reason that the user can check the exact outside temperature from it. One color always describes a gap of five or ten degrees.

**Workflow**
