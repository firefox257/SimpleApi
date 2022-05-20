using System;
using System.Linq;
using System.Collections.Generic;



namespace try1
{
	
	
	class Program
	{
		
		static long time()
		{
			return DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
		}
		static void Main(string[] args)
		{
			long t1, t2;
			Dictionary<int, int> map1 = new Dictionary<int, int>();
			t1 = time();
			for(int i = 0; i < 1000000; i++)
			{
				
				string str1 = "try" + i;
				//map1[i] = i % 256;
			}
			t2 = time();
			Console.WriteLine("time " + (t2- t1));
			
			/*
			 
			 Dictionary<int, int> map1 = new Dictionary<int, int>();
			 */
			
		}
		
	}
	
	
	
}
