using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SharpDX_Tutorial
{
    using SharpDX;
    using SharpDX.Direct3D12;
    using SharpDX.DXGI;
    using SharpDX.WIC;
    using SharpDX.Windows;

    internal sealed class CoolGame : Game
    {
        private readonly GraphicsDeviceManager _graphicsDeviceManger;


    }

}


namespace SharpDX_Tutorial
{ 

    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
