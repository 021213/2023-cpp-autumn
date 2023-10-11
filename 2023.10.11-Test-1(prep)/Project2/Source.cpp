#include<iostream>

typedef unsigned int uint;

int main(int argc, char* argv[])
{
	const int BITS = sizeof(uint) * 8;

	uint n = 1180960184; // 0b 0100 0110 0110 0100 0000 0101 1011 1000
	                     // 0b 0011 1111 1111 1111 1111 1111 1111 0000
	                     // 0b 0111 1001 1001 1011 1111 1010 0100 1000

	{
		/*
				 13 = 0b1101
			13 >> 1 = 0b0110 = 6
			13 >> 2 = 0b0011 = 3
			13 >> 3 = 0b0001 = 1
			13 << 1 = 0b1010
			13 << 2 = 0b0100
			13 & 7  = 0b1101 & 0b0111
			          0b0111
			          0b0101 = 5
			13 & 1  = 0b1101
			          0b0001
			          0b0001
		*/
		std::cout << "0b ";
		for (int i = BITS - 1; i >= 0; --i)
		{
			std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
		}
		std::cout << std::endl;
	}

	{
		int sumbits = 0;
		for (int i = 0; i < BITS; ++i)
		{
			sumbits += (n >> i) & 1;
		}
		std::cout << sumbits << std::endl;
	}

	{
		if (n == 0)
		{
			n = ~n;
		}
		else
		{
			int start = BITS - 1;
			int end = 0;
			while ((n >> start & 1) == 0)
			{
				start--;
			}
			while ((n >> end & 1) == 0)
			{
				end++;
			}
			std::cout << start << " " << end << std::endl;
			
			start--; //start = 29
			end++;   //end   = 4
			uint mask = 0;						//0b 0000 0000 0000 0000 0000 0000 0000 0000
			//std::cout << mask << std::endl;
			mask = ~mask;						//0b 1111 1111 1111 1111 1111 1111 1111 1111
			//std::cout << mask << std::endl;
			mask = (mask >> (start - end + 1));	//0b 0000 0000 0000 0000 0000 0000 0011 1111
			//std::cout << mask << std::endl;
			mask = ~mask;						//0b 1111 1111 1111 1111 1111 1111 1100 0000
			//std::cout << mask << std::endl;
			mask = (mask >> (BITS - start - 1));//0b 0011 1111 1111 1111 1111 1111 1111 0000
			//std::cout << mask << std::endl;
			n = n ^ mask;

			std::cout << "MASK = " << mask << std::endl;

			mask = 0;
			for (int i = end; i <= start; ++i)
			{
				mask = mask | (1 << i);
			}
			std::cout << "MASK = " << mask << std::endl;

			{
				std::cout << "0b ";
				for (int i = BITS - 1; i >= 0; --i)
				{
					std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
				}
				std::cout << std::endl;
			}
			// 0b 0100 0110 0110 0100 0000 0101 1011 1000
			// 0b 0011 1111 1111 1111 1111 1111 1111 0000
			// 0b 0111 1001 1001 1011 1111 1010 0100 1000
		}
	}

	{				   //   00000 0111 1110 0000
		uint a = 4561; // 0b 0001 0001 1101 0001
		uint b = 8946; // 0b 0010 0010 1111 0010
		uint c = 0;    // 0b 0011 0100 1100 0011

		bool up = 0;
		for (int i = 0; i < BITS; ++i)
		{
			bool bitA = ((a >> i) & 1);
			bool bitB = ((b >> i) & 1);
			bool current = bitA ^ bitB ^ up;
			// 0 0 0 -> 0
			// 0 0 1 -> 1
			// 0 1 1 -> 0
			// 1 1 1 -> 1
			up = (bitA & bitB) | (bitA & up) | (bitB & up);
			//std::cout << (int)bitA << " " << (int)bitB << "->" << current << " " << up << std::endl;
			c = c | ((int)current << i);
		}
		std::cout << a << " + " << b << " = " << c << std::endl;
	}

	return EXIT_SUCCESS;
}