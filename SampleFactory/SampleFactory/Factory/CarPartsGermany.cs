using SampleFactory.Parts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Factory 
{
    public class CarPartsGermany : ICarPartsFactory
    {
        public IEngine GetEngine()
        {
            return new DieselEngine();
        }
        public IEngine GetEngine()
        {
            return new CityWheels();
        }

    }
}
