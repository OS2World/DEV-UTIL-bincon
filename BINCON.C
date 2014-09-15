	/*=============================================================
	=  (C)opyright 1994 Tim Triemstra and                         =
	=  (C)opyright 1994 Empath Software, All Rights are Reserved  =
	=                                                             =
	=  The author can be contacted at:                            =
	=  Internet: empath@umcc.umich.edu                            =
	=============================================================*/

/*
	This file is probably pretty ugly to alot of you "professional
	programmers" (or anybody else actually.)  However, since I am
	completely self-taught there are bound to be areas where I can
	improve - just ask my professors.

    This code should, however, compile just fine for pretty much
    any operating system.  I haven't tested it with a 16bit compile
    but it should work (with somewhat limitted usefulness, look at
    the comments for reasons why.)

	I included the source because there is probably a situation
	that someone out there might like some more functionality.  I can't
	really think of anything off the top of my head, though.

	If this code influences you to write an application along this
	line, please release it as shareware/freeware.  The world needs
	good programs and if we all have to spend our precious minutes
	writing small tools like this then the real programs will take
	alot longer.  The only thing I ask is that if you use it constantly
	then distribute it.  After all, you're not the only wierd one out
	there that may like	this program.

    You can mail me anything you think I may want/need (I always
    accept money :) at the following addresses:

	Tim Triemstra
	Empath Software
	P.O.Box 40901
	Redford, MI 48240

	I can be (and prefer to be) contacted at:
	Internet:  empath@umcc.umich.edu
	UUCPmail:  umcc!roofus!empath   (I think this still works :)
*/

#ifdef  __I86__
#if     __I86__     > 2     /* Symantec uses I86 instead of __386__ */
#define __386__     1       /* Make it like Watcom */
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <io.h>

void main(int argc, char *argv[])
{
	FILE *f;
	unsigned char   *raw;
	unsigned int    length;
	unsigned int    count;
	short           count2;
	int             start, end, temp;

	if(argc < 3)
	{
		#ifdef __386__              /* Make clear if in 32bit mode */
			printf(">32bit version<\n");
		#else
			printf(">16bit version<\n");
		#endif

		/* Instructions when no paramters are given */
		printf("BINCON <file> <type D:H> <startByte> <endByte>\n");
		printf("type D=Decimal, H=Hex, ");
		printf("<start> defaults to 0, <end> defaults to the eof\n");
		printf("IE: bincon bitmap.bmp D 54 822 >bitmap.dat\n");
		printf("Would turn a 16x16 24bit Windows BMP into a raw data");
		printf("file (3 bytes per pixel)\n");
		exit(0);
	}

	/* Take care of the file information */
	f = fopen(argv[1],"rb");
	if(!f)
	{
		printf("Could not open the requested file \"%s\"\n",argv[1]);
		exit(255);
	}

	/* Determine how much memory is needed */
	/* +NOTE+   This program loads the entire file into memory
				before processing so 16bit compiles won't run very
				well.  This is done to save speed, the program can
				easily be modified to convert as it reads, having
				almost no memory overhead at all.  If you are still
				running a 16bit computer this is advised. */

	start = 0; end = filelength(fileno(f));
	if(argc > 3)
    {
	    start = atoi(argv[3]);
    }
	if(argc > 4)
	{
		temp = atoi(argv[4]);
		if(temp < end) end = temp;
	}
	if(start < end) length = end - start + 1;
	else
	{
	    printf("** You cannot start beyond the end of the file\n");
	    exit(255);
	}

	#ifdef __386__
		raw = (unsigned char*)malloc(length);
	#else
		if(length > 64000)
		{
			printf("** 16bit version handles up to 64000 bytes only");
			exit(255);
		}
		raw = farmalloc(length);
	#endif

    fseek(f, start, SEEK_SET);
	fread(raw,sizeof(char),length,f);
	fclose(f);

	printf("\n{\n    ");

	/* This will simply output to the screen, good for >filename work */
	if(argv[2][0] == 'd') argv[2][0] = 'D';
	if(argv[2][0] == 'h') argv[2][0] = 'H';
	count2 = -1;

	switch(argv[2][0])
	{
		/* Slightly different output formatting for Decimal and Hex */
        /* Hexidecimal */
		case 'H' :  for(count = 0; count < length - 1; count++)
					{
						if(++count2 != 0) printf(",");
						if(count2 == 3 || count2 == 6 ||
						    count2 == 9) printf("  ");
						if(count2 > 11)
						{
							count2 = 0;
							printf("\n    ");
						}
                        printf("%#4x",raw[count]);
					}
					break;
        /* Decimal */
		case 'D' :  for(count = 0; count < length - 1; count++)
					{
						if(++count2 != 0) printf(",");
						if(count2 == 3 || count2 == 6 ||
						    count2 == 9) printf("  ");
						if(count2 > 11)
						{
							count2 = 0;
							printf("\n    ");
						}
						printf(" %3d",raw[count]);
					}
					break;
		default  :  {
		                printf("** You must specify (D)ec or (H)ex\n");
    					exit(0);
    			    }
	}
	printf("\n};\n");       /* Closing brackets and we're done! */
	exit(0);
}

