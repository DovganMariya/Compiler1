using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Parts
{
    public class HighwayWheels : IWheels
    {
        public HighwayWheels()
        {
            Console.WriteLine("Установка колес радиуса 17");
        }

    }
}
