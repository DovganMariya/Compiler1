using SampleFactory.Factory.Parts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Factory
{
    public class CarPartsFactoryGermani : ICarPartsFactory
    {
        public IEngine GetEngine()
        {
            return new DieselEngine();
        }

        public IWheels GetWheels()
        {
            return new CityWheels();
        }
    }
}
