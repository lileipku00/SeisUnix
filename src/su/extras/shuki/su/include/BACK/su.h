/* su.h - include file for SU
 *
 * declarations for:
 *	typedef struct sutrace {} Sutrace - the trace identification header
 *	typedef struct bhed {} Bhed - binary header
 *	
 */ 

#ifndef INCLUDE_SEGY_H
#define INCLUDE_SEGY_H

#define NTRHB	(sizeof(Sutrace)-sizeof(float*))


typedef struct sutrace {	/* SU trace */

	int tracl;	/* trace sequence number within line */

	int tracr;	/* trace sequence number within reel */

	int fldr;	/* field record number */

/*	int tracf;	/* trace number within field record */

/*	int ep;		/* energy source point number */

	int cdp;	/* CDP ensemble number */

	int cdpt;	/* trace number within CDP ensemble */

	int trid;	/* trace identification code:
				1 = seismic data
				2 = dead
				3 = dummy
				4 = time break
				5 = uphole
				6 = sweep
				7 = timing
				8 = water break
				SEGY: 9---, N = optional use (N = 32,767)
				From here on these are CWP id flags:
				9 = autocorrelation
				10 = Fourier transformed - no packing
				11 = Fourier transformed - unpacked Nyquist
				12 = Fourier transformed - packed Nyquist
				13 = Complex signal in the time domain
				101 = 1 byte packing (chars)
				102 = 2 byte packing (short ints)
			*/
	int nvs;	/* number of vertically summed traces (see vscode
			   in Bhed structure) */

	int nhs;	/* number of horizontally summed traces (see vscode
			   in Bhed structure) */
/*	int duse;	/* data use:
				1 = production
				2 = test */

	int offset;	/* distance from source point to receiver
			   group (negative if opposite to direction
			   in which the line was shot) */

/*	int gelev;	/* receiver group elevation from sea level
			   (above sea level is positive) */

/*	int selev;	/* source elevation from sea level
			   (above sea level is positive) */

/*	int sdepth;	/* source depth (positive) */

/*	int gdel;	/* datum elevation at receiver group */

/*	int sdel;	/* datum elevation at source */

/*	int swdep;	/* water depth at source */

/*	int gwdep;	/* water depth at receiver group */

/*	int scalel;	/* scale factor for previous 7 entries
			   with value plus or minus 10 to the
			   power 0, 1, 2, 3, or 4 (if positive,
			   multiply, if negative divide) */
/*	int scalco;	/* scale factor for next 4 entries
			   with value plus or minus 10 to the
			   power 0, 1, 2, 3, or 4 (if positive,
			   multiply, if negative divide) */

	int sx;	/* X source coordinate */

	int sy;	/* Y source coordinate */

	int gx;	/* X group coordinate */

	int gy;	/* Y source coordinate */

/*	int counit;	/* coordinate units code:
				for previoius four entries
				1 = length (meters or feet)
				2 = seconds of arc (in this case, the
				X values are longitude and the Y values
				are latitude, a positive value designates
				the number of seconds east of Greenwich
				or north of the equator */

/*	int wevel;	/* weathering velocity */

/*	int sweves;	/* subweathering velocity */

/*	int sut;	/* uphole time at source */

/*	int gut;	/* uphole time at receiver group */

	int sstat;	/* source static correction */

	int gstat;	/* group static correction */

	int tstat;	/* total static applied */

/*	int laga;	/* lag time A, time in ms between end of 240-
			   byte trace identification header and time
			   break, positive if time break occurs after
			   end of header, time break is defined as
			   the initiation pulse which maybe recorded
			   on an auxiliary trace or as otherwise
			   specified by the recording system */
/*	int lagb;	/* lag time B, time in ms between the time break
			   and the initiation time of the energy source,
			   may be positive or negative */

/*	int delrt;	/* delay recording time, time in ms between
			   initiation time of energy source and time
			   when recording of data samples begins
			   (for deep water work if recording does not
			   start at sero time) */

	int muts;	/* mute time--start */

	int mute;	/* mute time--end */

	int ns;	/* number of samples in this trace */

	int dt;	/* sample interval; in micro-seconds */

	int gain;	/* gain type of field instruments code:
				1 = fixed
				2 = binary
				3 = floating point
				4 ---- N = optional use */

/*	int igc;	/* instrument gain constant */

/*	int igi;	/* instrument early or initial gain */

/*	int corr;	/* correlated:
				1 = no
				2 = yes */

/*	int sfs;	/* sweep frequency at start */

/*	int sfe;	/* sweep frequency at end */

/*	int slen;	/* sweep length in ms */

/*	int styp;	/* sweep type code:
				1 = linear
				2 = cos-squared
				3 = other */

/*	int stas;	/* sweep trace length at start in ms */

/*	int stae;	/* sweep trace length at end in ms */

/*	int tatyp;	/* taper type: 1=linear, 2=cos^2, 3=other */

/*	int afilf;	/* alias filter frequency if used */

/*	int afils;	/* alias filter slope */

/*	int nofilf;	/* notch filter frequency if used */

/*	int nofils;	/* notch filter slope */

/*	int lcf;	/* low cut frequency if used */

/*	int hcf;	/* high cut frequncy if used */

/*	int lcs;	/* low cut slope */

/*	int hcs;	/* high cut slope */

/*	int year;	/* year data recorded */

/*	int day;	/* day of year */

/*	int hour;	/* hour of day (24 hour clock) */

/*	int minute;	/* minute of hour */

/*	int sec;	/* second of minute */

/*	int timbas;	/* time basis code:
				1 = local
				2 = GMT
				3 = other */

/*	int trwf;	/* trace weighting factor, defined as 1/2^N
			   volts for the least sigificant bit */

/*	int grnors;	/* geophone group number of roll switch
			   position one */

/*	int grnofr;	/* geophone group number of trace one within
			   original field record */

/*	int grnlof;	/* geophone group number of last trace within
			   original field record */

/*	int gaps;	/* gap size (total number of groups dropped) */

/*	int otrav;	/* overtravel taper code:
				1 = down (or behind)
				2 = up (or ahead) */

	/* local assignments */
/*	int s_sta;

/*	int g_sta;

/*	int h_sta;

/*	int y_sta;

/*	int srstat;	/* residual shot statics */

/*	int grstat;	/* residual geophone statics */

	float ungpow;	/* negative of power used for dynamic
			   range compression */

	float unscale;	/* reciprocal of scaling factor to normalize
			   range */

	int ntr;	/* number of traces in the data set */

	int mark;	/* mark selected traces */

	float *data;

} Sutrace;


typedef struct subhed {	/* Bhed - binary header */

	int jobid;	/* job identification number */

	int lino;	/* line number (only one line per reel) */

	int reno;	/* reel number */

	int ntrpr;	/* number of data traces per record */

        int nart;	/* number of auxiliary traces per record */

	int dt;		/* sample interval in micro secs for this reel */

	int dto;	/* same for original field recording */

	int ns;		/* number of samples per trace for this reel */

	int nso;	/* same for original field recording */

	int format;	/* data sample format code:
				1 = floating point (4 bytes)
				2 = fixed point (4 bytes)
				3 = fixed point (2 bytes)
				4 = fixed point w/gain code (4 bytes) */

	int fold;	/* CDP fold expected per CDP ensemble */

	int tsort;	/* trace sorting code: 
				1 = as recorded (no sorting)
				2 = CDP ensemble
				3 = single fold continuous profile
				4 = horizontally stacked */

	int vscode;	/* vertical sum code:
				1 = no sum
				2 = two sum ...
				N = N sum (N = 32,767) */

	int hsfs;	/* sweep frequency at start */

	int hsfe;	/* sweep frequency at end */

	int hslen;	/* sweep length (ms) */

	int hstyp;	/* sweep type code:
				1 = linear
				2 = parabolic
				3 = exponential
				4 = other */

	int schn;	/* trace number of sweep channel */

	int hstas;	/* sweep trace taper length at start if
			   tapered (the taper starts at zero time
			   and is effective for this length) */

	int hstae;	/* sweep trace taper length at end (the ending
			   taper starts at sweep length minus the taper
			   length at end) */

	int htatyp;	/* sweep trace taper type code:
				1 = linear
				2 = cos-squared
				3 = other */

	int hcorr;	/* correlated data traces code:
				1 = no
				2 = yes */
	int bgrcv;	/* binary gain recovered code:
				1 = yes
				2 = no */

	int rcvm;	/* amplitude recovery method code:
				1 = none
				2 = spherical divergence
				3 = AGC
				4 = other */

	int mfeet;	/* measurement system code:
				1 = meters
				2 = feet */

	int polyt;	/* impulse signal polarity code:
				1 = increase in pressure or upward
				    geophone case movement gives
				    negative number on tape
				2 = increase in pressure or upward
				    geophone case movement gives
				    positive number on tape */

	int vpol;	/* vibratory polarity code:
				code	seismic signal lags pilot by
				1	337.5 to  22.5 degrees
				2	 22.5 to  67.5 degrees
				3	 67.5 to 112.5 degrees
				4	112.5 to 157.5 degrees
				5	157.5 to 202.5 degrees
				6	202.5 to 247.5 degrees
				7	247.5 to 292.5 degrees
				8	293.5 to 337.5 degrees */

	/* SU extension */
	char name[16];
	char area[16];
	char client[16];
	int esize;	/* Element size */

} Subhed;

#define		TRUE		1
#define		FALSE		0
#define		YES		1
#define		NO		0
#define		STDIN		0
#define		STDOUT		1
#define		STDERR		2

#define SGN(x)		( (x) < 0 ? -1.0 : 1.0)
#define ABS(x)		( (x) < 0 ? -(x) : (x) )
#define	MAX(x,y)	( (x) > (y) ? (x) : (y) )
#define	MIN(x,y)	( (x) < (y) ? (x) : (y) )

#define MUSTIGETPAR(x,y) if(!igetpar(x,y)) err("need %s=",x)
#define MUSTFGETPAR(x,y) if(!fgetpar(x,y)) err("need %s=",x)
#define MUSTZGETPAR(x,y) if(!zgetpar(x,y)) err("need %s=",x)
#define MUSTHGETPAR(x,y) if(!hgetpar(x,y)) err("need %s=",x)
#define MUSTLGETPAR(x,y) if(!lgetpar(x,y)) err("need %s=",x)
#define MUSTSGETPAR(x,y) if(!sgetpar(x,y)) err("need %s=",x)

#define		LOWBYTE(w)	((w) & 0xFF)
#define 	HIGHBYTE(w)	LOWBYTE( (w) >>8)
#define		ISNEGCHAR(c)	((c) & 0x80)
#define		SIGNEXTEND(c)	(~0xFF | (int) (c))

typedef enum {false, true} bool;
typedef enum {UNKNOWN= -1,CLOSED,TTY,DISK,DIR,TAPE,PIPE,DEVNULL} filetype;

/* extern int errno; Masscomp fluke in <errno.h> */

void exit();

extern void syserr(), err(), warn(), selfdoc();
extern void puthdval(), gethdval(), gname();
extern void printfval(), fprintfval(), scanfval(), printftype();
extern void vsadd(), vsmul(), vsadd2(), vsmul2();
extern void vadd(), vsub(), vmul(), vdiv();
extern void vadd2(), vsub2(), vmul2(), vdiv2();
extern void vsqrt(), vabs();
extern void cvabs();
extern void dvsadd(), dvsmul(), dvsadd2(), dvsmul2();
extern void dvadd(), dvsub(), dvmul(), dvdiv();
extern void dvadd2(), dvsub2(), dvmul2(), dvdiv2();
extern void dvsqrt(), dvabs();
extern void ivsadd(), ivsmul(), ivsadd2(), ivsmul2();
extern void ivadd(), ivsub(), ivmul(), ivdiv();
extern void ivadd2(), ivsub2(), ivmul2(), ivdiv2();
extern void ivsqrt(), ivabs();
extern unsigned maxgetpar();
extern int syswarn(), getpar(), gettr(), puttr(), getindex();
extern int vtoi(), valcmp(), ivmax(), ivmin(), ivabsmx();
extern int ivsum(), ivl1(), ivl2(), ivprod();
extern long vtol();
extern float vtof(), vmax(), vmin(), vabsmx();
extern float vsum(), vl1(), vl2(), vprod();
extern double vtoz(), dvmax(), dvmin(), dvabsmax();
extern double dvsum(), dvl1(), dvl2(), dvprod();
extern char *getkey(), *hdtype();
extern filetype statfil();

typedef union {
	char		s[32];
	short		h;
	unsigned short	u;
	long		l;
	unsigned long	v;
	int		i;
	float		f;
	double		z;
} value;

typedef struct section {
	int n1,n2;
	value val;
	float o1,o2;
	float d1,d2;
	float *data;
} Section;

typedef union {
	char		*s;	/* Char pointer			*/
	short		*h;	/* Short int pointer		*/
	unsigned short	*u;	/* Unsigned short integer	*/
	long		*l;	/* Long int pointer 		*/
	unsigned long	*v;	/* Unsigned long integer 	*/
	int		*d;	/* Integer (whatever it is)	*/
	float		*f;	/* Float pointer 		*/
	double		*z;	/* Double pointer 		*/
} mixed;

#endif INCLUDE_SEGY_H
