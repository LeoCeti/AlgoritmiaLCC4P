using System;

class Program
{
    static void Main(string[] args)
    {
        double[,] MatrizConPeso = new double[,]
        {
            { 0, 2.0, 0, 1.2 },
            { 0.5, 0, 1.2, 0 },
            { 0, 0.9, 1.3, 0 },
            { 1.2, 0, 0, 0 }
        };

        Console.WriteLine("Matriz con pesos:");
        ImprimirMatriz(matrizConPesos);

        Console.ReadKey();
    }

    static void ImprimirMatriz(double[,] matriz)
    {
        for (int i = 0; i < matriz.GetLength(0); i++)
        {
            for (int j = 0; j < matriz.GetLength(1); j++)
            {
                Console.Write(matriz[i, j].ToString("F1") + " ");
            }
            Console.WriteLine();
        }
    }
}
