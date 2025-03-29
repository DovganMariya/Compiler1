using SampleCommand.Devices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleCommand.Commands
{
    public class MusicTurnOnCommand : ICommand
    {
        private YandexMusic _yanMusic;

        public MusicTurnOnCommand(YandexMusic yanMusic)
        {
            _yanMusic = yanMusic;
        }

        public void Execute()
        {
            _yanMusic.PlayAndPause();
        }

        public override string? ToString()
        {
            return "Плей/пауза музыки";
        }
    }
}
