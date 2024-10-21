/*
xii-x input window id.
prints the internal X11 window id
for the window that works as an input.
*/

#include<X11/Xlib.h>
#include<unistd.h>
#include<stdio.h>

int main(){
Display* dpl;
Window ifoc;
int revto;

dpl=XOpenDisplay(0);
if(!dpl){
	write(2,"xip: can't open a display.\n",27);
	return 1;
}

XGetInputFocus(dpl,&ifoc,&revto);

dprintf(1,"%lu\n",ifoc);

XCloseDisplay(dpl);
return 0;
}
