﻿using SampleFactory.Factory.Parts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Factory
{
    public class CarPartsFactoryChina : ICarPartsFactory
    {
        public IEngine GetEngine()
        {
            return new GasolineEngine();
        }

        public IWheels GetWheels()
        {
            return new HighwayWheels();
        }
    }
}
