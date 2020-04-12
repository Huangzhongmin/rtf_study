# rtf_study

## ArraySample
+ 不可以使用init族函数， mvn install时报错：
见err.note
> init族需要T实现<< >> 运算符？
+ 运行时错误
```
Working directory: "/home/codac-dev/hzm/apptest/sampleunit/xml"
Loaded plugin: console
Loaded plugin: console_logger
Loaded plugin: file
Loaded plugin: gen_sample
rtflocal: symbol lookup error: /home/codac-dev/hzm/apptest/sampleunit/target/main/c++/lib/librtf_gen_sample_plugin.so.0.0.0: undefined symbol: _ZN3rtf5block25registerPrintArrayFactoryEPNS_14FactoryManagerE
```
