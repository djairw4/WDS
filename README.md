# Visualization of parking sensors

<table>
<tr>
<td>
 I created a QT desktop application that visualizes data read from ultrasonic sensors.  These sensors are supposed to simulate the performance of real car parking sensors.
</td>
</tr>
</table>

[Project report (in Polish)](https://github.com/djairw4/WDS/blob/main/wds_sprawozdanie.pdf)

[Documentation (in Polish)](http://panamint.ict.pwr.wroc.pl/~djarzabe/Doxygen/html/annotated.html)

## General information

* 4 ultrasonic sensors connected to the STM32F411E DISCO board
* the app communicates with the board via UART
* displaying the current distances of obstacles from the sensors
* the chart shows how the distance has changed over time

## System presentation

Here is a video that shows how the system works: https://www.youtube.com/watch?v=qMRQl52bFTw

<p align="center">
  <img src="https://github.com/djairw4/WDS/blob/main/WDS_RPK.png" />
</p>

<p align="center">
  <img src="https://github.com/djairw4/WDS/blob/main/schemat.png" width=600/>
</p>
