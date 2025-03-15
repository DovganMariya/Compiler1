using SampleFactory.Car;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Factory
{
    public class FacilityTurkey : Facility
    {
        protected override ICar GetCar()
        {
            return new Tiguan();
        }
    }
}
