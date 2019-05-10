using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[Serializable]

/* A serializable class to create a device*/

public class Device 
{
    //switch to set the device status           
    private string Switch = "off";
    private string deviceName;

    public Device(string deviceName){
        this.deviceName=deviceName;
    }

    public void setSwitchON()
    {
        this.Switch = "ON";
    }

    public void setSwitchOFF()
    {
        this.Switch = "OFF";
    }

    public string getSwitch()
    {
        return this.Switch;
    }

    public string getName()
    {
        return this.deviceName;
    }
}
