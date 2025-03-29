// See https://aka.ms/new-console-template for more information
using SampleCommand;
using SampleCommand.Commands;
using SampleCommand.Devices;

var tv = new TV();
var music = new YandexMusic();

var comMusicTurnOn = new MusicTurnOnCommand(music);
var comMusicSkip = new MusicSkipCommand(music);

var comTvTurnOn = new TVCommand(tv);

var remote = new RemoteControl();

remote.SetCommandToButton(1, comMusicTurnOn);
remote.SetCommandToButton(2, comMusicSkip);
remote.SetCommandToButton(3, comTvTurnOn);

Console.WriteLine(remote.ToString());
var input = Console.ReadLine();

while (input != null && (string)input != "")
{
    remote.PushButton(int.Parse(s:
        input));
    Console.WriteLine(remote.ToString());
    input = Console.ReadLine();
}