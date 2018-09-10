using System;
using System.Collections.Generic;
using System.Text;

namespace OOP_Opdracht_week_1
{
    class User
    {
        private User next;
        string name;
        int access;

        public User(string name, int access = 0)
        {
            name = this.name;
            access = this.access;
        }

        public string GetName()
        {
            return name;
        }

        public int GetAccess()
        {
            return access;
        }

        public int Check_Access()
        {
            return 5;
        }
    }
}