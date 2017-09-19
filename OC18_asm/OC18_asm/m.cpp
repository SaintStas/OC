
#include <iostream>
int  main()
{
	int x = 9, y = 6, z = 3;
		_asm
		{
			mov eax, x
			mov edx, y
			mov ebx, z
		cikl :
			cmp eax, edx
				je the_end
				jl metka
				sub eax, edx
				jmp cikl
			metka :
			sub edx, eax
				jmp cikl
			the_end :

			;ÂÒÎĞÎÉĞÀÇ

		cikl2 :
			cmp eax, ebx
			je the_end2
			jl metka2
			sub eax, ebx
			jmp cikl2
		metka2 :
			 sub ebx, eax
				 jmp cikl2
			 the_end2 :

			mov x, eax
		}
	printf("%d\n", x);
	system("pause");
	return 0;
}
