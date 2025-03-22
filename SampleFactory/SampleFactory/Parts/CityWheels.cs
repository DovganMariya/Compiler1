using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Parts
{
    public class CityWheels : IWheels
    {
        public CityWheels()
        {
            Console.WriteLine("Установка колес радиуса 15");
        }

    }
}
