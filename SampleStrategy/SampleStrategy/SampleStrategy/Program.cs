// See https://aka.ms/new-console-template for more information
using SampleStrategy.Duck;
using SampleStrategy.Fly;

Console.WriteLine("Hello, World!");
DuckBase duck = new SimpleDuck();
duck.Dispay();
duck.DoSomething();
duck = new DisabledDuck();
duck.Dispay();
duck.DoSomething();
duck.SetFlyStrat(new SimpleFly());
duck.Dispay();
duck.DoSomething();