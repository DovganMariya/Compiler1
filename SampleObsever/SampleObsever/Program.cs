// See https://aka.ms/new-console-template for more information
using SampleObsever.Publisher;
using SampleObsever.Subscriber;

Console.WriteLine("Hello, World!");
ISubscriber subscriberT = new WidgetTelegram();
ISubscriber subscriberV = new WidgetVk();
ISubscriber subscriberI = new WidgetIcq();

IPublisher publisher = new NewsAgregator();

publisher.subscribe(subscriberT);
publisher.subscribe(subscriberV);   
publisher.subscribe(subscriberI);
publisher.notify();
Console.WriteLine("----------------");
publisher.unsubscribe(subscriberV);
publisher.notify();
Console.WriteLine("----------------");