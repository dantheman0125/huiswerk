using System;
using System.Collections.Generic;
using System.Text;

namespace OOP_Opdracht_week_1
{
    class Board
    {
        List<Posts> posts;
        private string name;

        public Board (string name)
        {
            this.name = name;
        }

        public string GetName()
        {
            return name;
        }
    }
}
