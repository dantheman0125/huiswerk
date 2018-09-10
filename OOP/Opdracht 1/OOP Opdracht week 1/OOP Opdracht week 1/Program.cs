using System;

namespace OOP_Opdracht_week_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Setup();
            Console.WriteLine("         Welcome to the NHLStenden");
            Line();
            Choice1();
        }

        static void Setup()
        {
            User Bert = new User("Bert de Vries");
            User Ernie = new User("Ernie Bij");
            User Daniel = new User("Daniel Roskam", 1);
            User Bertha = new User("Bertha Eend");
            User Wouter = new User("Wouter Brinksma", 1);
            User Lisa = new User("Lisa Vis");
            User Ghost = new User("Spooky Scary");




        }

        static void Line()
        {
            Console.WriteLine("======================================================");
        }

        static void InvalInNum()
        {
            Line();
            Console.WriteLine("Please pick a number that corresponds with the thing you want to do.");
            Console.WriteLine("Press enter to continue");
            Console.ReadLine();
            Console.Clear();
            Line();

        }

        static void Choice1()
        {
            Console.WriteLine("What would you like to do?");
            Line();
            Console.WriteLine("1. Post");
            Console.WriteLine("2. Search");
            Console.WriteLine("3. Create a board");

            string choice1str=Console.ReadLine();
            int choice1num;
            if (int.TryParse(choice1str, out choice1num))
                switch (choice1num)
                {
                    case 1:
                        Line();
                        Post();
                        break;
                    case 2:
                        Line();
                        Search();
                        break;
                    case 3:
                        Line();
                        Create();
                        break;
                    default:
                        InvalInNum();
                        Choice1();
                        break;
                }
            else
            {
                InvalInNum();
                Choice1();
            }
        }

        static void Post()
        {

        }

        static void Search()
        {

        }

        static void Create()
        {

        }
    }
}