using System;


namespace task2
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] digits = new string[9]
        {
            "Сто",
            "Двести",
            "Триста",
            "Четыреста",
            "Пятьсот",
            "Шестьсот",
            "Cемьсот",
            "Восемьсот",
            "Девятсот"
        };
            Console.WriteLine("Введите число от 100 до 999");
            string strA = Console.ReadLine();
            int numb = Int32.Parse(strA);
            string representation = numb.ToString();
            int tmp = numb / 100;
            Console.WriteLine("{0}", numb/100);
            for (int i = 0; i < 5; i++)
            {
                if(tmp == i+1)
                {
                    Console.WriteLine("{0}", digits[i]);
                }
            }
            Console.Read();
        }
    }
}
