#define statusOK(status) ((status) & 1)
#include <mdslib.h>
#include <mdsshr.h>

static int getSize(char* sigName)
{
    int dtype_long=DTYPE_LONG;
    int retSize;
    int lenDescr;
    int null=0;
    int status;
    char expression[1024];

    sprintf(expression,"SIZE(%s)",sigName);
    lenDescr=descr(&dtype_long,&retSize,&null);
    status=MdsValue(expression,&lenDescr,&null,0);

    if(!statusOK(status)){
        fprintf(stderr,"Error getting size of %s.\n",sigName);
        return -1;
    }
    return retSize;
}

int main(){
    int size=-1;
    int shot=81561;
    MdsConnect("202.127.204.12");
    MdsOpen("pcs_east",&shot);
    size=getSize("\\pcrl01");
    printf("%d",size);
}
