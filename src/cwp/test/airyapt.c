#include "cwp.h"

#define NMAX 1000
float aip[NMAX];

main()
{
	int nx,i;
	float xmin,xmax,x,dx;

	while(1) {
		/*
		printf("Enter nx xmin xmax: \n");
		*/
		scanf("%d %f %f",&nx,&xmin,&xmax);

		for (i=0,x=xmin,dx=(xmax-xmin)/(nx-1); i<nx; i++,x+=dx)
			aip[i] = airyap(x);
		/*
		pp1d(stdout,"",nx,0,aip);
		*/
		fwrite(aip,sizeof(float),nx,stdout);
		fflush(stdout);
		break;
	}
}
