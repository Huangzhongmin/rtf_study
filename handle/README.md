# ASIPP handle example #

FileWriter is an example of the RTF FunctionBlock how to create and open handle once.  
In this example we create a handle to a file which is opened in constructor and closed in the destructor.

Copy `librtf_file_handle_plugin.so` to rtf plugin folder or build it from source.

Run
```bash
./rtflocal n1 p1 <PATH_TO>/rtf/examples/handle/config/service_configuration.xml <PATH_TO>/rtf/examples/handle/config/application_configuration.xml
```

then type any number in console and press Enter.  
Number will be written to into file specified in `configure/application-1.xml` inside "FileOutput" FunctionBlock.  
```xml
<FunctionBlock Name="FileOutput" Type="FileWriter<int64>">
    <Parameter Name="FilePath" Value="/tmp/current_data.log"/>
    <InputPort Name="In" Signal="reader::a"/>
</FunctionBlock>
```

