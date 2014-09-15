October 26, 1994
	/*=============================================================
	=  (C)opyright 1994 Tim Triemstra and                         =
	=  (C)opyright 1994 Empath Software, All Rights are Reserved  =
	=                                                             =
	=  The author can be contacted at:                            =
	=  Internet: empath@umcc.umich.edu                            =
	=============================================================*/


INTRODUCTION:
_____________

    Welp, first off, here's what the heck this program does!  It is
    a very simple program (as the source code will attest to).
    which simply takes ANY type of file (especially binary or image
    files) and converts it into a list of numbers for linking into
    your programs.  The data can be output in decimal or
    hexidecimal formats and is formatted to look pretty nice.

    My main purpose for writing this program is for easy adding of
    bitmaps and palette information into graphics programs.  This
    is before I write my graphics library kernel, but I still want to
    experiment with graphics bitmaps - reading from .BMPs stinks in my
    opinion.  This is also good for data that you may not want users to
    realize IS data.  This is done by having your data right into the
    program, not in an external file for anyone to edit.

WHAT IS INCLUDED:
_________________

    BINCON.EXE and BINCON2.EXE are the two compiled versions of
    the program that are included.  They are DOS 32bit virtual
    memory and OS/2 32bit versions, respectively.  Both should work
    with an unlimmited file size.  However, many compilers become
    unmanageable if you try to include too much data so be careful.

    The source code, BINCON.C, is also included.  It includes some of
    the vital information included in this file at the top in comments.
    More importantly, you can modify the way the hex or dec is printed
    in the little loop at the bottom of the code.  This is so that you
    can change the format of the output to your liking.


HOW TO USE IT:
______________

    Here's the command line:
    BINCON <filename> <D|H> (start) (end) >output.dat

    FILENAME is obviously the input file.  It is the file you'd like
    to convert to raw data.  The D or H represent (D)ecimal or (H)ex
    output.  Both of the previous commands are required.  The (start)
    is the first byte to start dumping from, (end) is where to stop.
    You can enter a start without and end and the file will simply
    be processed to the end.  No start opion indicates to do the
    entire file.

    The >output.dat is just a pipe of output into a desired file.  I
    decided to do it this way to allow yu to run the program through
    the screen.  I do this alot to check through palettes.  It is also
    good because you can print it out from the command line and such.
    What the hey, DOS and UNIX created piping for a reason, I'm just
    using it...  Modify it if you'd like something else.  Skip the
    parameters and you'll get a parameter list.

EXTRA STUFF: -> Included in the source code header
__________________________________________________


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

___

I sure hope this code helps SOMEONE besides myself, although the people
that may find it useful may never see it - unless you distribute the
program.  PLEASE - distribute this file to your local BBS systems and
FTP sites where people look for programming tools.  You could be helping
the guy that figures out how to do a FAST fractal on a 8088 or some other
gound breaking research =)

Tim.

