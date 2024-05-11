using System;

public class Graph
{
    private int[,] edges;
    private int[,] copiedEdges;

    public Graph(int n)
    {
        this.edges = new int[n, n];
        this.copiedEdges = new int[n, n];
    }

    public int[,] GetCopiedEdges()
    {
        return copiedEdges;
    }

    public void SetCopiedEdges(int[,] copiedEdges)
    {
        this.copiedEdges = copiedEdges;
    }

    public void WeightedNonDirected()
    {
        for (int i = 0; i < edges.GetLength(0); i++)
        {
            for (int j = i; j < edges.GetLength(1); j++)
            {
                Console.Write("Is there a connection between " + (i + 1) + " and " + (j + 1) + " ? ");
                string connection = Console.ReadLine();
                try
                {
                    edges[i, j] = edges[j, i] = int.Parse(connection);
                    copiedEdges[i, j] = copiedEdges[j, i] = int.Parse(connection);
                }
                catch (FormatException)
                {
                    // Do nothing or simply skip the error
                }
            }
        }
        Console.WriteLine();
    }

    public override string ToString()
    {
        string s = "";
        for (int i = 0; i < edges.GetLength(0); i++)
        {
            for (int j = 0; j < edges.GetLength(1); j++)
            {
                s += edges[i, j] + "\t";
            }
            s += "\n";
        }
        return s;
    }

    public void Refill()
    {
        for (int i = 0; i < edges.GetLength(0); i++)
        {
            for (int j = i; j < edges.GetLength(1); j++)
            {
                copiedEdges[i, j] = copiedEdges[j, i] = edges[i, j];
            }
        }
    }

    public Dijkstra Dijkstra(int vertex, int end, int bring, string supply, Dijkstra a)
    {
        if (copiedEdges[vertex, end] != 0 && a.GetAmount() > copiedEdges[vertex, end] + bring)
        {
            a.SetAmount(copiedEdges[vertex, end] + bring);
            copiedEdges[vertex, end] = copiedEdges[end, vertex] = 0;
            a.SetPath(supply);
        }

        for (int i = 0; i < copiedEdges.GetLength(0); i++)
        {
            if (copiedEdges[vertex, i] != 0 && a.GetAmount() > (copiedEdges[vertex, i] + bring))
            {
                int tempo = copiedEdges[vertex, i] + bring;
                copiedEdges[vertex, i] = copiedEdges[i, vertex] = 0;
                string supply2 = supply + " " + i + " ";
                a = Dijkstra(i, end, tempo, supply2, a);
            }
        }
        Refill();
        return a;
    }
}

public class Dijkstra
{
    private int amount;
    private string path;
    private int start;
    private int end;

    public Dijkstra(int n, string re, int ini, int fin)
    {
        this.amount = n;
        this.path = re;
        this.start = ini;
        this.end = fin;
    }

    public override string ToString()
    {
        return "Minimum: " + this.amount + " Path: " + this.start + " " + this.path + "" + this.end;
    }

    public int GetAmount()
    {
        return amount;
    }

    public void SetAmount(int amount)
    {
        this.amount = amount;
    }

    public string GetPath()
    {
        return path;
    }

    public void SetPath(string path)
    {
        this.path = path;
    }
}

public class Testing
{
    public static void Main(string[] args)
    {
        Console.Write("Enter the number of vertices: ");
        int number = int.Parse(Console.ReadLine());

        Graph weightedNonDirected = new Graph(number);
        weightedNonDirected.WeightedNonDirected();
        Console.WriteLine(weightedNonDirected);

        Console.WriteLine();

        Console.Write("Enter the starting vertex: ");
        int vertex = int.Parse(Console.ReadLine());
        Console.Write("Enter the ending vertex: ");
        int end = int.Parse(Console.ReadLine());

        Dijkstra dij = new Dijkstra(999, "", vertex, end);
        Console.WriteLine(weightedNonDirected.Dijkstra(vertex, end, 0, "", dij));
    }
}
