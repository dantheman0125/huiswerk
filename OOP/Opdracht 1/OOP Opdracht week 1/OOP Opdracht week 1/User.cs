using System;
using System.Collections.Generic;
using System.Text;

namespace OOP_Opdracht_week_1
{
    class User
    {
        
        protected string name;

        public User(string name)
        {
            name = this.name;
        }

        public string GetName()
        {
            return name;
        }
    }

    class Admin : User
    {
        public Admin(string name) : base(name)
        {
            name = this.name;
        }

        public void MakeBoard(Board board)
        {
            Program.AddBoard();
        }

    }
}