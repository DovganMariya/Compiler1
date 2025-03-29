using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleCommand.Devices
{
    public class YandexMusic
    {
        public DeviceStates State { get; set; }
        public void PlayAndPause()
        {
            if (State == DeviceStates.OFF)
            {
                State = DeviceStates.ON;
            } else
            {
                State = DeviceStates.OFF;
            }
            Console.WriteLine("Яндекс.Музыка {0}",
                State == DeviceStates.OFF ? "пауза" : "играет");
        }
        public void SecondTrack()
        {
            Console.WriteLine("Яндекс.Музыка следующий трек");
            if (State == DeviceStates.OFF)
            {
                State = DeviceStates.ON;
                Console.WriteLine("Яндекс.Музыка играет");
            }
        }
    }
}
