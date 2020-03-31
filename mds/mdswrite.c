#include <stdio.h>
#include <math.h>
#include <string.h>
#include <mdslib.h>
#include <mdsshr.h>


#define statusOk(status) ((status) & 1)


int main()
{
int dtypeFloat = DTYPE_FLOAT;
int null = 0;
int status;
int socket;
float data[1000];
float timebase[1000];
int dataDesc;
int timeDesc;
int shot = 1;
int len;
int i;

socket = MdsConnect("127.0.0.1:8000");
if ( socket == -1 )
{
fprintf(stderr,"Error connecting to mdsip server.\n");
return -1;
}

status = MdsOpen("my_tree", &shot);
if ( !statusOk(status) )
{
fprintf(stderr,"Error opening tree for shot %d: %s.\n",shot,
MdsGetMsg(status));
return -1;
}

for(i = 0; i < 1000; i++)
{
data[i] = sin(i / 300.) * cos(i / 20.);
timebase[i] = i/1000.; /*Build a signal which lasts 1 sec */
}

len = 1000; /* 1000 samples */
dataDesc = descr(&dtypeFloat, data, &len, &null);

timeDesc = descr(&dtypeFloat, timebase, &len, &null);

status = MdsPut("sig1", "BUILD_SIGNAL($1,,$2)", &dataDesc, &timeDesc,
&null);
if ( !statusOk(status) )
{
fprintf(stderr,"Error writing signal: %s\n", MdsGetMsg(status));
return -1;
}

status = MdsClose("my_tree", &shot);
if ( !statusOk(status) )
{
fprintf(stderr,"Error closing tree for shot %d: %s.\n",shot,
MdsGetMsg(status));
return -1;
}
return 0;
}
