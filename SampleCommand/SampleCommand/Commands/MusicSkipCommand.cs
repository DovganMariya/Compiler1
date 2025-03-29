using SampleCommand.Devices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleCommand.Commands
{
    public class MusicSkipCommand : ICommand
    {
        private YandexMusic _yanMusic;

        public MusicSkipCommand(YandexMusic yanMusic)
        {
            _yanMusic = yanMusic;
        }

        public void Execute()
        {
            _yanMusic.SecondTrack();
        }

        public override string? ToString()
        {
            return "Музыка следующий трек";
        }
    }
}
