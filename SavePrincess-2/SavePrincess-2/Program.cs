using System;
using System.Collections.Generic;
using System.IO;
class Solution
{
    enum MOVES {
        NONE,
        LEFT,
        RIGHT,
        UP,
        DOWN
    } 
    static void nextMove(int n, int r, int c, String[] grid)
    {
        // Var
        Tuple<int, int> pPoint = null;
        
        // Find princess
        for (int i = 0; i < n; ++i)
        {
            string line = grid[i];
            for (int j = 0; j < n; ++j)
            {
                if (line[j] == 'p')
                {
                    pPoint = new Tuple<int, int>(i, j);
                    break;
                }
                
            }
        }

        if (pPoint == null) return;

        // determine next move
        int deltaR = r - pPoint.Item1; // Positive: UP
        int deltaC = pPoint.Item2 - c; // Positive: RIGHT

        MOVES nextMove = MOVES.NONE;
        if (deltaR > 0)
            nextMove = MOVES.UP;
        else if (deltaR < 0)
            nextMove = MOVES.DOWN;

        if (deltaC > 0)
            nextMove = MOVES.RIGHT;
        else if (deltaC < 0)
            nextMove = MOVES.LEFT;

        PrintMove(nextMove);
    }
    
    static void PrintMove(MOVES m)
    {
        switch (m)
        {
            case MOVES.NONE:
                break;
            case MOVES.LEFT:
                Console.WriteLine("LEFT");
                break;
            case MOVES.RIGHT:
                Console.WriteLine("RIGHT");
                break;
            case MOVES.UP:
                Console.WriteLine("UP");
                break;
            case MOVES.DOWN:
                Console.WriteLine("DOWN");
                break;
            default:
                break;
        }
    }

    static void Main(String[] args)
    {
        int n;

        n = int.Parse(Console.ReadLine());
        String pos;
        pos = Console.ReadLine();
        String[] position = pos.Split(' ');
        int[] int_pos = new int[2];
        int_pos[0] = Convert.ToInt32(position[0]);
        int_pos[1] = Convert.ToInt32(position[1]);
        String[] grid = new String[n];
        for (int i = 0; i < n; i++)
        {
            grid[i] = Console.ReadLine();
        }

        nextMove(n, int_pos[0], int_pos[1], grid);

    }
}