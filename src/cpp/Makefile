ctrlnmap: ctrlnmap.cpp;
	g++ -o ctrlnmap ctrlnmap.cpp
inline-static:
	g++ -c inline_foo.cc inline_bar.cc
	ar rcs inline.a inline_foo.o inline_bar.o
inline-shared:
	g++ -shared -fpic -o inline.so inline_foo.cc inline_bar.cc
inline:
	g++ -o inline inline_foo.cc inline_bar.cc inline_main.cc
