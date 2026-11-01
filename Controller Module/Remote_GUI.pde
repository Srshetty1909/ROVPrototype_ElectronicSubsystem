import controlP5.*;
import processing.serial.*;
import grafica.*;
import java.util.Random;
String val;
String[] valarray;
long[] readings = {0, 0, 0, 0};
Serial port;
ControlP5 manbed;
int LHS = 100, RHS = 100, Heave = 1, Ballast = 1, Gripper = 0, Dropper = 0, Launch = 0;
int i,x, y, h, w, mode;
PFont font;
void setup(){
  size(1400, 500);
  noStroke();
  manbed = new ControlP5(this);
  port = new Serial(this, "COM4", 9600);
  font = createFont("times new roman bold", 25);
  h = 50;
  w = 200;
  manbed.addSlider("LHS").setPosition(75, 100).setSize(h,w).setRange(0, 200).setValue(100).setSliderMode(Slider.FLEXIBLE).setFont(font);
  manbed.addSlider("RHS").setPosition(275, 100).setSize(h,w).setRange(0, 200).setValue(100).setSliderMode(Slider.FLEXIBLE).setFont(font);
  manbed.addSlider("Heave").setPosition(475, 100).setSize(h,w).setRange(0, 2).setValue(1).setNumberOfTickMarks(3).setSliderMode(Slider.FLEXIBLE).setFont(font);
  manbed.addSlider("Ballast").setPosition(675, 100).setSize(h,w).setRange(0, 2).setValue(1).setNumberOfTickMarks(3).setSliderMode(Slider.FLEXIBLE).setFont(font);
  manbed.addSlider("Gripper").setPosition(875, 100).setSize(h,w).setRange(0, 1).setValue(0).setNumberOfTickMarks(2).setSliderMode(Slider.FLEXIBLE).setFont(font);
  manbed.addSlider("Dropper").setPosition(1075, 100).setSize(h,w).setRange(0, 1).setValue(0).setNumberOfTickMarks(2).setSliderMode(Slider.FLEXIBLE).setFont(font);
  manbed.addSlider("Launch").setPosition(1275, 100).setSize(h,w).setRange(0, 1).setValue(0).setNumberOfTickMarks(2).setSliderMode(Slider.FLEXIBLE).setFont(font);
  manbed.addButton("Send").setPosition(650, 400).setSize(100, 50).setFont(font);
}
void draw(){
  background(255, 100, 0);
  if ( port.available() > 0)
  {  // If data is available,
    val = port.readStringUntil('\n');
    if(val != null)
    {
    print(val);
  }
  
}
}

void Send()
{
  port.write(LHS);
  port.write(RHS);
  port.write(Heave);
  port.write(Ballast);
  port.write(Gripper);
  port.write(Dropper);
  port.write(Launch);
}
