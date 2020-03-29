# Real Time Framework Plugin Library

The Plugin Library has default implementations of RTF plugins. Plugins are blocks packed into libraries and dynamically loaded into RTF application.

| Plugin Name | Type | Description |
|-------------|------|-------------|
| Console  | FunctionBlock | Console implements function blocks for reading/writing from/to standard input/output. |
| Console Logger | Service | Console logger is using RTF logging mechanism to write onto standard output. |
| System Logger | Service | System logger is using CODAC's m-log-lib to provide logging for RTF. |
| File | FunctionBlock | File plugin provides function blocks for writing/reading to/from files. |
| Math | FunctionBlock | Plugin implements basic mathematics operations |
| SDN  | FunctionBlock | CODAC's SDN subscriber and publisher implementation in RTF |

## Building

For more information about compiling and building refer to the [Real Time Framework](../../README.md)

## License

Copyright (c) 2017-2019, ITER Organization<br/>
Route de Vinon-sur-Verdon, 13115, St. Paul-lez-Durance, France<br/>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistribution and use are granted solely to the members of the ITER
  Agreement (the People's Republic of China, the European Atomic Energy
  Community, the Republic of India, Japan, the Republic of Korea,
  the Russian Federation, and the United States of America).
  Organizations, bodies or individuals belonging to the parties other
  than that in the list above shall seek specific written permission
  from the ITER Organization before redistribution or use of this software.

* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

* Neither the name of the ITER Organization nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE ITER ORGANIZATION OR ITS CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.