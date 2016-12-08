using System;

namespace HRMilitaryTime
{
	class MainClass
	{



		public static void Main(string[] args)
		{
			string time = Console.ReadLine();

			string[] arr_temp = time.Split(':');

			// Extract AM/PM indicator
			string indicator = arr_temp[2].Substring(arr_temp[2].Length - 2, 2);
			arr_temp[2] = arr_temp[2].Substring(0, 2);

			// Convert to int array
			int[] arr = Array.ConvertAll(arr_temp, Int32.Parse);
			if (indicator == "PM" && arr[0] != 12)
			{
				arr[0] += 12;
			}
			else if (indicator == "AM" && arr[0] == 12)
			{
				arr[0] = 0;	
			}



			Console.WriteLine("{0:D2}:{1:D2}:{2:D2}", arr[0], arr[1], arr[2]);


		}
	}
}
