
using System.Text;

namespace SampleCommand
{
    public class RemoteControl
    {
        private Dictionary<int, Commands.ICommand> _commands;

        public RemoteControl()
        {
            _commands = new Dictionary<int, Commands.ICommand>();
        }

        public void SetCommandToButton(int buttonId, Commands.ICommand command)
        {
            _commands[buttonId] = command;
        }

        public void PushButton(int id)
        {
            if (_commands.ContainsKey(id))
            {
                _commands[id].Execute();
            }
        }

        public override string? ToString()
        {
            var sb = new StringBuilder();
            foreach (var id in _commands.Keys)
            {
                sb.AppendFormat("{0}\t-{1}\n", id, _commands[id]);
            }
            sb.Append("проч. \t - Выход");
            return sb.ToString();
        }
    }
}
