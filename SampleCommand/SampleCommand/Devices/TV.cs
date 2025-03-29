using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleCommand.Devices
{
    public class TV
    {
        public DeviceStates State { get; set; }
        public void TurnOn()
        {
            if (State == DeviceStates.OFF)
            {
                State = DeviceStates.ON;
            }
            else
            {
                State = DeviceStates.OFF;
            }
            Console.WriteLine("Телевизор {0}",
                State == DeviceStates.OFF ? "выключен" : "включен");
        }
    }
}
