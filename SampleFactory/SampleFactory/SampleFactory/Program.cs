
using SampleFactory.Factory;

var factoryRus = new FacilityRussia();
var carRus = factoryRus.BuildCar(); 
Console.WriteLine();
var factoryTurk = new FacilityTurkey();
var carTurk = factoryTurk.BuildCar();

