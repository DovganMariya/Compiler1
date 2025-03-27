using SampleFactory.Car;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Factory
{
    public class FacilityRussia : Facility
    {
        protected override Icar GetCar()
        {
            return new Tiguan(new CarPartsFactoryGermani());
        }
    }
}
