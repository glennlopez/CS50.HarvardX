NOTE: Answers are given at the end.

Go ahead and pull up the URLs to which BITMAPFILEHEADER and BITMAPINFOHEADER are attributed, per the comments in bmp.h.

Rather than hold your hand further on a stroll through copy.c, we’re instead going to ask you some questions and let you teach yourself how the code therein works. As always, man is your friend, and so, now, is Microsoft Developer Network (aka MSDN). If not sure on first glance how to answer some question, do some quick research and figure it out! You might want to turn to https://reference.cs50.net/stdio as well.

In questions.txt, answer each of the following questions in a sentence or more.

1) What’s stdint.h?

2) What’s the point of using uint8_t, uint32_t, int32_t, and uint16_t in a program?

3) How many bytes is a BYTE, a DWORD, a LONG, and a WORD, respectively?

4) What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

5) What’s the difference between bfSize and biSize?

6) What does it mean if biHeight is negative?

7) What field in BITMAPINFOHEADER specifies the BMP’s color depth (i.e., bits per pixel)?

8) Why might fopen return NULL in lines 24 and 32 of copy.c?

9) Why is the third argument to fread always 1 in our code?

10) What value does line 65 of copy.c assign to padding if bi.biWidth is 3?

11) What does fseek do?

12) What is SEEK_CUR?




A N S W E R S
(uncorrected, used only as a guideline for self directed teaching)
1.  <stdint> Specified by MSDN provides typedefs and macros for fixed-with integral types. It helps ensure code portability across compilers.

2.  Using uint8_t over unsigned char in C documents a programmers intent. It shows you will be storing small numbers rather than chars

3.  BYTE    uint8_t     unsigned    (8bits or 1byte)
    DWORD   uint32_t    unsigned    (32bits or 4bytes)
    LONG    int32_t     signed      (32bits or 4bytes)
    WORD    uint16_t    unsigned    (16bits or 2bytes)

4.  DEC: 255        216         255
    BIN: 1111 1111  1101 1000   1111 1111
    HEX: 0xFF       0xD8        0xFF

5.  bfSize is the size of the whole bmp file, which includes the headerfiles
    bfSize = biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
    bfSize = biSizeImage + 54

    biSize is the size of the BITMAPINFOHEADER header file. biSize is constant and it equals 40 bytes

6.  biHeight specifies the height of the bitmap in pixels, if biHeight is negative, this means the bitmap is a
    top-down DIB with the orgine at the upper left corner.

7.  biBitCount specifies the number of bits per pixel.

8.  If the file specified in the cmd-line parameters does not exist, it will return a null.

9.  fread( <buffer>, <size>, <qty>, <filepointer>)
    example: int arr[10]
    fread(arr, sizeof(int), 10, ptr)

    The fread() <qty> parameter is always 1 becuase there is only 1 BITMAPFILEHEADER/BITMAPINFOHEADER struct element

10.
    = (4 - (3 * 3) % 4) % 4
    = (4 - 9 % 4) % 4
    = (4 - 1) % 4
    = 3 % 4
    = 3

11. int fseek(FILE *pointer, long offset, int position);
    pointer: pointer to a FILE object
    offset: number of bytes to offset from position
    possition: postion from where offset is added

    fseek() is used to move file pointer associated with a given file to a specific position.


12. SEEK_CUR denotes file pointers current position

