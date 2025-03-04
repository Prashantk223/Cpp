cd C:\Projects\LearnCpp\Cpp\mySTL
cl.exe /c /EHsc /I C:\GitHub\RTR-6\MyProjects\02-OpenGL\02-OpenGL\03-GLInfo commonAlgos.cpp  mystring.cpp Test.cpp

link.exe Test.obj commonAlgos.obj mystring.obj
Test.exe
