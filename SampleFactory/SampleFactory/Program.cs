// See https://aka.ms/new-console-template for more information
using SampleFactory.Factory;

Console.WriteLine("Hello, World!");

var factoryRus = new FacilityRussia();
var carRus = factoryRus.BuildCar();

var factoryTurk = new FacilityTurkey();
var carRus =factoryRus.BuildCar();
Console.WriteLine();
var factoryTurk = new FacilityTurkey();
var carTurl = factoryTurk.BuildCar();