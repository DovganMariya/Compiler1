using SampleCommand.Devices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleCommand.Commands
{
    public class TVCommand : ICommand
    {
        private TV _tv;

        public TVCommand(TV tv)
        {
            _tv = tv;
        }

        public void Execute()
        {
            _tv.TurnOn();
        }

        public override string? ToString()
        { 
            return "Включение/выключение телевизора"; 
        }
    }
}
