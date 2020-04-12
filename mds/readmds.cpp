#include <mdsobjects.h>
#include <cstdlib>
#include <iostream>
#include <string>
inline char* s2c(const std::string & s){
    return const_cast<char*>(s.c_str());
}
int main(){
    MDSplus::Connection *conn;
try{
    MDSplus::Connection *con= new MDSplus::Connection(s2c("202.127.204.12"));
    conn=con;
    conn->openTree(s2c("pcs_east"),81561);
}
  catch(MDSplus::MdsException *exc){
        std::cerr<<"Error "<<exc->what()<<std::endl;
    }

    //MDSplus::Data *data=conn->get("SIZE(\\pcrl01)");
    //int size = data->getInt();

    int size;
    MDSplus::Data *data=conn->get("\\pcrl01");
    MDSplus::Data *timebase=conn->get("DIM_OF(\\pcrl01)");

    float* databuf=data->getFloatArray(&size);
    float* timebuf=timebase->getFloatArray(&size);

    deleteData(data);
    deleteData(timebase);
    conn->closeTree(s2c("pcs_east"),81561);

    std::cout<<"size:"<<size<<std::endl;
    for(int i=size-100;i!=size;++i){
            std::cout<<databuf[i]<<":"<<timebuf[i]<<std::endl;
        }

    delete databuf;
    delete timebuf;

return 0;
}

