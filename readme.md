# PROJECTS CREATED IN C++


### COMPILE AND EXECUTE CODE IN C++
#### Compile code C++
`$ g++ main.cpp -o run` 
#### Execute code C++
`$ ./run.exe`


### COMPILE AND EXECUTE CODE IN FLEX AND BISON
#### Generate `.tab.c` and `.tab.h`
`$ bison -d parser.y`                                               <!-- parser.y is name the file created -->
#### Generate `.yy.c`
`$ flex lexer.l`                                                    <!-- lexer.y is name the file created -->
#### Compile the generated files and create the executable 
`$ gcc -o calculadora lex.yy.c parser.tab.c -lm`
#### Execute
`$ ./calculadora`                                                   <!-- calculadora is name the generate excecutable -->

![Captura de pantalla 2024-05-24 232133](https://github.com/jmorales01/cpp/assets/91076395/f3d1a2f2-e71a-447b-97d6-831fd4d536c3)
